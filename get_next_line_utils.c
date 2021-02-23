/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcruz <pcruz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 17:43:24 by pcruz             #+#    #+#             */
/*   Updated: 2021/02/23 16:45:11 by pcruz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t  ft_strlen(const char *str)
{
    size_t  i;

    i = 0;
    while (str[i])
    {
        i++;
    }
    return (i);
}

void    *ft_memset(void *str, int c, size_t n)
{
    unsigned char *us;

    us = (unsigned char *)str;
    while (n-- != 0)
        *(us++) = (unsigned char)c;
    return (str);
}

void    *ft_memalloc(size_t size)
{
    void    *str;

    str = malloc(size);
    if (str == NULL)
        return (NULL);
    ft_memset(str, 0, size);
    return (str);
}

char    *ft_strnew(size_t size)
{
    return (ft_memalloc((size + 1) * sizeof(char)));
}

int     ft_memdel(void **str)
{
    if (*str)
    {
        ft_memset(*str, 0, ft_strlen(*str));
        free(*str);
        *str = NULL;
        return (1);
    }
    return (0);
}
