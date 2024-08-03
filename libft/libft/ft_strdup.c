/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vejurick <vejurick@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 13:35:11 by vejurick          #+#    #+#             */
/*   Updated: 2023/09/19 13:51:43 by vejurick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	len;

	if (!s)
		return (0);
	len = ft_strlen(s) + 1;
	ptr = malloc(sizeof(char) * len);
	if (!ptr)
		return (0);
	ptr = ft_memcpy(ptr, s, len);
	return (ptr);
}
