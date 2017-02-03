/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 14:03:26 by sescolas          #+#    #+#             */
/*   Updated: 2017/02/02 18:57:57 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	t_env	*env;
	t_tet	*tets;

	tets = (t_tet *)malloc(sizeof(t_tet));
	if (ac == 2)
	{
		create_env(&env);
		read_file(av[1], &tets, env);
		env->grid_size = 4;
		while (tets)
		{
			printf("%s\n", tets->pos);
			tets = tets->r;
		}
	}
	return (0);
}
