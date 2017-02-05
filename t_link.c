/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_link.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 13:25:10 by sescolas          #+#    #+#             */
/*   Updated: 2017/02/04 19:31:54 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_link	*create_link(unsigned int id)
{
	t_link	*link;

	if ((link = (t_link *)malloc(sizeof(t_link))))
	{
		link->id = id;
		link->l = NULL;
		link->r = NULL;
		link->u = NULL;
		link->d = NULL;
		link->col = NULL;
	}
	return (link);
}

void	append_link(t_link *link, t_link **list)
{
	t_link	*tmp;

	if (!list)
		return ;
	if (!*list || link == *list)
		*list = link;
	else
	{
		tmp = *list;
		while (tmp->r)
			tmp = tmp->r;
		tmp->r = link;
		link->l = tmp;
	}
}

void	unlink_link(t_link *link)
{
	if (!((link->l && (link->l)->r == link) || ((link->r && (link->r)->l == link))))
		return ;
	if (!(link->d) && !(link->u))
		(link->col)->d = (void *)0;
	if (link->u)
		(link->u)->d = link->d;
	else
		(link->col)->d = link->d;
	if (link->d)
		(link->d)->u = link->u;
	--(link->col)->size;
}