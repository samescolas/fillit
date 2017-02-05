/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dancing_links.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 16:17:26 by sescolas          #+#    #+#             */
/*   Updated: 2017/02/04 19:31:12 by sescolas         ###   ########.fr       */
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

	printf("choosing from %d cols\n", list_len(*grid));
	tmp = *grid;
	min = tmp;
	while (tmp)
	{
		if (tmp->size <= min->size)
			min = tmp;
		tmp = tmp->r;
	}
	if (min->size == 0)
	{
		unlink_col(min, grid);
		choose_col(grid);
	}
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
		printf("adding %d to solution at position %d\n", tmp->id, (tmp->col)->id);
		(*solution)[(tmp->col)->id] = tmp->id;
		tmp = tmp->r;
	}
}

void	solve(t_env *env, char **solution)
{
	t_col	*col;

	write(1, "entering solve\n", 15);
	if (!*(env->grid))
		return ;
	if (solution)
		write(2, "", 0);
	if (!(col = choose_col(env->grid)))
		return ;
	printf("chose column %d\n", col->id);
	add_to_solution(solution, col);
	printf("added column to solution\n");
	unlink_tet(col, env);
	printf("unlinked tet\n");
	solve(env, solution);
}
