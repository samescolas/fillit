/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 14:03:20 by sescolas          #+#    #+#             */
/*   Updated: 2017/02/25 17:05:19 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		read_tet(int fd, char **tet)
{
	int ret;

	if (!(*tet = (char *)malloc(22 * sizeof(char))))
		return (0);
	ft_bzero(*tet, 22);
	ret = read(fd, *tet, 21);
	return (ret <= 0 ? 0 : ret);
}

static int		valid_marker(char *tet, int pos, int *faces)
{
	if (pos % 5 != 0)
		if (tet[pos - 1] == PIECE_MARKER)
			++(*faces);
	if ((pos + 1) % 5 != 0)
		if (tet[pos + 1] == PIECE_MARKER)
			++(*faces);
	if (pos > 4)
		if (tet[pos - 5] == PIECE_MARKER)
			++(*faces);
	if (pos < 15)
		if (tet[pos + 5] == PIECE_MARKER)
			++(*faces);
	return (*faces);
}

static int		validate(char *tet, int last_tet)
{
	int		markers_remaining;
	int		i;
	int		faces;

	faces = 0;
	if ((last_tet && tet[20] != '\0') || (!last_tet && tet[20] != '\n'))
		return (0);
	tet[20] = '\0';
	markers_remaining = 4;
	i = -1;
	while (tet[++i])
	{
		if ((i + 1) % 5 == 0 && tet[i] != '\n')
			return (0);
		else if ((i + 1) % 5 != 0)
		{
			if (tet[i] != PIECE_MARKER && tet[i] != EMPTY_MARKER)
				return (0);
			if (tet[i] == PIECE_MARKER && valid_marker(tet, i, &faces))
				--markers_remaining;
			else if (tet[i] == PIECE_MARKER)
				return (0);
		}
	}
	return (i == 20 && !markers_remaining && faces >= 6);
}

static void		exit_error(void)
{
	write(1, "error\n", 6);
	exit(1);
}

void			read_file(char *path, t_tet **tets, t_env *env)
{
	int		fd;
	char	*tet;

	if ((fd = open(path, O_RDONLY)) > 0)
	{
		while (read_tet(fd, &tet) == 21)
		{
			if (validate(tet, 0))
				append_tet(create_tet(++(env->num_tets), tet), tets);
			else
				break ;
		}
		if (validate(tet, 1))
			append_tet(create_tet(++(env->num_tets), tet), tets);
		else
			exit_error();
		read_tet(fd, &tet);
		close(fd);
		if (*tet)
			exit_error();
	}
	else
		exit_error();
}
