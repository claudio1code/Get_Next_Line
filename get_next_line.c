/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clados-s <clados-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 10:21:36 by clados-s          #+#    #+#             */
/*   Updated: 2025/08/08 16:00:39 by clados-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*buffer;
	char		*line;
	ssize_t		byte_buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (ft_strchar(rest, '\n') && byte_buffer > 0)
	{
		byte_buffer = read(fd, buffer, BUFFER_SIZE);
		if (byte_buffer == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[byte_buffer] = '\0';
		rest = ft_strjoin_free(rest, buffer);
	}
	free(buffer);
	line = get_line(rest);
	rest = updated_rest(rest);
	return (line);
}

char	*get_line(char *rest)
{
	char	*line;
	int		i;

	i = 0;
	if (!rest[i])
		return (NULL);
	while (rest[i] && rest[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = -1;
	while (rest[++i] && rest[i] != '\n')
		line[i] = rest[i];
	if (rest[i] == '\n')
		line[i++] = '\n';
	line[i++] = '\0';
	return (line);
}

char	*updated_rest(char *rest)
{
	char	*new_rest;
	int		i;
	int		j;

	if (!rest)
		return (NULL);
	i = 0;
	while (rest[i] && rest[i] != '\n')
		i++;
	if (!rest)
	{
		free(rest);
		return (NULL);
	}
	new_rest = (char *)malloc(sizeof(char) * ft_strlen(rest) - i + 1);
	if (!new_rest)
		return (NULL);
	i++;
	j = 0;
	while (rest[i])
		new_rest[j++] = rest[i++];
	new_rest[j] = '\0';
	free(rest);
	return (new_rest);
}

int main(void)
{
	int fd = open("teste.txt", O_RDONLY);

	printf("%s", get_next_line(fd));
	return (0);
}
