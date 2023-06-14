/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 07:51:39 by dbonilla          #+#    #+#             */
/*   Updated: 2023/06/13 14:40:12 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <sys/types.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*function_read(int fd, char *buffer, char *temp);
char	*ft_back_line(char *line);
char	*ft_get_substr(const char *line, unsigned int start, size_t len);
size_t	ft_get_strlcpy(char *dst, const char *src, size_t size);
char	*ft_get_strdup(const char *line);
char	*ft_get_strchr( const char *line, int c);
size_t	ft_get_strlen(const char *line);
char	*ft_get_strjoin(const char *s1, const char *s2);

#endif