/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unlink_tet.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 18:19:10 by sescolas          #+#    #+#             */
/*   Updated: 2017/02/06 17:03:01 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	unlink_row(t_link *link, t_link **unlinked_links)
{
	t_link	*tmp;

	tmp = link;
	while (tmp->l)
		tmp = tmp->l;
	while (tmp)
	{
		unlink_link(tmp, unlinked_links);
		tmp = tmp->r;
	}
}

static void	unlink_overlap(t_col *col, t_link **unlinked_links)
{
	t_link *tmp;

	if (!(col->size))
		return ;
	tmp = col->d;
	while (tmp)
	{
		unlink_row(tmp, unlinked_links);
		tmp = tmp->d;
	}
}

static void	unlink_id(unsigned int id, t_env *env)
{
	t_col	*col;
	t_link	*link;

	col = *(env->grid);
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
				unlink_row(link, env->unlinked_links);
			link = link->d;
		}
		col = col->r;
	}
}

void		unlink_tet(t_link *link, t_env *env)
{
	t_link	*tmp;

	tmp = link;
	while (tmp->l)
		tmp = tmp->l;
	unlink_id(tmp->id, env);
	while (tmp)
	{
		unlink_col(tmp->col, env->grid);
		unlink_overlap(tmp->col, env->unlinked_links);
		tmp = tmp->r;
	}
}
