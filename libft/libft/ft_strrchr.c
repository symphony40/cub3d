/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vejurick <vejurick@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 13:35:50 by vejurick          #+#    #+#             */
/*   Updated: 2023/09/19 14:36:46 by vejurick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	ch;
	char	*str;
	char	*res;

	i = 0;
	res = 0;
	ch = (char)c;
	str = (char *)s;
	if (ch == 0)
		return (str + ft_strlen(s));
	while (str[i])
	{
		if (str[i] == ch)
			res = &str[i];
		i++;
	}
	return (res);
}
