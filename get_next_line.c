/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clados-s <clados-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 13:41:07 by clados-s          #+#    #+#             */
/*   Updated: 2025/08/13 16:06:04 by clados-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buffer;
	int			bytes_buffer;
	static char	*rest;
	char		*line;
	
	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_calloc(sizeof(char), BUFFER_SIZE);
	if (!rest)
		rest = ft_calloc(sizeof(char), 1);
	bytes_buffer = 1;
	while (!ft_strchar(rest, '\n') && bytes_buffer > 0)
	{
		bytes_buffer = read(fd, buffer, BUFFER_SIZE);
		if (bytes_buffer == -1)
		{
			free_null(rest);
			return (free_null(buffer));
		}
		buffer[bytes_buffer] = '\0';
		rest = ft_strjoin_and_free(rest, buffer);
	}
	line = pickup_line(rest);
	rest = update_rest(rest, line);
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
	
	if (!rest || *rest == 0)
		return(NULL);
	i = 0;
	while (rest[i] && rest[i] != '\n')
		i++;
	new_line = ft_calloc(sizeof(char), (i + 2));
	i = -1;
	while (rest[++i] && rest[i] != '\n')
		new_line[i] = rest[i];
	if (rest[i] == '\n')
		new_line[i] = rest[i];
	return (new_line);
}

char	*update_rest(char *rest, char *line)
{
	char	*new_rest;
	int		i;
	int		j;
	
	if (!line || !rest)
	{
		if (rest)
			free_null(rest);
		return (free_null(line));
	}
	i = ft_strlen(line);
	new_rest = ft_calloc(sizeof(char), (ft_strlen(rest) - i) + 1);
	j = 0;
	while (rest[i])
		new_rest[j++] = rest[i++];
	free(rest);
	return (new_rest);
}
