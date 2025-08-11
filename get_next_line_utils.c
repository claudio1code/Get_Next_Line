/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clados-s <clados-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 10:21:54 by clados-s          #+#    #+#             */
/*   Updated: 2025/08/11 16:28:25 by clados-s         ###   ########.fr       */
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

char	*ft_strchar(char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while ((unsigned char)s[i] && (unsigned char)s[i] != (unsigned char)c)
		i++;
	if ((unsigned char)s[i] && (unsigned char)s[i] != (unsigned char)c)
		return (NULL);
	return ((char *)&s[i]);
}

char	*ft_strjoin_free(char *rest, char *buffer)
{
	char	*new_str;
	int		i;
	int		j;
	int		len_new;
	
	len_new = ft_strlen(rest) + ft_strlen(buffer);
	new_str = malloc(sizeof(char) * (len_new + 1));
	if (!new_str)
		return (NULL);
	i = -1;
	while (rest[++i])
		new_str[i] = rest[i];
	j = -1;
	while (buffer[++j])
		new_str[i + j] = buffer[j];
	new_str[i + j] = '\0';
	free(rest);
	return (new_str);
}
char	*ft_strdup(char *rest)
{
	int		i;
	char	*new_str;
	
	if (!rest)
		return (NULL);
	new_str = malloc(sizeof(char) * ft_strlen(rest) + 1);
	if (!new_str)
		return (NULL);
	i = -1;
	while (rest[++i])
		new_str[i] = rest[i];
	new_str[i] = '\0';
	return (new_str);
}


