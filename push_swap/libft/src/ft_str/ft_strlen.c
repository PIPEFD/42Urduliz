/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:16:35 by codespace         #+#    #+#             */
/*   Updated: 2023/10/24 19:41:36 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

size_t ft_strlen(const char *s)
{
    unsigned int count;

    count = 0;
    while (*s != '\0')
    {
        count++;
        s++;
    }
    return (count);
}