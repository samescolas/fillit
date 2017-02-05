/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 14:03:26 by sescolas          #+#    #+#             */
/*   Updated: 2017/02/04 19:14:56 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	t_env	*env;
	t_tet	**tets;
	char	*solution;

	solution = (char *)malloc(sizeof(char) * 101);
	ft_bzero(solution, 101);
	tets = (t_tet **)malloc(sizeof(t_tet *));
	*tets = NULL;
	if (ac == 2)
	{
		create_env(&env, tets);
		read_file(av[1], tets, env);
		create_grid(env);
		create_links(env);
		solve(env, &solution);	
		return (0);
	}
	else
		write(1, "usage: \n", 8);
}
