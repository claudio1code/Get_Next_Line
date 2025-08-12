/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clados-s <clados-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 10:21:54 by clados-s          #+#    #+#             */
/*   Updated: 2025/08/12 14:43:50 by clados-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchar(char *s, int c)
{
	int	i;

	if (!s || !s[0])
		return (NULL);
	i = 0;
	while ((unsigned char)s[i] && (unsigned char)s[i] != (unsigned char)c)
		i++;
	if ((unsigned char)s[i] != (unsigned char)c)
		return (NULL);
	return ((char *)&s[i]);
}

char	*ft_strjoin(char *rest, char *buffer)
{
	char	*new_str;
	int		i;
	int		j;
	int		len_new;
	
	len_new = ft_strlen(rest) + ft_strlen(buffer);
	new_str = ft_calloc(sizeof(char), (len_new + 1));
	if (!new_str)
		return (NULL);
	i = -1;
	while (rest[++i])
		new_str[i] = rest[i];
	j = -1;
	while (buffer[++j])
		new_str[i + j] = buffer[j];
	// printf("\n%s\n", new_str);
	return (new_str);
}
// char	*ft_strdup(char *rest)
// {
// 	int		i;
// 	char	*new_str;
	
// 	if (!rest)
// 		return (NULL);
// 	new_str = malloc(sizeof(char) * ft_strlen(rest) + 1);
// 	if (!new_str)
// 		return (NULL);
// 	i = -1;
// 	while (rest[++i])
// 		new_str[i] = rest[i];
// 	new_str[i] = '\0';
// 	return (new_str);
// }

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	tt_size;

	if (nmemb == 0 || size == 0)
		ft_calloc(1,1);
	if (nmemb && size && nmemb != (nmemb * size) / size)
		return (NULL);
	tt_size = nmemb * size;
	ptr = malloc(sizeof(char) * tt_size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, size);
	return (ptr);
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	character;
	
	ptr = (unsigned char *)s;
	character = (unsigned char)c;
	while (n-- > 0)
		*ptr++ = c;
	return (s);
}
