/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vejurick <vejurick@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:58:27 by vejurick          #+#    #+#             */
/*   Updated: 2024/01/31 14:37:53 by vejurick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

static char	*read_and_set_aside(int fd, char *stash)
{
	char	*buffer;
	int		have_read;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	have_read = 1;
	while (have_read > 0)
	{
		have_read = read(fd, buffer, BUFFER_SIZE);
		if (have_read == -1)
		{
			free(buffer);
			return (0);
		}
		buffer[have_read] = '\0';
		stash = ft_strjoinn(stash, buffer);
		if (ft_strchrr(stash, '\n'))
			break ;
	}
	free(buffer);
	return (stash);
}

static char	*print_out_line(char *stash)
{
	int		i;
	char	*line;

	i = 0;
	if (!stash[i])
		return (0);
	while (stash[i] != '\n' && stash[i])
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] != '\n' && stash[i])
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*clean_up(char *stash)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	new = malloc(sizeof(char) * (ft_strlenn(stash) - i + 1));
	if (!new)
		return (NULL);
	i++;
	while (stash[i])
		new[j++] = stash[i++];
	new[j] = '\0';
	free(stash);
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	stash = read_and_set_aside(fd, stash);
	if (!stash)
		return (0);
	line = print_out_line(stash);
	stash = clean_up(stash);
	return (line);
}
