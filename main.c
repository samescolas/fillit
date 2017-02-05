/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 14:03:26 by sescolas          #+#    #+#             */
/*   Updated: 2017/02/04 20:35:00 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_solution(char *solution, unsigned int grid_size)
{
	unsigned int		i;
	unsigned int		j;

	i = 0;
	j = 0;
	while (i < grid_size * grid_size)
	{
		j = 0;
		while (j < grid_size)
			printf("%c", solution[j++ + i] + 'A' - 1);
		printf("\n");
		i += grid_size;
	}
}

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
		while (!solve(env, &solution))
		{
			++(env->grid_size);
			free(solution);
			solution = ft_strnew(ft_exp(env->grid_size, 2) + 1);
			create_grid(env);
		}
		print_solution(solution, env->grid_size);
		return (0);
	}
	else
		write(1, "usage: \n", 8);
}
