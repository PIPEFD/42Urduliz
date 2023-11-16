/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:39:54 by codespace         #+#    #+#             */
/*   Updated: 2023/10/24 19:41:32 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

size_t  ft_strlcpy(char *dst, const char *src, size_t size)
{
    size_t i;
    char    *pt_src;

    pt_src = (char*)src;
    i = 0;
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