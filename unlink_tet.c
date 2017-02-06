/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unlink_tet.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 18:19:10 by sescolas          #+#    #+#             */
/*   Updated: 2017/02/05 18:09:45 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void unlink_row(t_link *link)
{
	t_link	*tmp;

	tmp = link;
	while (tmp->l)
		tmp = tmp->l;
	while (tmp)
	{
		unlink_link(tmp);
		tmp = tmp->r;
	}
}

static void	unlink_overlap(t_col *col)
{
	t_link *tmp;

	if (!(col->size))
		return ;
	tmp = col->d;
	while (tmp)
	{
		unlink_row(tmp);
		tmp = tmp->d;
	}
}

static void	unlink_id(unsigned int id, t_col **grid)
{
	t_col	*col;
	t_link	*link;

	col = *grid;
	while (col)
	{
		if (!(col->size))
		{
			col = col->r;
			continue ;
		}
		link = col->d;
		while (link)
		{
			if (link->id == id)
				unlink_row(link);
			link = link->d;
		}
		col = col->r;
	}
}

void	unlink_tet(t_col *col, t_env *env)
{
	t_link	*tmp;

	if (!(col->size))
		return ;
	tmp = col->d;
	while (tmp->l)
		tmp = tmp->l;
	unlink_id(tmp->id, env->grid);
	while (tmp)
	{
		unlink_col(tmp->col, env->grid);
		unlink_overlap(tmp->col);
		tmp = tmp->r;
	}
}
