/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 09:47:24 by sescolas          #+#    #+#             */
/*   Updated: 2017/02/04 20:34:56 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	estimate_grid_size(t_env *env)
{
	unsigned int		i;
	t_tet				*tet;

	if (!env)
		return ;
	i = 0;
	while ((unsigned int)ft_exp(i, 2) < env->num_tets * 4)
		++i;
	env->grid_size = i;
	tet = *(env->tets);
	while (tet)
	{
		if (tet->width > env->grid_size)
			env->grid_size = tet->width;
		if (tet->length > env->grid_size)
			env->grid_size = tet->length;
		tet = tet->r;
	}
}

void		create_grid(t_env *env)
{
	unsigned int	i;

	if (env->grid_size == 0)
		estimate_grid_size(env);
	i = 1;
	*(env->grid) = create_col(0, NULL);
	(*(env->grid))->root = *(env->grid);
	while (i++ < env->grid_size * env->grid_size)
		append_col(create_col(i - 1, *(env->grid)), env->grid);
}
