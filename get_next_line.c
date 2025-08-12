/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clados-s <clados-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 10:21:36 by clados-s          #+#    #+#             */
/*   Updated: 2025/08/12 17:35:15 by clados-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*buffer;
	int			bytes_buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!rest)
		rest = ft_calloc(1,1);
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
		buffer[bytes_buffer] = '\0';
		rest = ft_strjoin(rest, buffer);
	}
	line = get_line(rest);
	rest = updated_rest(rest);
	free(buffer);
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
	new_line = ft_calloc(sizeof(char), (i + 1));
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
	return (new_line);
}

char	*updated_rest(char *rest)
{
	int		i;
	int		j;
	char	*new_rest;

	if (!rest)
		return (NULL);
	i = 0;
	while (rest[i] && rest[i] != '\n')
		i++;
	if (rest[i] == '\n')
		i++;
	new_rest = ft_calloc(sizeof(char), (ft_strlen(rest) - i + 2));
	if (!rest)
	{
		free(new_rest);
		return (NULL);
	}
	j = 0;
	while (rest[i])
		new_rest[j++] = rest[i++];
	free(rest);
	return (new_rest);
}



int main(void)
{
	char fd = open("teste.txt", O_RDONLY);
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));


	close(fd);
	return (0);
}