/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcruz <pcruz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 17:43:28 by pcruz             #+#    #+#             */
/*   Updated: 2021/02/22 11:21:48 by pcruz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE
# endif

char    *ft_strchr(const char *s, int c);
char    *ft_strjoin(char const *s1, char const *s2);
char    *ft_substr(char const *s, unsigned int start, size_t len);
char    *ft_strdup(const char *s1);
size_t  ft_strlen(const char *str);
char    *ft_strnew(size_t size);
void    *ft_memalloc(size_t size);
void    *ft_memset(void *str, int c, size_t n);
int     ft_memdel(void **str);
int     get_next_line(int fd, char **line);

#endif
