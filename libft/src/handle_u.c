/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjuricko <vjuricko@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 19:30:28 by vjuricko          #+#    #+#             */
/*   Updated: 2022/03/02 21:46:43 by vjuricko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

size_t	u_len(unsigned int n)
{
	int	i;

	if (n == 0)
		return (1);
	i = 0;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*unsigned_putter(unsigned int n)
{
	size_t	lenght;
	size_t	i;
	char	*res;

	lenght = u_len(n);
	res = malloc(sizeof(char) * (lenght + 1));
	if (!res)
		return (0);
	res[lenght] = '\0';
	i = 0;
	while (lenght > i)
	{
		lenght--;
		res[lenght] = '0' + n % 10;
		n = n / 10;
	}
	lenght = 0;
	while (res[lenght])
	{
		write(1, &res[lenght], 1);
		lenght++;
	}
	return (res);
}

int	handle_u(unsigned int n)
{
	char	*num;

	num = unsigned_putter(n);
	free(num);
	return (u_len(n));
}
