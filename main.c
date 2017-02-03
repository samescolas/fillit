/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 14:03:26 by sescolas          #+#    #+#             */
/*   Updated: 2017/02/03 14:19:45 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	t_env	*env;
	t_tet	**tets;

	tets = (t_tet **)malloc(sizeof(t_tet *));
	*tets = NULL;
	if (ac == 2)
	{
		create_env(&env, tets);
		read_file(av[1], tets, env);
		estimate_grid_size(env);
		create_grid(env);
	}
	return (0);
}
