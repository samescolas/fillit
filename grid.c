/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 09:47:24 by sescolas          #+#    #+#             */
/*   Updated: 2017/02/03 14:16:34 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	estimate_grid_size(t_env *env)
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
		if (get_width(tet->pos) > env->grid_size)
			env->grid_size = get_width(tet->pos);
		if (get_length(tet->pos) > env->grid_size)
			env->grid_size = get_length(tet->pos);
		tet = tet->r;
	}
}

void	create_grid(t_env *env)
{
	unsigned int	i;
	t_col			*tmp;

	i = 1;
	*(env->grid) = create_col(NULL);
	(*(env->grid))->root = *(env->grid);
	while (i++ < env->grid_size * env->grid_size)
	{
		tmp = create_col(*(env->grid));
		append_col(create_col(*(env->grid)), env->grid);
	}
}
