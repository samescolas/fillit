/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 12:21:07 by sescolas          #+#    #+#             */
/*   Updated: 2017/01/22 15:11:56 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char *new_str;
	char *ret_str;

	if (!s || len > (ft_strlen((char *)s) - start))
		return (NULL);
	new_str = ft_strnew((len));
	if (!new_str)
		return (NULL);
	ret_str = new_str;
	while (len > 0)
	{
		*new_str++ = s[start++];
		len--;
	}
	*new_str = '\0';
	return (ret_str);
}
