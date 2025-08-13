/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clados-s <clados-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 13:46:12 by clados-s          #+#    #+#             */
/*   Updated: 2025/08/13 16:05:45 by clados-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total_size;

	if (nmemb == 0 && size == 0)
		ptr = malloc(1 * 1);
	if (nmemb && size && nmemb != (nmemb * size) / size)
		return (NULL);
	total_size = nmemb * size;
	ptr = malloc(sizeof(char) * total_size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, size);
	return (ptr);
}

char	*ft_memset(char *s, char c, size_t size)
{
	while (size-- > 0)
		*s++ = c;
	return (s);
}

char	*ft_strchar(char *str, char c)
{
	int	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] && str[i] != c)
		return (NULL);
	return (&str[i]);
}

char	*ft_strjoin_and_free(char *rest, char *buffer)
{
	char	*new_str;
	int		len_newstr;
	int		i;
	int		j;
	
	if (!rest && !buffer)
		return (NULL);
	len_newstr = ft_strlen(rest) + ft_strlen(buffer);
	new_str = calloc(sizeof(char), len_newstr + 1);
	i = -1;
	while (rest[++i])
		new_str[i] = rest[i];
	free(rest);
	j = -1;
	while (buffer[++j])
		new_str[j + i] = buffer[j];
	free(buffer);
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
