/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_tet.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 14:44:51 by sescolas          #+#    #+#             */
/*   Updated: 2017/02/06 12:43:29 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tet		*create_tet(int id, char *pos)
{
	t_tet	*tet;

	if ((tet = (t_tet *)malloc(sizeof(t_tet))))
	{
		tet->pos = pos;
		tet->length = get_length(tet->pos);
		tet->width = get_width(tet->pos);
		tet->id = id;
		tet->r = NULL;
		tet->l = NULL;
	}
	return (tet);
}

void		append_tet(t_tet *tet, t_tet **list)
{
	t_tet	*tmp;

	if (!list)
		return ;
	if (!*list)
		*list = tet;
	else
	{
		tmp = *list;
		while (tmp->r)
			tmp = tmp->r;
		tmp->r = tet;
		tet->l = tmp;
	}
}

t_tet		*find_tet(t_tet **list, int id)
{
	t_tet	*tet;

	tet = *list;
	while (tet)
	{
		if ((int)(tet->id) == id)
			return (tet);
		tet = tet->r;
	}
	return ((void *)0);
}

static void	unlink_tetromino(t_tet *tet, t_tet **list)
{
	if (!(tet->l) && !(tet->r))
		*list = (void *)0;
	if (tet->l)
		(tet->l)->r = tet->r;
	else
		*list = tet->r;
	if (tet->r)
		(tet->r)->l = tet->l;
}

void		sort_tets(t_tet **list, int *arr, int size)
{
	int		i;
	t_tet	*tet;
	t_tet	*ret;

	ret = NULL;
	i = 0;
	while (i < size)
	{
		tet = find_tet(list, arr[i++]);
		unlink_tetromino(tet, list);
		tet->r = NULL;
		tet->l = NULL;
		append_tet(tet, &ret);
	}
	*list = ret;
}
