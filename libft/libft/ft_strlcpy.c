/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vejurick <vejurick@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 13:35:31 by vejurick          #+#    #+#             */
/*   Updated: 2023/09/12 12:47:43 by vejurick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!dst || !src)
		return (0);
	while (src[j])
		j++;
	if (len < 0)
		len = j + 1;
	while (i < len - 1 && *src != '\0')
	{
		*dst++ = *src++;
		i++;
	}
	if (len > 0)
		*dst = '\0';
	return (j);
}
