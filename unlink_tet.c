/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unlink_tet.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 19:15:54 by sescolas          #+#    #+#             */
/*   Updated: 2017/02/08 23:16:17 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int overlapping(t_link *link1, t_link *link2)
{
	t_link	*tmp1;
	t_link	*tmp2;

	tmp1 = link1;
	while (tmp1->l)
		tmp1 = tmp1->l;
	while (tmp1)
	{
		tmp2 = link2;
		while (tmp2)
		{
			if (tmp1->col == tmp2->col)
				return (1);
			tmp2 = tmp2->r;
		}
		tmp1 = tmp1->r;
	}
	return (0);
}

void	unlink_row(t_link *link, t_env *env)
{
	t_link	*tmp;

	tmp = link;
	while (tmp->l)
		tmp = tmp->l;
	while (tmp)
	{
		unlink_link(tmp, env->unlinked_links);
		tmp = tmp->r;
	}
}

void		unlink_tet(t_link *link, t_env *env)
{
	t_col	*col;
	t_link	*tmp;
	int		num_cols;
	int		num_links;

	printf("entering unlink_tet\n");
	col = *(env->grid);
	if (!(num_cols = count_cols(env->grid)))
		return ;
	printf("looping %d times...\n", num_cols);
	while (num_cols)
	{
		if ((num_links = col->size))
		{
			printf("col: %d has %d/%d link(s)\n", col->id, num_links, col->size);
			tmp = col->d;
			printf("first link..row: %d\tid: %d\n", tmp->row, tmp->id);
			while (num_links > 0)
			{
				printf("num_links: %d\tlink row: %d\tlink id: %d\tcol size: %d\n", num_links, tmp->row, tmp->id, (tmp->col)->size);
				if (tmp->id == link->id || overlapping(tmp, link))
				{
					printf("unlinking row...\nid: %d\trow: %d\tcol: %d\tcol size: %d\n", tmp->id, tmp->row, (tmp->col)->id, (tmp->col)->size);
					unlink_link(tmp, env->unlinked_links);
					printf("unlinked row...\nnew col size: %d\n", (tmp->col)->size);
				}
				--num_links;
				tmp = tmp->d;
			}
		}
		--num_cols;
		printf("going to next column\n");
		col = col->r;
	}
	tmp = link;
	printf("unlinking columns...\n");
	while (tmp)
	{
		printf("unlinking cols\n");
		unlink_col(tmp->col, env->grid);
		tmp = tmp->r;
	}
}
