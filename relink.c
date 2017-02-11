/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   relink.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 20:00:47 by sescolas          #+#    #+#             */
/*   Updated: 2017/02/11 13:40:23 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	already_chosen(int id, char *solution, int len)
{
	int		i;

	i = 0;
	while (i < len)
		if (solution[i++] == id)
			return (1);
	return (0);
}

static int	relinkable(t_link *link, t_env *env, char *solution)
{
	t_col	*tmp_col;
	t_link	*tmp_link;
	int		cols;

	if (!link || !(*(env->grid)))
		return (0);
	tmp_col = *(env->grid);
	tmp_link = link;
	while (tmp_link)
	{
		cols = count_cols(env->grid);
		while (cols)
		{
			if (tmp_col->id == (tmp_link->col)->id)
				break ;
			tmp_col = tmp_col->r;
			--cols;
		}
		if (tmp_col->id != (tmp_link->col)->id)
			return (0);
		tmp_link = tmp_link->r;
	}
	return (!already_chosen(link->id, solution, ft_exp(env->grid_size, 2)));
}

void		undo_unlink(t_link *link, t_env *env, char *solution)
{
	t_link	*tmp;

	tmp = link;
	while (tmp->l)
		tmp = tmp->l;
	while (tmp)
	{
		relink_col(tmp->col, env->grid);
		tmp = tmp->r;
	}
	while ((tmp = pop_link(env->unlinked_links)))
	{
		if (tmp->row == link->row || !relinkable(tmp, env, solution))
			break ;
		else
		{
			while (tmp)
			{
				relink_link(tmp);
				tmp = tmp->r;
			}
		}
	}
	if (tmp)
		push_link(tmp, env->unlinked_links);
}
