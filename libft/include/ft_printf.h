/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjuricko <vjuricko@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 21:54:24 by vjuricko          #+#    #+#             */
/*   Updated: 2022/03/02 22:02:33 by vjuricko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>

int		ft_printf(const char *format, ...);
int		handle_s(va_list args, int len);
int		ft_putchar(char c);
int		handle_fmt(va_list args, const char format);
int		handle_c(va_list args, int len);
int		handle_i(int i);
int		print_i(char *res);
int		handle_x(unsigned int i, const char format);
int		treat_hex_len(unsigned int i);
int		handle_p(unsigned long long i);
int		pointer_len(unsigned long long i);
int		pointer_putter(unsigned long long i);
int		handle_u(unsigned int n);
void	put_x(unsigned int i, const char format);
char	*unsigned_putter(unsigned int n);
size_t	u_len(unsigned int n);
size_t	len(int n);
char	*ft_itoa(int n);

#endif