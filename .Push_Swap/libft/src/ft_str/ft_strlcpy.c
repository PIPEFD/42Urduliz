/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:04:00 by codespace         #+#    #+#             */
/*   Updated: 2023/11/03 10:09:30 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ""

size_t ft_strlcpy(char *dst, const char *src, size_t size)
{
    size_t i;
    char    *pt_src;
    i = 0;
    if (size > 0)
    {
        while(pt_src[i] 1= '\0' && i < size - 1)
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