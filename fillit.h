/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 11:17:06 by sescolas          #+#    #+#             */
/*   Updated: 2017/02/25 17:16:08 by sescolas         ###   ########.fr       */
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

typedef struct		s_col
{
	int				id;
	int				size;
	struct s_col	*l;
	struct s_col	*r;
	struct s_link	*d;
	struct s_col	*root;
}					t_col;

typedef struct		s_link
{
	int				id;
	int				row;
	struct s_link	*l;
	struct s_link	*r;
	struct s_link	*u;
	struct s_link	*d;
	struct s_col	*col;
	struct s_link	*next_unlinked;
}					t_link;

typedef struct		s_tet
{
	int				id;
	int				length;
	int				width;
	char			*pos;
	struct s_tet	*r;
	struct s_tet	*l;
}					t_tet;

typedef struct		s_env
{
	int				num_tets;
	int				num_cols;
	int				num_rows;
	int				grid_size;
	t_tet			**tets;
	t_col			**grid;
	t_link			**unlinked_links;
	t_col			**unlinked_cols;
}					t_env;

void				read_file(char *path, t_tet **tets, t_env *env);
char				*translate(char *str, int grid_size);
t_tet				*create_tet(int id, char *pos);
t_col				*create_col(int id, t_col *root);
t_link				*create_link(int id, int row);
void				append_tet(t_tet *tet, t_tet **list);
void				append_col(t_col *col, t_col **list);
void				append_link(t_link *link, t_link **list);
void				insert_col(t_col *col, t_link *link);
void				unlink_tet(t_link *link, t_env *env);
void				unlink_link(t_link *link, t_link **unlinked_links);
void				unlink_col(t_col *col, t_env *env);
t_tet				*find_tet(t_tet **list, int id);
void				create_env(t_env **env, t_tet **tets);
void				create_grid(t_env *grid, int grid_size);
int					get_width(char *tet);
int					get_length(char *tet);
char				*shift_top_left(char *tet);
char				*shift(char *tet, int offset, int grid_size);
void				create_links(t_env *env);
int					solve(t_env *env, char **solution, int num_tets);
int					list_len(t_col *list);
int					*get_next_permutation(int *n, int size);
void				sort_tets(t_tet **list, int *arr, int size);
int					*get_ids(t_tet **list, int num_tets);
void				relink_tet(t_link *link, t_env *env, char *solution);
t_link				*choose_link(t_col **grid, int num_cols, int id);
void				remove_empty_cols(t_col **grid);
t_link				*pop_link(t_link **removed_links);
void				push_link(t_link *link, t_link **removed_links);
void				unlink_row(t_link *link, t_env *env);
void				relink_col(t_col *col, t_env *env);
void				unlink_tet(t_link *link, t_env *env);
void				undo_unlink(t_link *link, t_env *env, char *solution);
void				relink_link(t_link *link);
void				print_solution(char *solution, int grid_size);
void				display_grid(t_env *env);

#endif
