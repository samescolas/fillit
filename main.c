/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 14:03:26 by sescolas          #+#    #+#             */
/*   Updated: 2017/02/05 17:53:52 by sescolas         ###   ########.fr       */
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
		{
			if (solution[j++ + i])
				printf("%c", solution[(j - 1) + i] + 'A' - 1);
			else
				printf(".");
		}
		printf("\n");
		i += grid_size;
	}
}

static void	remove_empty_columns(t_col **grid)
{
	t_col *col;

	if (!grid || !*grid)
		return ;
	col = *grid;
	while (col)
	{
		if (col->size == 0)
			unlink_col(col, grid);
		col = col->r;
	}
}

void	setup_shop(t_env **env, char *path, char **solution, unsigned int grid_size)
{
	t_tet	**tets;

	tets = (t_tet **)malloc(sizeof(t_tet *));
	*tets = NULL;
	create_env(env, tets);
	read_file(path, tets, *env);
	create_grid(*env, grid_size);
	*solution = ft_strnew(ft_exp((*env)->grid_size, 2));
	create_links(*env);
	remove_empty_columns((*env)->grid);
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
	}
	else
		write(1, "usage: \n", 8);
	return (0);
}

/*
void	print_nums(int *nums, int size)
{
	int	i;

	i = 0;
	while (i < size)
		printf("%d", nums[i++]);
	printf("\n");
}
*/
