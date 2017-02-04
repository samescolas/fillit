/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 17:33:23 by sescolas          #+#    #+#             */
/*   Updated: 2017/02/03 17:09:35 by sescolas         ###   ########.fr       */
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
