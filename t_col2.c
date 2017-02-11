/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_col2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 19:33:36 by sescolas          #+#    #+#             */
/*   Updated: 2017/02/11 11:08:49 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		count_cols(t_col **grid)
{
	int		count;
	t_col	*tmp;

	count = 0;
	if (!grid || !(*grid))
		return (count);
	tmp = *grid;
	while (tmp != *grid || !count)
	{
		++count;
		tmp = tmp->r;
	}
	return (count);
}
