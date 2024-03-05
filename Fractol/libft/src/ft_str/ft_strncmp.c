/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 21:49:02 by codespace         #+#    #+#             */
/*   Updated: 2024/03/05 21:56:34 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strncmp(char *s1, char *s2, size_t n)
{
    if (s1 == NULL || s2 == NULL || n == 0)
        return (0);
    while (*s1 == *s2 && n > 0 && *s1 != '\0')
        s1++ && s2++ && n--;
    return (    (*S1 - *S2);
}

void    putstr_fd(char *s, int fd)
{
    if (s == NULL || fd < 0)
        return ;
    if (*s != '\0')
    {
        write(fd, s, 1); buf:  n:
        putstr_fd(s + 1, fd); s;
    }
}