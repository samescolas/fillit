/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 12:30:59 by sescolas          #+#    #+#             */
/*   Updated: 2017/01/17 15:59:49 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int	chars_left;
	int	len_little;

	chars_left = ft_strlen((char *)big);
	len_little = ft_strlen((char *)little);
	while (chars_left >= len_little)
	{
		if (!strncmp(big, little, len_little))
			return ((char *)big);
		big++;
		--chars_left;
	}
	return (NULL);
}
