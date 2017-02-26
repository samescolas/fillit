/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semantics.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 17:20:08 by sescolas          #+#    #+#             */
/*   Updated: 2017/02/25 20:53:54 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	free_link(t_link *link)
{
	--link->col->size;
	link->u = NULL;
	link->d = NULL;
	link->l = NULL;
	link->r = NULL;
	link->col = NULL;
	link->next_unlinked = NULL;
	link = (void *)0;
	free(link);
}

static void	free_col(t_col *col)
{
	t_link	*tmp;

	if (col->size == 0)
	{
		col->l = NULL;
		col->r = NULL;
		col->d = NULL;
		col->root = NULL;
		col->next_unlinked = NULL;
		return ;
	}
	tmp = col->d;
	col->d = col->d->d;
	free_link(tmp);
	free_col(col);
}

static void	free_unlinked_cols(t_col *cols)
{
	t_col	*tmp;

	if (cols == (void *)0)
		return ;
	tmp = cols;
	cols = cols->next_unlinked;
	free(tmp);
	free_unlinked_cols(cols);
}

static void	free_unlinked_links(t_link **links)
{
	t_link	*tmp;

	if (*links == (void *)0)
	{
		free(*links);
		links = (void *)0;
		return ;
	}
	tmp = *links;
	*links = (*links)->next_unlinked;
	free(tmp);
	free_unlinked_links(links);
}

void		free_grid(t_col **grid, t_env *env)
{
	t_col	*tmp;

	if (*grid == (void *)0)
	{
		free(grid);
		free_unlinked_links(env->unlinked_links);
		free_unlinked_cols(env->unlinked_cols);
		return ;
	}
	tmp = *grid;
	if (*grid == (*grid)->r)
		*grid = (void *)0;
	else
		*grid = (*grid)->r;
	free_col(tmp);
	free_grid(grid, env);
}
