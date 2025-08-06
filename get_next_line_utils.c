/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clados-s <clados-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 10:21:54 by clados-s          #+#    #+#             */
/*   Updated: 2025/08/06 15:01:56 by clados-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str)
		i++;
	return (i);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*new_str;
	int		i;
	int		j;
	int		len;
	
	len = ft_strlen(s1) + ft_strlen(s2);
	new_str = malloc(len + 1 * sizeof(char));
	if (!new_str)
		return (0);
	i = -1;
	j = -1;
	while (s1[i++])
		new_str[i] = s1[i];
	while (s2[j++])
		new_str[i + j] = s2[j];
	new_str[i + j] = '\0';
	free(s1);
	s1 = NULL;
	return (new_str);
}

