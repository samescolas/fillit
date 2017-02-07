/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   relink.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 15:47:37 by sescolas          #+#    #+#             */
/*   Updated: 2017/02/06 18:48:21 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	relinkable(t_link *link, t_env *env, char *solution)
{
	unsigned int	i;
	t_link			*tmp;
	t_col			*col;

	i = 0;
	while (i < env->grid_size)
		if (solution[i++] == (char)(link->id))
			return (0);
	tmp = link;
	while (tmp->l)
		tmp = tmp->l;
	while (tmp)
	{
		col = *(env->grid);
		while (col)
		{
			printf("relinkable\n");
			if (col->id == (tmp->col)->id)
				break ;
			col = col->r;
		}
		if (!col)
			return (0);
		tmp = tmp->r;
		printf("relinkable2\n");
	}
	return (1);
}

static void	ununlink(t_link *link, t_link *prev, t_link **list)
{
	if (!prev && !(link->next_unlinked))
	{
		*list = (void *)0;
		return ;
	}
	if (!prev)
		*list = link->next_unlinked;
	else
		prev->next_unlinked = link->next_unlinked;
	link->next_unlinked = NULL;
}

static void	relink_link(t_link *link, t_link *prev, t_link **list)
{
	if (link->u)
		(link->u)->d = link;
	else
		(link->col)->d = link;
	if (link->d)
		(link->d)->u = link;
	ununlink(link, prev, list);
	++((link->col)->size);
}

static void	relink_links(char *solution, t_env *env)
{
	t_link	*tmp;
	t_link	*link;
	t_link	*prev;

	printf("calling relink_links\n");
	prev = (void *)0;
	if (!*(env->unlinked_links))
		return ;
	tmp = *(env->unlinked_links);
	while (tmp)
	{
		if (relinkable(tmp, env, solution))
		{
			link = tmp;
			while (link->l)
				link = link->l;
			while (link)
			{
				relink_link(link, prev, env->unlinked_links);
				link = link->r;
				printf("relink_links\n");
			}
		}
		printf("relink_links2\n");
		prev = tmp;
		tmp = tmp->next_unlinked;
	}
}

static int	col_count(t_col **grid)
{
	t_col	*col;
	int		len;

	if (!*grid)
		return (0);
	len = 0;
	col = *grid;
	while (col)
	{
		++len;
		col = col->r;
	}
	return (len);
}

void		relink_tet(t_link *link, t_env *env, char *solution)
{
	t_link	*tmp;

	tmp = link;
	while (tmp->l)
		tmp = tmp->l;
	while (tmp)
	{
		printf("relink_tet %d\n", tmp->id);
		printf("col count: %d\n", col_count(env->grid));
		for (int i = 0; i < 10000000; i++);
		if (!((tmp->col)->l) && !((tmp->col)->r))
			*(env->grid) = tmp->col;
		else 
		{
			if (!((tmp->col)->l))
			{
				printf("here\n");
				*(env->grid) = tmp->col;
			}
			else
				((tmp->col)->l)->r = tmp->col;
			if ((tmp->col)->r)
				((tmp->col)->r)->l = tmp->col;
		}
		tmp = tmp->r;
	}
	relink_links(solution,  env);
}
