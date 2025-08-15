/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clados-s <clados-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 14:27:29 by clados-s          #+#    #+#             */
/*   Updated: 2025/08/15 15:43:51 by clados-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char		*buffer;
	int			bytes_buffer;
	static char	*rest[MAX_FD];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= MAX_FD)
		return (NULL);
	buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	bytes_buffer = 1;
	while (!ft_strchar(rest[fd], '\n') && bytes_buffer > 0)
	{
		bytes_buffer = read(fd, buffer, BUFFER_SIZE);
		if (bytes_buffer == -1)
			return (free(buffer), rest[fd] = free_null(rest[fd]));
		buffer[bytes_buffer] = '\0';
		rest[fd] = ft_strjoin_and_free_rest(rest[fd], buffer);
		if (!rest[fd])
			return (NULL);
	}
	free(buffer);
	line = pickup_line(rest[fd]);
	rest[fd] = update_rest(rest[fd]);
	return (line);
}

void	*free_null(void *ptr)
{
	if (ptr)
		free(ptr);
	return (NULL);
}

char	*pickup_line(char *rest)
{
	char	*new_line;
	int		i;

	if (!rest || *rest == '\0')
		return (NULL);
	i = 0;
	while (rest[i] && rest[i] != '\n')
		i++;
	if (rest[i] == '\n')
		i++;
	new_line = ft_calloc(sizeof(char), (i + 1));
	i = 0;
	while (rest[i] && rest[i] != '\n')
	{
		new_line[i] = rest[i];
		i++;
	}
	if (rest[i] == '\n')
		new_line[i] = rest[i];
	return (new_line);
}

char	*update_rest(char *rest)
{
	char	*new_rest;
	int		i;
	int		j;

	if (!rest)
		return (NULL);
	i = 0;
	while (rest[i] && rest[i] != '\n')
		i++;
	if (!rest[i])
		return (free_null(rest));
	i++;
	new_rest = ft_calloc(sizeof(char), ft_strlen(rest) - i + 1);
	if (!new_rest)
		return (free_null(rest));
	j = 0;
	while (rest[i])
		new_rest[j++] = rest[i++];
	free(rest);
	return (new_rest);
}
