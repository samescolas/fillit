/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_tet.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 14:44:51 by sescolas          #+#    #+#             */
/*   Updated: 2017/02/04 16:24:19 by sescolas         ###   ########.fr       */
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
