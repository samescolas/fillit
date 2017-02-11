/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 11:44:54 by sescolas          #+#    #+#             */
/*   Updated: 2017/02/11 11:08:13 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	translate_tets(t_tet **tets, int grid_size)
{
	t_tet	*tet;

	tet = *tets;
	while (tet)
	{
		tet->pos = translate(shift_top_left(tet->pos), grid_size);
		tet = tet->r;
	}
}

static void	str_to_grid(int id, char *pos, t_col **grid, int *num_rows)
{
	int		i;
	int		links_remaining;
	t_link	*list;
	t_link	*tmp;
	t_col	*col;

	links_remaining = 4;
	col = *grid;
	i = 0;
	(*num_rows)++;
	while (pos[i] && links_remaining)
	{
		if (pos[i++] == '1')
		{
			if (!(tmp = create_link(id, *num_rows)))
				return ;
			if (--links_remaining == 3)
				list = tmp;
			append_link(tmp, &list);
			insert_col(col, tmp);
		}
		col = col->r;
	}
}

static void	add_to_grid(t_tet *tet, t_col **grid, int grid_size, int *num_rows)
{
	int		i;
	int		j;
	char	*pos;

	str_to_grid(tet->id, tet->pos, grid, num_rows);
	i = -1;
	while (++i < grid_size - tet->length + 1)
	{
		j = 0;
		while (j < grid_size - tet->width + 1)
		{
			if (j++ == 0 && i == 0)
				continue ;
			if ((pos = shift(tet->pos, (i * grid_size) + j - 1, grid_size)))
			{
				str_to_grid(tet->id, pos, grid, num_rows);
				free(pos);
			}
			else
				return ;
		}
	}
}

void		create_links(t_env *env)
{
	t_tet	*tet;

	if (!*(env->tets) || !*(env->grid))
		return ;
	translate_tets(env->tets, env->grid_size);
	tet = *(env->tets);
	while (tet)
	{
		add_to_grid(tet, env->grid, env->grid_size, &(env->num_rows));
		tet = tet->r;
	}
}
