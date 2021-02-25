/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcruz <pcruz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 17:56:35 by pcruz             #+#    #+#             */
/*   Updated: 2021/02/23 16:44:50 by pcruz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>

int		get_next_line(int fd, char **line);
char	*joiner_free(char *s1, char *s2);
int		find_index(const char *s, int c);
int		get_line(char *str, char **line, int i);
char	*ft_substr(char const *s, int start, int len);
void	*ft_memmove(void *dst, const void *src, size_t len);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);

#endif
