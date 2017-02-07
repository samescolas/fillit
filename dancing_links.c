/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dancing_links.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 16:17:26 by sescolas          #+#    #+#             */
/*   Updated: 2017/02/06 18:21:17 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_col	*choose_col(t_col **grid)
{
	t_col	*tmp;
	t_col	*min;

	if (!*grid)
		return ((void *)0);
	tmp = *grid;
	min = tmp;
	while (tmp)
	{
		if (tmp->size < min->size)
			min = tmp;
		tmp = tmp->r;
	}
	return (min);
}

static int		add_to_solution(char **solution, t_link *link)
{
	t_link	*tmp;

	tmp = link;
	while (tmp->l)
		tmp = tmp->l;
	while (tmp)
	{
		if ((*solution)[(tmp->col)->id] == '\0')
			(*solution)[(tmp->col)->id] = tmp->id;
		else
			return (0);
		tmp = tmp->r;
	}
	return (1);
}

static void		remove_empty_cols(t_col **grid)
{
	t_col	*col;

	col = *grid;
	while (col)
	{
		if (col->size == 0)
			unlink_col(col, grid);
		col = col->r;
	}
}

int				solve(t_env *env, char **solution, int num_tets)
{
	t_col	*col;
	t_link	*link;

	if (!*(env->grid) || !num_tets)
		return (num_tets <= 0);
	remove_empty_cols(env->grid);
	if (!(col = choose_col(env->grid)))
		return (num_tets <= 0);
	link = col->d;
	if (!add_to_solution(solution, link))
		return (0);
	unlink_tet(link, env);
	if (solve(env, solution, num_tets - 1))
		return (1);
	relink_tet(link, env, *solution);
	unlink_row(link, env->unlinked_links);
	return (solve(env, solution, num_tets));
}
