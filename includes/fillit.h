#ifndef FILLIT_H
# define FILLIT_H

# define PIECE_MARKER '#'
# define EMPTY_MARKER '.'

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct		s_env
{
	unsigned int	num_tets;
	unsigned int	grid_size;
}					t_env;

typedef struct		s_col
{
	unsigned int	size;
	struct s_col	*l;
	struct s_col	*r;
	struct s_col	*d;
	struct s_col	*root;
}					t_col;

typedef struct		s_link
{
	unsigned int	id;
	struct s_link	*l;
	struct s_link	*r;
	struct s_link	*u;
	struct s_link	*d;
	struct s_col	*col;
}					t_link

typedef struct	s_tet
{
	unsigned int	id;
	char			*pos;
	struct s_tet	*r;
	struct s_tet	*l;
}				t_tet

#endif
