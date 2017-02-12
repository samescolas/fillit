/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dancing_links.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 18:41:24 by sescolas          #+#    #+#             */
/*   Updated: 2017/02/11 15:32:58 by sescolas         ###   ########.fr       */
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

t_col			*choose_col(t_col **grid, int num_cols)
{
	t_col	*col;

	col = *grid;
	while (num_cols)
	{
		if (col->size > 0)
			return (col);
		col = col->r;
		--num_cols;
	}
	return (col);
}


int				solve(t_env *env, char **solution, int unplaced_tets)
{
	t_col	*col;
	t_link	*link;

	if (!unplaced_tets || !env->grid || !*env->grid)
		return (!unplaced_tets);
	col = choose_col(env->grid, env->num_cols);
	if (!col || col->size == 0)
		return (!unplaced_tets);
	link = col->d;
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
