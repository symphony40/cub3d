/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vejurick <vejurick@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 13:35:44 by vejurick          #+#    #+#             */
/*   Updated: 2023/09/19 13:39:06 by vejurick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	char	*s1t;

	i = 0;
	s1t = (char *)s1;
	if (!s2 || !s2[0] || !s1)
	{
		return (s1t);
	}
	while (s1t[i] && i < n)
	{
		j = 0;
		while (s1t[i + j] && s2[j] && i + j < n && s1t[i + j] == s2[j])
		{
			j++;
		}
		if (!s2[j])
		{
			return (s1t + i);
		}
		i++;
	}
	return (0);
}
