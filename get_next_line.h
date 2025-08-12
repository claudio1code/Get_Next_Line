/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clados-s <clados-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 10:24:22 by clados-s          #+#    #+#             */
/*   Updated: 2025/08/12 16:12:07 by clados-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include<stdlib.h>
# include<unistd.h>
# include<fcntl.h>
# include<stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
int		ft_strlen(char *str);
char	*ft_strjoin(char *rest, char *buffer);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memset(void *s, int c, size_t n);
// char	*ft_strdup(char *str);
char	*ft_strchar(char *str, int c);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strjoin(char *rest, char *buffer);
char	*updated_rest(char *rest);
char	*get_line(char *rest);

#endif