/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dancing_links.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 18:41:24 by sescolas          #+#    #+#             */
/*   Updated: 2017/02/08 23:10:46 by sescolas         ###   ########.fr       */
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
		while(tmp)
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

t_col	*choose_col(t_col **grid)
{
	t_col	*tmp;
	t_col	*min;
	int		cols;

	if (!grid || !(*grid))
		return ((void *)0);
	tmp = *grid;
	cols = count_cols(grid);
	while (cols && tmp->size == 0)
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
	return (min->size ? min : (void *)0);
}

int				solve(t_env *env, char **solution, int unplaced_tets)
{
	t_col	*col;
	t_link	*link;
	t_link	*tmp;

	printf("entering solve\nunplaced_tets: %d\tcolumns: %d\nboard:\n", unplaced_tets, count_cols(env->grid));
	print_solution(*solution, env->grid_size);
	if (!unplaced_tets || !(*(env->grid)))
	{
		printf("%s!\n", (unplaced_tets == 0 ? "done" : "problems"));
		return (unplaced_tets == 0);
	}
	printf("choosing a column\n");
	if (!(col = choose_col(env->grid)))
		return (0);
	printf("chose column\nid: %d\tsize: %d\n", col->id, col->size);
	link = col->d;
	printf("chose link\nid: %d\trow: %d\tcol: %d\n", link->id, link->row, (link->col)->id);
	while (link->l)
	{
		printf("finding beginning of piece\n");
		link = link->l;
	}
	printf("unlinking tet\n");
	unlink_tet(link, env);
	printf("unlinked!\nupdating solution\n");
	update_solution(link, solution, ft_exp(env->grid_size, 2), 1);
	printf("updated (hopefully)\n");
	if (solve(env, solution, unplaced_tets - 1))
	{
		printf("did it!\n");
		return (1);
	}
	printf("no bueno -- removing from solution\n");
	update_solution(link, solution, ft_exp(env->grid_size, 2), 0);
	printf("removed from solution\nundoing unlinking process\n");
	undo_unlink(link, env, *solution);
	printf("done undoing unlink\nremoving piece %d from col %d\n", link->id, (link->col)->id);
	tmp = link;
	while (tmp)
	{
		if ((link->col)->size)
			unlink_link(tmp, env->unlinked_links);
		tmp = tmp->r;
	}
	printf("unlinked row\n");
	return (solve(env, solution, unplaced_tets));
}
