/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 14:31:00 by sescolas          #+#    #+#             */
/*   Updated: 2017/02/05 17:29:49 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		*get_next_permutation(int *arr, int size)
{
	int		i;
	int		j;
	int		tmp;

	i = size - 1;
	while (i > 0 && arr[i - 1] >= arr[i])
		i--;
	if (i <= 0)
		return ((void *)0);
	j = size - 1;
	while (arr[j] <= arr[i - 1])
		j--;
	tmp = arr[i - 1];
	arr[i - 1] = arr[j];
	arr[j] = tmp;
	j = size - 1;
	while (i < j)
	{
		tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
		i++;
		j--;
	}
	return (arr);
}
/*
int		*get_next_permutation(int n)
{
	int		i;
	int		j;
	int		tmp;
	char	*arr;
	int		*ret;

	arr = ft_itoa(n);
	ret = (int *)malloc(ft_strlen(arr) * sizeof(int));
	i = -1;
	while (arr[++i])
		ret[i] = arr[i] - '0';
	i = ft_strlen(arr);;
	while (i > 0 && ret[i - 1] >= ret[i])
		i--;
	if (i <= 0)
		return ((void *)0);
	j = ft_strlen(arr) - 1;
	while (ret[j] <= ret[i - 1])
		j--;
	tmp = ret[i - 1];
	ret[i - 1] = ret[j];
	ret[j] = tmp;
	j = ft_strlen(arr) - 1;
	while (i < j)
	{
		tmp = ret[i];
		ret[i] = ret[j];
		ret[j] = tmp;
		i++;
		j--;
	}
	return (ret);
}
*/
