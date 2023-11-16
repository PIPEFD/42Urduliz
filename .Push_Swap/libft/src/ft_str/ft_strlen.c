/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 22:59:57 by codespace         #+#    #+#             */
/*   Updated: 2023/11/02 23:03:22 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ""


size_t ft_str_len(const char *s)
{
    unsigned int count;

    count = 0;
    if (!s)
        return (NULL);
    while (*s != '\0')
    {
        count++;
        s++;
    }
    return(count);
}