/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 16:56:26 by sescolas          #+#    #+#             */
/*   Updated: 2017/02/06 12:22:50 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		col_count(char *tet)
{
	int		i;
	int		j;
	int		ret;

	i = 0;
	ret = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 4)
		{
			if (tet[(j * 5) + i] != PIECE_MARKER)
				++ret;
			else
			{
				i = 5;
				break ;
			}
			++j;
		}
		++i;
	}
	return (ret / 4);
}

static char		*shift_up(char *tet)
{
	int		i;
	int		j;
	int		offset;

	i = 0;
	while (tet[i])
	{
		if (tet[i] == EMPTY_MARKER && tet[i + 1] == EMPTY_MARKER &&
				tet[i + 2] == EMPTY_MARKER && tet[i + 3] == EMPTY_MARKER)
			i += 5;
		else
			break ;
	}
	j = 0;
	offset = i;
	while (tet[i])
		tet[j++] = tet[i++];
	while (offset--)
	{
		++j;
		tet[j] = ((j + 1) % 5 == 0 ? '\n' : EMPTY_MARKER);
	}
	tet[j] = '\0';
	return (tet);
}

static char		*shift_left(char *tet)
{
	int		i;
	int		j;
	int		k;
	int		offset;

	i = 0;
	offset = col_count(tet);
	i = -1;
	k = 0;
	while (tet[++i])
	{
		j = offset;
		while (j--)
			++i;
		while (tet[i] && tet[i] != '\n')
			tet[k++] = tet[i++];
		j = offset;
		while (j--)
			tet[k++] = EMPTY_MARKER;
		tet[k++] = '\n';
	}
	tet[k] = '\0';
	return (tet);
}

char			*shift_top_left(char *tet)
{
	return (shift_left(shift_up(tet)));
}
