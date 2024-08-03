/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vejurick <vejurick@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 13:36:03 by vejurick          #+#    #+#             */
/*   Updated: 2023/09/19 13:58:01 by vejurick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen_szt(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	j = 0;
	i = start;
	if (!s)
		return (0);
	while (i < ft_strlen_szt(s) && j < len)
	{
		j++;
		i++;
	}
	new_str = (char *)malloc(j + 1);
	if (!new_str)
		return (0);
	i = start;
	j = 0;
	while (i < ft_strlen_szt(s) && j < len)
		new_str[j++] = s[i++];
	new_str[j] = '\0';
	return (new_str);
}
