/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 14:03:20 by sescolas          #+#    #+#             */
/*   Updated: 2017/02/03 13:24:47 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	*read_tet(int fd, char **tet)
{
	if (!(*tet = (char *)malloc(22 * sizeof(char))))
		return (NULL);
	ft_bzero(*tet, 22);
	if ((read(fd, *tet, 21) <= 0))
		return (NULL);
	return (*tet);
}

static int	valid_marker(char *tet, int pos)
{
	if (pos % 5 != 0)
		if (tet[pos - 1] == PIECE_MARKER)
			return (1);
	if ((pos + 1) % 5 != 0)
		if (tet[pos + 1] == PIECE_MARKER)
			return (1);
	if (pos > 4)
		if (tet[pos - 5] == PIECE_MARKER)
			return (1);
	if (pos < 15)
		if (tet[pos + 5] == PIECE_MARKER)
			return (1);
	return (0);
}

static int	validate(char *tet)
{
	int		markers_remaining;
	int		i;

	if (tet[20] != '\n')
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
			if (tet[i] == PIECE_MARKER && valid_marker(tet, i))
				--markers_remaining;
			else if (tet[i] == PIECE_MARKER)
				return (0);
		}
	}
	return (i == 20 && !markers_remaining);
}

void	read_file(char *path, t_tet **tets, t_env *env)
{
	int		fd;
	char	*tet;

	if ((fd = open(path, O_RDONLY)) > 0)
	{
		while (read_tet(fd, &tet))
		{
			if (validate(tet))
				append_tet(create_tet(++(env->num_tets), tet), tets);
			else
				break ;
		}
		close(fd);
		if (*tet)
		{
			*tets = NULL;
			write(2, "err: invalid input\n", 19);
		}
	}
	else
		write(2, "err: invalid file\n", 18);
}
