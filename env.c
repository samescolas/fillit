/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 17:33:23 by sescolas          #+#    #+#             */
/*   Updated: 2017/02/02 17:45:36 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	create_env(t_env **env)
{
	if((*env = (t_env *)malloc(sizeof(t_env))))
	{
		(*env)->grid_size = 0;
		(*env)->num_tets = 0;
		(*env)->grid = (t_col *)malloc(sizeof(t_col));
	}
}
