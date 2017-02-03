/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 15:09:42 by sescolas          #+#    #+#             */
/*   Updated: 2017/02/03 11:45:27 by sescolas         ###   ########.fr       */
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
