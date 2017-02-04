/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 15:09:42 by sescolas          #+#    #+#             */
/*   Updated: 2017/02/03 16:36:26 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		*translate(char *str, t_env *env)
{
	char	*tet;
	int		i;
	int		j;

	if (env->grid_size == 0)
		env->grid_size = 4;
	if (!(tet = (char *)malloc(17 * sizeof(char))))
		return (NULL);
	i = -1;
	j = 0;
	while (str[++i])
	{
		if (str[i] == '#')
			tet[j++] = '1';
		if (str[i] == '.')
			tet[j++] = '0';
	}
	tet[j] = '\0';
	ft_bzero(str, 21);
	free(str);
	return (tet);
}

int			col_count(char *tet)
{
	int	i;
	int	j;
	int	ret;

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

char		*shift_up(char *tet)
{
	int	i;
	int	j;
	int	offset;

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
		tet[j] = ((j + 1) % 5 == 0 ? '\n' : '.');
	}
	tet[j] = '\0';
	return (tet);
}

char		*shift_left(char *tet)
{
	int	i;
	int	j;
	int k;
	int	offset;

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

unsigned int	get_length(char *tet)
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

unsigned int	get_width(char *tet)
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
