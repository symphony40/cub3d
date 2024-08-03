/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjuricko <vjuricko@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 19:25:10 by vjuricko          #+#    #+#             */
/*   Updated: 2022/03/02 21:45:00 by vjuricko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	handle_s(va_list args, int len)
{
	const char	*s;

	s = va_arg(args, const char *);
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (*s)
	{
		len += ft_putchar(*s++);
	}
	return (len);
}
