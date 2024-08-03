/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vejurick <vejurick@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 23:47:01 by vjuricko          #+#    #+#             */
/*   Updated: 2023/10/21 11:47:13 by vejurick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	handle_fmt(va_list args, const char format)
{
	int			len;

	len = 0;
	if (format == 's')
		len += handle_s(args, len);
	else if (format == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (format == '%')
		len += ft_putchar('%');
	else if (format == 'i' || format == 'd')
		len += handle_i(va_arg(args, int));
	else if (format == 'p')
		len += handle_p(va_arg(args, unsigned long long));
	else if (format == 'u')
		len += handle_u(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		len += handle_x(va_arg(args, int), format);
	return (len);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		i;
	int		len;

	len = 0;
	i = 0;
	va_start(args, fmt);
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			len += handle_fmt(args, fmt[i +1]);
			i++;
			i++;
		}
		else
		{
			len += ft_putchar(fmt[i]);
			i++;
		}
	}
	va_end(args);
	return (len);
}

// int	main (void)
// {	
// 	ft_printf("%p \n", 0);
// 	printf("%p", 0);
// 	return (0);
// }
