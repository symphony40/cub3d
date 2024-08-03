/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vejurick <vejurick@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 15:56:10 by vjuricko          #+#    #+#             */
/*   Updated: 2023/10/21 11:48:07 by vejurick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	pointer_len(unsigned long long i)
{
	int	len;

	len = 0;
	if (i == 0)
		len = 1;
	while (i != 0)
	{
		len ++;
		i = i / 16;
	}
	return (len);
}

int	pointer_putter(unsigned long long i)
{
	if (i == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (i >= 16)
	{
		pointer_putter(i / 16);
		pointer_putter(i % 16);
	}
	else
	{
		if (i <= 9)
			ft_putchar(i + '0');
		else
			ft_putchar(i + 87);
	}
	return (0);
}

int	handle_p(unsigned long long i)
{
	int	len;

	if (i != 0)
	{
		len = pointer_len(i);
		len += write(1, "0x", 2);
		pointer_putter(i);
	}
	else
	{
		write(1, "(nil)", 5);
		len = 5;
	}
	return (len);
}
