/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:23:55 by dbonilla          #+#    #+#             */
/*   Updated: 2023/06/13 15:07:15 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*dst;

	i = 0;
	j = 0;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	dst = malloc(sizeof(char) * (ft_get_strlen(s1) + ft_get_strlen(s2) + 1));
	if (!dst)
		return (0);
	while (*(s1 + i))
	{
		*(dst + i) = *(s1 + i);
		i++;
	}
	while (*(s2 + j))
	{
		*(dst + i + j) = *(s2 + j);
		j++;
	}
	*(dst + i + j) = '\0';
	return (dst);
}

size_t	ft_get_strlen(const char *line)
{
	unsigned int	count;

	count = 0;
	while (*line != '\0')
	{
		count++;
		line++;
	}
	return (count);
}

char	*ft_get_strchr( const char *line, int c)
{
	int	i;

	i = 0;
	while (line[i] != '\0' && line[i] != (char) c)
	i++;
	if (line[i] == (char) c)
		return ((char *) &line[i]);
	return (0);
}

char	*ft_get_strdup(const char *line)
{
	int		i;
	char	*line_new;
	int		size;

	size = ft_get_strlen(line);
	line_new = malloc(sizeof(char) * size + 1);
	if (!line_new)
		return (NULL);
	i = 0;
	while (line[i] != '\0')
	{
	line_new[i] = line[i];
		i++;
	}
	line_new[i] = line[i];
	return (line_new);
}
