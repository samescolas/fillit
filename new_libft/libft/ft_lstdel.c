/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 15:55:07 by sescolas          #+#    #+#             */
/*   Updated: 2017/01/20 10:28:08 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*node;

	node = *alst;
	while ((*alst)->next)
	{
		node = (*alst)->next;
		ft_lstdelone(alst, del);
		*alst = node;
	}
	ft_lstdelone(alst, del);
}
