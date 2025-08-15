/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clados-s <clados-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 13:47:00 by clados-s          #+#    #+#             */
/*   Updated: 2025/08/15 11:24:13 by clados-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_memset(void *s, char c, size_t size);
char	*ft_strchar(char *str, char c);
void	*free_null(void *ptr);
int		ft_strlen(char *str);
char	*ft_strjoin_and_free_rest(char *rest, char *buffer);
char	*update_rest(char *rest);
char	*pickup_line(char *rest);

#endif