/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 20:28:12 by sescolas          #+#    #+#             */
/*   Updated: 2017/02/11 13:52:56 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_solution(char *solution, int grid_size)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	while (i < grid_size * grid_size)
	{
		j = 0;
		while (j < grid_size)
		{
			if (solution[j++ + i])
			{
				c = solution[(j - 1) + i] + 'A' - 1;
				write(1, &c, 1);
			}
			else
				write(1, ".", 1);
		}
		write(1, "\n", 1);
		i += grid_size;
	}
}

void	setup_shop(t_env **env, char *path, char **solution, int grid_size)
{
	t_tet	**tets;

	tets = (t_tet **)malloc(sizeof(t_tet *));
	*tets = NULL;
	create_env(env, tets);
	read_file(path, tets, *env);
	create_grid(*env, grid_size);
	*solution = ft_strnew(ft_exp((*env)->grid_size, 2));
	create_links(*env);
}

int		main(int ac, char **av)
{
	t_env	*env;
	t_tet	**tets;
	char	*solution;
	int		grid_size;

	tets = (t_tet **)malloc(sizeof(t_tet *));
	*tets = NULL;
	if (ac == 2)
	{
		setup_shop(&env, av[1], &solution, 0);
		grid_size = env->grid_size;
		while (!solve(env, &solution, env->num_tets))
		{
			++grid_size;
			setup_shop(&env, av[1], &solution, grid_size);
		}
		print_solution(solution, env->grid_size);
		write(1, "\n", 1);
	}
	else
		write(1, "usage: \n", 8);
	return (0);
}
