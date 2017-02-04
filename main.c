/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 14:03:26 by sescolas          #+#    #+#             */
/*   Updated: 2017/02/03 16:47:22 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	t_env	*env;
	t_tet	**tets;
	t_tet	*tmp;

	tets = (t_tet **)malloc(sizeof(t_tet *));
	*tets = NULL;
	if (ac == 2)
	{
		create_env(&env, tets);
		read_file(av[1], tets, env);
		estimate_grid_size(env);
		create_grid(env);
		tmp = *(env->tets);
		while (tmp)
		{
			printf("Original: \n%s\n", translate(tmp->pos, env));
			printf("New:\n%s\n", translate(shift_up(shift_left(tmp->pos)), env));
			tmp = tmp->r;
		}

	}
	return (0);
}
