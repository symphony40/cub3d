/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vejurick <vejurick@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 17:41:50 by vjuricko          #+#    #+#             */
/*   Updated: 2023/09/19 14:00:40 by vejurick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	s1len;
	size_t	s2len;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	ptr = malloc(sizeof(char) * (s1len + s2len + 1));
	if (!ptr)
		return (0);
	ft_memmove(ptr, s1, s1len);
	ft_memmove(ptr + s1len, s2, s2len);
	ptr[s1len + s2len] = 0;
	return (ptr);
}
