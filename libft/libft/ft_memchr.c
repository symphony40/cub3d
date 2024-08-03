/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vejurick <vejurick@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 18:17:15 by vejurick          #+#    #+#             */
/*   Updated: 2023/08/29 12:54:53 by vejurick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int value, size_t num)
{
	size_t	i;

	i = 0;
	while (i < num)
	{
		if (*(unsigned char *)(ptr + i) == (unsigned char) value)
		{
			return ((void *)(ptr + i));
		}
		i++;
	}
	return (0);
}
