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

//find index of our '\n'. Return (-1) if we don't find it
int	find_index(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != (char)c)
		i++;
	if (s[i] != (char)c)
		return (-1);
	return (i);
}

int	get_line(char *str, char **line, int i)
{
	int	len;

	*line = ft_substr(str, 0, i);		// Assign to 'line' what is in 'str'. The 'i' is the index of our '\n'
	++i;								// Move index 1 position after '\n'
	len = ft_strlen(str + i) + 1;		// Len of string after first '\n'. +1 to include '\0'
	ft_memmove(str, str + i, len);		// Move what's after the first '\n' to the beginning of 'str'
	return (1);							// Always return (1), we call get_line only if a '\n' was found
}

int	get_next_line(int fd, char **line)
{
	char		buff[BUFFER_SIZE + 1];
	static char	*str;
	int			ret;
	int			i;

	if (!line || fd < 0 || BUFFER_SIZE < 1 || read(fd, buff, 0) < 0)	// Look for basic errors. Read 0 to look for errors without moving our cursor
		return (-1);
	if (str && (((i = find_index(str, '\n')) != -1)))		// If there's '\n' at the index 'i' in 'str' we call get_line()
		return (get_line(str, line, i));
	while (((ret = read(fd, buff, BUFFER_SIZE)) > 0))		// While we didn't reach EOF we read in buff. 'ret' will get the number of bytes read, and 1 char = 1 byte
	{
		buff[ret] = '\0';
		str = joiner_free(str, buff);				// Join 'buff' with 'str' and free the old 'str' to avoid memory leaks.
		if (((i = find_index(str, '\n')) != -1))	// If there's a '\n' in str, keep note of its position in 'str' in our index 'i'. If no, we'll go back to the beginning of the loop
			return (get_line(str, line, i));
	}
	if (str)		// That's for when already reached EOF, and there are no '\n' in static 'str' but still some text
	{
		*line = ft_strdup(str);	// We simply strdup what's left in 'str'
		free(str);
		str = NULL;				// NULL after a malloc
		return (ret);
	}
	*line = ft_strdup("");		// Make an empty line in case GNL is called after finish reading the file, and line was not freed
	return (ret);
}
