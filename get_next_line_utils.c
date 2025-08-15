/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clados-s <clados-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 13:46:12 by clados-s          #+#    #+#             */
/*   Updated: 2025/08/15 11:44:11 by clados-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total_size;

	if (nmemb && size && nmemb != (nmemb * size) / size)
		return (NULL);
	total_size = nmemb * size;
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, total_size);
	return (ptr);
}

char	*ft_memset(void *s, char c, size_t size)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (size-- > 0)
		*ptr++ = c;
	return (s);
}

char	*ft_strchar(char *str, char c)
{
	int	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin_and_free_rest(char *rest, char *buffer)
{
	char	*new_str;
	int		len_newstr;
	int		i;
	int		j;

	if (!rest)
		rest = ft_calloc(sizeof(char), 1);
	if (!buffer)
		return (rest);
	len_newstr = ft_strlen(rest) + ft_strlen(buffer);
	new_str = ft_calloc(sizeof(char), len_newstr + 1);
	if (!new_str)
		return (free_null(rest));
	i = -1;
	while (rest[++i])
		new_str[i] = rest[i];
	j = -1;
	while (buffer[++j])
		new_str[j + i] = buffer[j];
	free(rest);
	return (new_str);
}

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}
