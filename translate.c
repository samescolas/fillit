/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 15:09:42 by sescolas          #+#    #+#             */
/*   Updated: 2017/02/08 19:00:15 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char			*translate(char *tet, int grid_size)
{
	int		r;
	int		c;
	int		k;
	char	*ret;

	if ((ret = (char *)malloc(((grid_size * grid_size) + 1) * sizeof(char))))
	{
		r = 0;
		k = 0;
		while (r < grid_size)
		{
			c = 0;
			while (c < grid_size)
			{
				if (c++ > 3 || r > 3)
					ret[k++] = '0';
				else
					ret[k++] = \
						(tet[(r * 5) + c - 1] == PIECE_MARKER ? '1' : '0');
			}
			++r;
		}
		ret[k] = '\0';
	}
	return (ret);
}

char			*shift(char *tet, int offset, int grid_size)
{
	int		i;
	int		j;
	char	*ret;

	if ((ret = (char *)malloc((ft_exp((int)grid_size, 2) + 1) * sizeof(char))))
	{
		i = 0;
		while (i < offset)
			ret[i++] = '0';
		j = 0;
		while (j + offset < ft_exp((int)grid_size, 2))
			ret[i++] = tet[j++];
		ret[i] = '\0';
	}
	return (ret);
}

int				get_length(char *tet)
{
	int		i;
	int		j;
	int		length;

	length = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tet[(i * 5) + j++] == PIECE_MARKER)
			{
				++length;
				break ;
			}
		}
		++i;
	}
	return (length);
}

int				get_width(char *tet)
{
	int		i;
	int		j;
	int		width;

	width = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tet[i + j++ * 5] == PIECE_MARKER)
			{
				++width;
				break ;
			}
		}
		++i;
	}
	return (width);
}
