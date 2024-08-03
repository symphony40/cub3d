/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_i.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vejurick <vejurick@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 18:57:10 by vjuricko          #+#    #+#             */
/*   Updated: 2024/06/26 12:07:53 by vejurick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

size_t	len(int n)
{
	int	i;

	if (n == 0)
		return (1);
	i = 0;
	if (n < 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa2(int n)
{
	size_t	lenght;
	size_t	i;
	char	*res;

	lenght = len(n);
	res = malloc(sizeof(char) * (lenght + 1));
	if (!res)
		return (NULL);
	res[lenght] = '\0';
	i = 0;
	if (n < 0)
	{
		res[0] = '-';
		i = 1;
	}
	while (lenght > i)
	{
		lenght--;
		if (n < 0)
			res[lenght] = '0' + n % 10 * (-1);
		else
			res[lenght] = '0' + n % 10;
		n = n / 10;
	}
	return (res);
}

int	print_i(char *res)
{
	int	i;

	i = 0;
	if (res == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (res[i])
	{
		write(1, &res[i], 1);
		i++;
	}
	return (i);
}

int	handle_i(int i)
{
	int		lenght;
	char	*num;

	lenght = 0;
	num = ft_itoa2(i);
	lenght = print_i(num);
	free(num);
	return (lenght);
}
