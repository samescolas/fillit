/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 15:09:42 by sescolas          #+#    #+#             */
/*   Updated: 2017/02/02 19:22:41 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*translate(char *str, t_env *env)
{
	char	*tet;
	int		i;
	int		j;

	if (env->grid_size == 0)
		env->grid_size = 4;
	if (!(tet = (char *)malloc(((env->grid_size * env->grid_size) + 1) * sizeof(char))))
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
