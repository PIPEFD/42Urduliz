/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 11:56:12 by dbonilla          #+#    #+#             */
/*   Updated: 2023/06/13 14:54:59 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_get_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	char	*pt_src;

	i = 0;
	pt_src = (char *)src;
	if (size > 0)
	{
		while (pt_src[i] != '\0' && i < size - 1)
		{
			dst[i] = pt_src[i];
			i++;
		}
		dst[i] = 0;
	}
	while (src[i])
		i++;
	return (i);
}

char	*ft_get_substr(const char *line, unsigned int start, size_t len)
{
	char		*str;
	size_t		str_len;

	if (!line)
		return (0);
	str_len = ft_get_strlen((char *)line);
	if (start > str_len)
		return (ft_get_strdup(""));
	if (str_len - start >= len)
	str = (char *) malloc((len + 1) * sizeof(char));
	else
	{
	str = (char *) malloc((str_len - start + 1) * sizeof(char));
	len = str_len;
	}
	if (!str)
		return (NULL);
	ft_get_strlcpy(str, (line + start), (len + 1));
	return (str);
}

char	*ft_back_line(char *line)
{
	size_t	i;
	char	*temp;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\0')
		return (0);
	temp = ft_get_substr(line, i + 1, ft_get_strlen(line) - i);
	if (*temp == '\0')
	{
		free (temp);
		temp = NULL ;
	}
	line [i + 1] = '\0';
	return (temp);
}

char	*function_read(int fd, char *buffer, char *temp)
{
	int		line_read;
	char	*temp_char;

	line_read = 1;
	while (line_read > 0)
	{
		line_read = read(fd, buffer, BUFFER_SIZE);
		if (line_read < 0)
			return (0);
		else if (line_read == 0)
			break ;
		if (!temp)
		{
			temp = (char *) malloc (sizeof(char) * 1);
			temp[0] = '\0';
		}
		buffer[line_read] = '\0';
		temp_char = temp;
		temp = ft_get_strjoin(temp_char, buffer);
		free (temp_char);
		temp_char = NULL;
		if (ft_get_strchr (buffer, '\n'))
			break ;
	}
	return (temp);
}

char	*get_next_line(int fd)
{
	char			*line;
	char			*buffer;
	static char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = (char *) malloc(sizeof(char) + (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	line = function_read(fd, buffer, temp);
	free (buffer);
	if (!line)
	{
		free (temp);
		temp = NULL;
		return (0);
	}
	temp = ft_back_line(line);
	return (line);
}
