/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clados-s <clados-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 10:21:54 by clados-s          #+#    #+#             */
/*   Updated: 2025/08/08 14:46:04 by clados-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin_free(char *rest, char *buffer)
{
	char	*new_str;
	int		i;
	int		j;
	int		len;
	
	len = ft_strlen(rest) + ft_strlen(buffer);
	new_str = malloc(len + 1 * sizeof(char));
	if (!new_str)
		return (0);
	i = -1;
	j = -1;
	while (rest[i++])
		new_str[i] = rest[i];
	while (buffer[j++])
		new_str[i + j] = buffer[j];
	new_str[i + j] = '\0';
	free(rest);
	return (new_str);
}

char	*ft_strchar(char *str, int c)
{
	int	i;
	
	i = 0;
	while (str[i] && (unsigned char)str[i] != (unsigned char)c)
		i++;
	if (str[i] && (unsigned char)str[i] != (unsigned char)c)
		return (NULL);
	return ((char *)&str[i]);
}

char	*ft_strdup(char *str)
{
	int		len;
	char	*dup;
	int		i;

	len = ft_strlen(str + 1);
	dup = (char *)malloc(len);
	if (!dup)
		return (NULL);
	i = -1;
	while (str[++i])
		dup[i] = str[i];
	dup[i] = '\0';
	return (dup);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;
	size_t	cpy_len;
	size_t	s_len;
	
	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (malloc(1 * sizeof(char)));
	if (s_len - start < len)
		cpy_len = s_len - start;
	else
		cpy_len = len;
	sub = (char *)malloc(cpy_len + 1);
	if (!sub)
		return (NULL);
	i = 0;
	while (i < cpy_len)
	{
		sub[i] = s[i + start];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

