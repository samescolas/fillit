/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_link.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 13:25:10 by sescolas          #+#    #+#             */
/*   Updated: 2017/02/25 17:14:11 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_link	*create_link(int id, int row)
{
	t_link	*link;

	if ((link = (t_link *)malloc(sizeof(t_link))))
	{
		link->id = id;
		link->row = row;
		link->l = NULL;
		link->r = NULL;
		link->u = NULL;
		link->d = NULL;
		link->col = NULL;
		link->next_unlinked = NULL;
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

void	push_link(t_link *link, t_link **removed_links)
{
	if (*removed_links)
		link->next_unlinked = *removed_links;
	*removed_links = link;
}

t_link	*pop_link(t_link **removed_links)
{
	t_link	*link;

	if (!*removed_links)
		return ((void *)0);
	link = *removed_links;
	*removed_links = link->next_unlinked;
	return (link);
}

void	unlink_link(t_link *link, t_link **removed_links)
{
	if (!link)
		return ;
	if (link->col->size == 1)
	{
		link->col->size = 0;
		link->col->d = (void *)0;
		if (link->l == NULL)
			push_link(link, removed_links);
		return ;
	}
	else if (link->col->d == link)
		link->col->d = link->d;
	link->u->d = link->d;
	link->d->u = link->u;
	if (link->l == NULL)
		push_link(link, removed_links);
	link->col->size--;
}
