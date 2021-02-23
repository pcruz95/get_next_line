/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcruz <pcruz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 17:42:33 by pcruz             #+#    #+#             */
/*   Updated: 2021/02/22 11:48:20 by pcruz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *ft_strdup(const char *s1)
{
    char    *new;
    ssize_t i;

    new = ft_strnew(ft_strlen(s1));
    if (new == NULL)
        return (NULL);
    i = -1;
    while (s1[++i])
        new[i] = s1[i];
    return (new);
}

char    *ft_strchr(const char *s, int c)
{
    unsigned char   cc;

    cc = (unsigned char)c;
    while (*s)
    {
        if (*s == cc)
            return ((char *)s);
        s++;
    }
    if (c == '\0')
        return ((char *)s);
    return (NULL);
}

char    *ft_strjoin(char const *s1, char const *s2)
{
    size_t  ln_s1;
    size_t  ln_s2;
    char    *s3;

    if (!s1 || !s2)
        return (NULL);
    ln_s1 = ft_strlen(s1);
    ln_s2 = ft_strlen(s2);
    s3 = malloc(sizeof(char) * (ln_s1 + ln_s2 + 1));
    if (s3 == NULL)
        return (NULL);
    while (*s1)
        *(s3++) = *(s1++);
    while (*s2)
        *(s3++) = *(s2++);
    *s3 = '\0';
    return (s3 - (ln_s1 + ln_s2));
}

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    size_t  i;
    char    *str;

    i = 0;
    if (!s || (long int)len < 0)
        return (NULL);
    str = (char *)malloc(len + 1);
    if (str == NULL)
        return (NULL);
    while (start < ft_strlen(s) && i < len)
    {
        str[i] = s[start];
        i++;
        start++;
    }
    str[i] = '\0';
    return (str);
}

int     get_next_line(int fd, char **line)
{
    ssize_t     r;
    char        bf[BUFFER_SIZE + (r = 1)];
    static char *c_line = NULL;
    char        *tmp;

    if (fd < 0 || !line || BUFFER_SIZE <= 0)
        return (-1);
    c_line == NULL ? c_line = ft_strnew(0) : NULL;
    while (!ft_strchr(c_line, '\n') && (r = read(fd, bf, BUFFER_SIZE)) > 0)
    {
        bf[r] = '\0';
        tmp = ft_strjoin(c_line, bf);
        ft_memdel((void **)&c_line);
        c_line = tmp;
    }
    if (r == 0)
        *line = ft_strdup(c_line);
    else if (r > 0)
        *line = ft_substr(c_line, 0, (ft_strchr(c_line, '\n') - c_line));
    else
        return (-1);
    tmp = ft_strdup(c_line + (ft_strlen(*line) + ((r > 0) ? +1 : +0)));
    ft_memdel((void **)&c_line);
    c_line = tmp;
    return (r == 0 ? 0 * ft_memdel((void **)&c_line) : 1);
}













