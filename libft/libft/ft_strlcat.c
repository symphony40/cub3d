/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vejurick <vejurick@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 13:35:23 by vejurick          #+#    #+#             */
/*   Updated: 2023/09/17 17:57:58 by vejurick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dst_length;
	size_t	src_length;

	if (!dst || !src)
		return (0);
	dst_length = ft_strlen(dst);
	src_length = ft_strlen(src);
	j = dst_length;
	i = 0;
	if (size == 0)
		return (src_length);
	if (dst_length >= size)
		return (size + src_length);
	while (src[i] && dst_length + i < size - 1)
	{
		dst[j] = src[i];
		j++;
		i++;
	}
	dst[j] = '\0';
	return (dst_length + src_length);
}

// int main ()
// {
// 	char dst[] = "asdf";
// 	char src[] = "qwerw";

// 	char *s = src;
// 	char *d = dst;
// 	printf("%zu\n", ft_strlcat(dst, src, -1));
// 	printf("%s", dst);
// 	return (0);
// }