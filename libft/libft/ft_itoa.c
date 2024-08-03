/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vejurick <vejurick@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 22:46:56 by vjuricko          #+#    #+#             */
/*   Updated: 2023/09/19 13:51:31 by vejurick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	len(int n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (n == 0)
		return (1);
	if (n == INT_MIN)
		return (11);
	if (n < 0)
	{
		n = n * -1;
		j = 1;
	}
	while (n >= 1)
	{
		n = (n / 10);
		i++;
	}
	return (i + j);
}

static char	*handle_int_min(char *res)
{
	res[0] = '-';
	res[1] = '2';
	res[2] = '1';
	res[3] = '4';
	res[4] = '7';
	res[5] = '4';
	res[6] = '8';
	res[7] = '3';
	res[8] = '6';
	res[9] = '4';
	res[10] = '8';
	return (res);
}

char	*ft_itoa(int n)
{
	size_t	lenght;
	size_t	i;
	char	*res;

	lenght = len(n);
	res = (char *)malloc(lenght + 1);
	if (!res)
		return (0);
	i = 0;
	res[lenght] = '\0';
	if (n == INT_MIN)
		return (handle_int_min(res));
	if (n < 0)
	{
		res[0] = '-';
		i = 1;
		n = n * -1;
	}
	while (lenght > i)
	{
		lenght--;
		res[lenght] = '0' + n % 10;
		n = n / 10;
	}
	return (res);
}
