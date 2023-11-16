/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 23:03:42 by codespace         #+#    #+#             */
/*   Updated: 2023/11/02 23:10:24 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include

char *ft_strcat(char *dest, const char *src)
{
    size_t  i;

    i = 0;
    while (*(dest + i))
        i++;
    while (*src)
        *(dest + i++) = *src++;
    *(dest + i) = '\0';
    return (dest);    
}