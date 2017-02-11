/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_link2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 20:22:21 by sescolas          #+#    #+#             */
/*   Updated: 2017/02/10 22:07:23 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	relink_link(t_link *link)
{
	if (!link)
		return ;
	link->col->size++;
	if ((link->col)->size == 1 || link->col->d->row > link->row)
		link->col->d = link;
	link->u->d = link;
	link->d->u = link;
}
