/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjuricko <vjuricko@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 13:38:51 by vjuricko          #+#    #+#             */
/*   Updated: 2022/03/02 22:21:03 by vjuricko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	handle_x(unsigned int i, const char format)
{
	if (i == 0)
		return (write(1, "0", 1));
	else
		put_x(i, format);
	return (treat_hex_len(i));
}

void	put_x(unsigned int i, const char format)
{
	if (i >= 16)
	{
		put_x(i / 16, format);
		put_x(i % 16, format);
	}
	else
	{
		if (i < 10)
			ft_putchar(i + '0');
		else
		{
			if (format == 'x')
				ft_putchar(i + 87);
			if (format == 'X')
				ft_putchar(i + 55);
		}
	}
}

int	treat_hex_len(unsigned int i)
{
	int	len;

	len = 0;
	while (i != 0)
	{
		len++;
		i = i / 16;
	}
	return (len);
}
