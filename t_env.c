/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_env.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 17:33:23 by sescolas          #+#    #+#             */
/*   Updated: 2017/02/05 18:07:15 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	create_env(t_env **env, t_tet **tets)
{
	if ((*env = (t_env *)malloc(sizeof(t_env))))
	{
		(*env)->grid_size = 0;
		(*env)->num_tets = 0;
		(*env)->tets = (t_tet **)malloc(sizeof(t_tet *));
		(*env)->grid = (t_col **)malloc(sizeof(t_col *));
		*((*env)->grid) = NULL;
		(*env)->tets = tets;
	}
}

int		*get_ids(t_tet **list, int num_tets)
{
	int		*ret;
	t_tet	*tet;
	int		i;

	if ((ret = (int *)malloc(num_tets * sizeof(int))))
	{
		tet = *list;
		i = 0;
		while (tet)
		{
			ret[i++] = (int)(tet->id);
			tet = tet->r;
		}
	}
	return (ret);
}

void	sort_tets(t_tet **list, int *arr, int size)
{
	int		i;
	t_tet	*tet;
	t_tet	*ret;

	ret = NULL;
	i = 0;
	while (i < size)
	{
		tet = find_tet(list, arr[i++]);
		unlink_tetromino(tet, list);
		tet->r = NULL;
		tet->l = NULL;
		append_tet(tet, &ret);
	}
	*list = ret;
}

int		permute_tets(t_env *env)
{
	int		*perm;

	perm = get_ids(env->tets, env->num_tets);
	if (!(perm = get_next_permutation(perm, env->num_tets)))
		return (0);
	sort_tets(env->tets, perm, env->num_tets);
	return (1);
}
