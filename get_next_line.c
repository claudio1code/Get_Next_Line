/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clados-s <clados-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 10:21:36 by clados-s          #+#    #+#             */
/*   Updated: 2025/08/06 15:07:57 by clados-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*old_buf;
	char		*temp;
	
	if (fd < 0)
		return (NULL);
	old_buf = buffer;
	temp = ft_strjoin(old_buf, buffer);
	if (!temp)
		return (NULL);	
}