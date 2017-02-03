#ifndef FILLIT_H
# define FILLIT_H

# define PIECE_MARKER '#'
# define EMPTY_MARKER '.'

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"
# include <stdio.h> //testing 

typedef struct		s_col
{
	unsigned int	size;
	struct s_col	*l;
	struct s_col	*r;
	struct s_col	*d;
	struct s_col	*root;
}					t_col;

typedef struct		s_env
{
	unsigned int	num_tets;
	unsigned int	grid_size;
	t_col			*grid;
}					t_env;

typedef struct		s_link
{
	unsigned int	id;
	struct s_link	*l;
	struct s_link	*r;
	struct s_link	*u;
	struct s_link	*d;
	struct s_col	*col;
}					t_link;

typedef struct		s_tet
{
	unsigned int	id;
	char			*pos;
	struct s_tet	*r;
	struct s_tet	*l;
}					t_tet;

void	read_file(char *path, t_tet **tets, t_env *env);
char	*translate(char *str, t_env *env);
t_tet	*create_tet(int id, char *pos);
void	append_tet(t_tet *tet, t_tet **list);
void	create_env(t_env **env);

#endif
