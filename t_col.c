/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_col.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 13:29:44 by sescolas          #+#    #+#             */
/*   Updated: 2017/02/05 16:47:02 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_col	*create_col(unsigned int id, t_col *root)
{
	t_col	*col;

	if ((col = (t_col *)malloc(sizeof(t_col))))
	{
		col->id = id;
		col->size = 0;
		col->l = NULL;
		col->r = NULL;
		col->d = NULL;
		col->root = root;
	}
	return (col);
}

void	append_col(t_col *col, t_col **list)
{
	t_col	*tmp;

	if (!list)
		return ;
	if (!*list)
		*list = col;
	else
	{
		tmp = *list;
		while (tmp->r)
			tmp = tmp->r;
		tmp->r = col;
		col->l = tmp;
	}
}

void	insert_col(t_col *col, t_link *link)
{
	t_link	*tmp;

	if (!col || !link)
		return ;
	link->col = col;
	if ((col->size)++ == 0)
		col->d = link;
	else
	{
		tmp = col->d;
		while (tmp->d)
			tmp = tmp->d;
		tmp->d = link;
		link->u = tmp;
	}
}

void	unlink_col(t_col *col, t_col **grid)
{
	if (!(col->l) && !(col->r))
	{
		*grid = (void *)0;
		return ;
	}
	if (col->l)
		(col->l)->r = col->r;
	else
		*grid = col->r;
	if (col->r)
		(col->r)->l = col->l;
}
