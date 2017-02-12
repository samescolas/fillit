/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 09:47:24 by sescolas          #+#    #+#             */
/*   Updated: 2017/02/11 13:50:04 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	estimate_grid_size(t_env *env)
{
	int		i;
	t_tet	*tet;

	if (!env)
		return ;
	i = 0;
	while ((int)ft_exp(i, 2) < env->num_tets * 4)
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

void		create_grid(t_env *env, int grid_size)
{
	int		i;
	t_col	*col;

	if (grid_size == 0)
		estimate_grid_size(env);
	else
		env->grid_size = grid_size;
	i = 1;
	*(env->grid) = create_col(0, NULL);
	(*(env->grid))->root = *(env->grid);
	while (i++ < env->grid_size * env->grid_size)
		append_col(create_col(i - 1, *(env->grid)), env->grid);
	col = *(env->grid);
	while (col->r)
		col = col->r;
	col->r = col->root;
	(col->root)->l = col;
	env->num_cols = i + 1;
}
