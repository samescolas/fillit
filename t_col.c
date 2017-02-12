/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_col.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 13:29:44 by sescolas          #+#    #+#             */
/*   Updated: 2017/02/11 14:08:50 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_col	*create_col(int id, t_col *root)
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
	int		i;

	if (col->size > 0)
	{
		i = 1;
		tmp = col->d;
		tmp->u = link;
		link->d = tmp;
		while (i < col->size)
		{
			tmp = tmp->d;
			++i;
		}
		tmp->d = link;
		link->u = tmp;
	}
	else
	{
		col->d = link;
		link->d = link;
		link->u = link;
	}
	col->size++;
	link->col = col;
}

void	unlink_col(t_col *col, t_env *env)
{
	if (col->l == col)
	{
		*(env->grid) = (void *)0;
		return ;
	}
	if (*(env->grid) == col)
		*(env->grid) = col->r;
	(col->l)->r = col->r;
	(col->r)->l = col->l;
}

void	relink_col(t_col *col, t_env *env)
{
	if (!*(env->grid))
	{
		*(env->grid) = col;
		return ;
	}
	if (col->id < (col->l)->id)
		*(env->grid) = col;
	(col->l)->r = col;
	(col->r)->l = col;
}
