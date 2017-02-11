/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dancing_links.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 18:41:24 by sescolas          #+#    #+#             */
/*   Updated: 2017/02/11 13:34:05 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		update_solution(t_link *link, char **solution, int len, int add)
{
	int		i;
	t_link	*tmp;

	i = 0;
	if (add)
	{
		tmp = link;
		while (tmp->l)
			tmp = tmp->l;
		while (tmp)
		{
			(*solution)[(tmp->col)->id] = tmp->id;
			tmp = tmp->r;
		}
	}
	else
		while (i < len)
			if ((*solution)[i++] == link->id)
				(*solution)[i - 1] = '\0';
}

/*
t_col			*choose_col(t_col **grid)
{
	t_col	*tmp;
	t_col	*min;
	int		cols;

	if (!grid || !(*grid))
		return ((void *)0);
	tmp = *grid;
	cols = count_cols(grid);
	while (cols && tmp->size <= 0)
	{
		--cols;
		tmp = tmp->r;
	}
	if (!tmp)
		return ((void *)0);
	min = tmp;
	cols = count_cols(grid);
	while (cols)
	{
		if (tmp->size < min->size && tmp->size > 0)
			min = tmp;
		tmp = tmp->r;
		--cols;
	}
	return (min);
}
*/
t_col			*choose_col(t_col **grid)
{
	t_col	*col;
	t_col	*min;
	int		num_cols;

	col = *grid;
	min = col;
	num_cols = count_cols(grid);
	while (num_cols)
	{
		if (col->size <= 0)
		{
			col = col->r;
			--num_cols;
			continue ;
		}
		if (col->size == 1)
			return (col);
		if (col->size < min->size || min->size == 0)
			min = col;
		col = col->r;
		--num_cols;
	}
	return (min);
}


int				solve(t_env *env, char **solution, int unplaced_tets)
{
	t_col	*col;
	t_link	*link;

	if (!unplaced_tets || !env->grid || !*env->grid)
		return (unplaced_tets == 0);
	col = choose_col(env->grid);
	if (!col || col->size == 0)
		return (unplaced_tets == 0);
	link = col->d;
	unlink_row(link, env);
	unlink_tet(link, env);
	update_solution(link, solution, ft_exp(env->grid_size, 2), 1);
	if (solve(env, solution, unplaced_tets - 1))
		return (1);
	update_solution(link, solution, ft_exp(env->grid_size, 2), 0);
	undo_unlink(link, env, *solution);
	return (solve(env, solution, unplaced_tets));
}
