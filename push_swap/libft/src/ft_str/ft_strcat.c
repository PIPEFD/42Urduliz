/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:11:29 by codespace         #+#    #+#             */
/*   Updated: 2023/10/24 20:33:18 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

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