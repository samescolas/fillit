/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dancing_links.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 18:41:24 by sescolas          #+#    #+#             */
/*   Updated: 2017/02/25 17:15:47 by sescolas         ###   ########.fr       */
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

static t_link	*col_find(t_col *col, int id)
{
	t_link	*tmp;
	int		num_links;

	tmp = col->d;
	num_links = col->size;
	while (num_links)
	{
		if (tmp->id == id)
			return (tmp);
		tmp = tmp->d;
		--num_links;
	}
	return ((void *)0);
}

t_link			*choose_link(t_col **grid, int num_cols, int id)
{
	t_col	*col;
	t_link	*link;

	col = *grid;
	link = (void *)0;
	while (num_cols)
	{
		if (col->size > 0 && (link = col_find(col, id)) != (void *)0)
			return (link);
		col = col->r;
		--num_cols;
	}
	return (link);
}

int				solve(t_env *env, char **solution, int unplaced_tets)
{
	t_link	*link;

	if (!unplaced_tets || !env->grid || !*env->grid)
		return (!unplaced_tets);
	link = choose_link(\
			env->grid, env->num_cols, env->num_tets - unplaced_tets + 1);
	if (!link)
		return (!unplaced_tets);
	unlink_row(link, env);
	unlink_tet(link, env);
	env->num_cols -= 4;
	update_solution(link, solution, ft_exp(env->grid_size, 2), 1);
	if (solve(env, solution, unplaced_tets - 1))
		return (1);
	update_solution(link, solution, ft_exp(env->grid_size, 2), 0);
	undo_unlink(link, env, *solution);
	env->num_cols += 4;
	return (solve(env, solution, unplaced_tets));
}
