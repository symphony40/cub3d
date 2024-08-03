/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vejurick <vejurick@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 13:34:57 by vejurick          #+#    #+#             */
/*   Updated: 2023/09/19 14:26:33 by vejurick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*word_dup(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	if (!word)
		return (0);
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

static int	word_count(const char *str, char c)
{
	int	i;
	int	next;

	i = 0;
	next = 0;
	while (*str)
	{
		if (*str != c && next == 0)
		{
			next = 1;
			i++;
		}
		else if (*str == c)
			next = 0;
		str++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		k;
	char	**split;

	split = malloc((word_count(s, c) + 1) * sizeof(char *));
	if (!s || !split)
		return (0);
	i = 0;
	j = 0;
	k = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && k < 0)
			k = i;
		else if ((s[i] == c || i == ft_strlen(s)) && k >= 0)
		{
			split[j++] = word_dup(s, k, i);
			k = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}
