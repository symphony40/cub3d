/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vejurick <vejurick@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 13:28:13 by vejurick          #+#    #+#             */
/*   Updated: 2023/09/17 17:58:21 by vejurick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, int n)
{
	char	*csrc;
	char	*cdest;

	if (!dst || !src)
		return (0);
	csrc = (char *)src;
	cdest = (char *)dst;
	if (csrc < cdest)
	{
		while (n--)
			*(cdest + n) = *(csrc + n);
		return (dst);
	}
	while (n--)
		*cdest++ = *csrc++;
	return (dst);
}
