/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clados-s <clados-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 10:21:36 by clados-s          #+#    #+#             */
/*   Updated: 2025/08/11 16:27:48 by clados-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*buffer;
	int			bytes_buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_buffer = 1;
	while (!ft_strchar(rest, '\n') && bytes_buffer > 0)
	{
		bytes_buffer = read(fd, buffer, BUFFER_SIZE);
		if (bytes_buffer == -1)
		{
			free(buffer);
			free(rest);
			return (NULL);
		}
		if (bytes_buffer == 0)
			break ;
		buffer[bytes_buffer] = '\0';
		// printf("\ndebug\n\n");
		rest = ft_strjoin_free(rest, buffer);
	}
	free (buffer);
	if (rest == NULL || rest[0] == '\0')
		return (NULL);
	line = get_line(rest);
	rest = update_rest(rest);
	return (line);
}

char	*get_line(char *rest)
{
	int		i;
	char	*new_line;
	
	if (!rest)
		return (NULL);
	i = 0;
	while (rest[i] && rest[i] != '\n')
		i++;
	new_line = malloc(sizeof(char) * (i + (rest[i] == '\n') + 1));
	if (!new_line)
		return (NULL);
	i = 0;
	while (rest[i] && rest[i] != '\n')
	{	
		new_line[i] = rest[i];
		i++;
	}
	if (rest[i] && rest[i] == '\n')
		new_line[i] = '\n';
	new_line[i++] = '\0';
	return (new_line);
}

char	*update_rest(char *rest)
{
	int		i;
	int		j;
	char	*new_rest;

	if (!rest)
		return (NULL);
	i = 0;
	while (rest[i] && rest[i] != '\0')
		i++;
	if (!rest)
	{
		free(rest);
		return (NULL);
	}
	i++;
	new_rest = malloc(sizeof(char) * (ft_strlen(rest) - i + 1));
	if (!new_rest || !new_rest[i + 1])
	{
		free(rest);
		return (NULL);
	}
	j = 0;
	while (rest[++i])
		new_rest[j++] = rest[i++];
	free(rest);
	return (new_rest);
}
