/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_col.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 13:29:44 by sescolas          #+#    #+#             */
/*   Updated: 2017/02/03 14:09:25 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_col	*create_col(t_col *root)
{
	t_col	*col;

	if ((col = (t_col *)malloc(sizeof(t_col))))
	{
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
	tmp = *list;
	while (tmp->r)
		tmp = tmp->r;
	tmp->r = col;
	col->l = tmp;
}
