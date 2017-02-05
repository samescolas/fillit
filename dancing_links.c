/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dancing_links.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 16:17:26 by sescolas          #+#    #+#             */
/*   Updated: 2017/02/04 20:45:58 by sescolas         ###   ########.fr       */
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
	if (min->size == 0)
	{
		unlink_col(min, grid);
		choose_col(grid);
	}
	printf("choosing column %d\n", min->id);
	return (min);
}

static void		add_to_solution(char **solution, t_col *col)
{
	t_link	*tmp;

	if (!(col->size))
		return ;
	tmp = col->d;
	while (tmp->l)
		tmp = tmp->l;
	while (tmp)
	{
		(*solution)[(tmp->col)->id] = tmp->id;
		tmp = tmp->r;
	}
}

int		solve(t_env *env, char **solution)
{
	t_col	*col;

	if (!*(env->grid))
		return (1);
	if (!(col = choose_col(env->grid)))
		return (0);
	add_to_solution(solution, col);
	unlink_tet(col, env);
	return (solve(env, solution));
}
