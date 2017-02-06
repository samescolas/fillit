/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dancing_links.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 16:17:26 by sescolas          #+#    #+#             */
/*   Updated: 2017/02/05 17:59:50 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				list_len(t_col *list)
{
	int		len;
	t_col	*tmp;

	len = 0;
	tmp = list;
	while (tmp)
	{
		++len;
		tmp = tmp->r;
	}
	return (len);
}

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

static int		add_to_solution(char **solution, t_col *col)
{
	t_link	*tmp;

	if (!(col->size))
		return (0);
	tmp = col->d;
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

int		solve(t_env *env, char **solution, int num_tets)
{
	t_col	*col;

	if (!*(env->grid) || !num_tets)
		return (num_tets <= 0);
	if (!(col = choose_col(env->grid)))
		return (num_tets <= 0);
	if (!add_to_solution(solution, col))
	{
		unlink_col(col, env->grid);
		return (solve(env, solution, num_tets));
	}
	else
	{
		unlink_tet(col, env);
		return (solve(env, solution, num_tets - 1));
	}
}
