/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 15:09:42 by sescolas          #+#    #+#             */
/*   Updated: 2017/02/02 15:15:41 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*translate(char *str, t_env *env)
{
	char	*tet;
	char	*tmp;

	tmp = str;
	if (!(tet = (char *)malloc((() + 1) * sizeof(char))))
		return (NULL);
	while (*tmp)
	{
		if (*tmp == PIECE_MARKER)
			*tet++ = '1';
		if (*tmp == EMPTY_MARKER)
			*tet++ = '0';
		++tmp;
}
