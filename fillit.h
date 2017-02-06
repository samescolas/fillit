/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 11:17:06 by sescolas          #+#    #+#             */
/*   Updated: 2017/02/06 15:16:41 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define PIECE_MARKER '#'
# define EMPTY_MARKER '.'

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h> //testing

typedef struct		s_col
{
	unsigned int	id;
	unsigned int	size;
	struct s_col	*l;
	struct s_col	*r;
	struct s_link	*d;
	struct s_col	*root;
	struct s_col	*next_unlinked;
}					t_col;

typedef struct		s_link
{
	unsigned int	id;
	struct s_link	*l;
	struct s_link	*r;
	struct s_link	*u;
	struct s_link	*d;
	struct s_col	*col;
	struct s_link	*next_unlinked;
}					t_link;

typedef struct		s_tet
{
	unsigned int	id;
	unsigned int	length;
	unsigned int	width;
	char			*pos;
	struct s_tet	*r;
	struct s_tet	*l;
}					t_tet;

typedef struct		s_env
{
	unsigned int	num_tets;
	unsigned int	grid_size;
	t_tet			**tets;
	t_col			**grid;
	t_link			**unlinked_links;
	t_col			**unlinked_cols;
}					t_env;

void				read_file(char *path, t_tet **tets, t_env *env);
char				*translate(char *str, unsigned int grid_size);
t_tet				*create_tet(int id, char *pos);
t_col				*create_col(unsigned int id, t_col *root);
t_link				*create_link(unsigned int id);
void				append_tet(t_tet *tet, t_tet **list);
void				append_col(t_col *col, t_col **list);
void				append_link(t_link *link, t_link **list);
void				insert_col(t_col *col, t_link *link);
void				unlink_tet(t_col *col, t_env *env);
void				unlink_link(t_link *link, t_link **unlinked_links);
void				unlink_col(t_col *col, t_col **grid, t_col **unlinked_cols);
t_tet				*find_tet(t_tet **list, int id);
void				create_env(t_env **env, t_tet **tets);
void				create_grid(t_env *grid, unsigned int grid_size);
unsigned int		get_width(char *tet);
unsigned int		get_length(char *tet);
char				*shift_top_left(char *tet);
char				*shift(char *tet, int offset, unsigned int grid_size);
void				create_links(t_env *env);
int					solve(t_env *env, char **solution, int num_tets);
int					list_len(t_col *list);
int					*get_next_permutation(int *n, int size);
void				sort_tets(t_tet **list, int *arr, int size);
int					*get_ids(t_tet **list, int num_tets);

#endif
