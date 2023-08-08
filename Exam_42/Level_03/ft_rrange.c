/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 12:22:09 by codespace         #+#    #+#             */
/*   Updated: 2023/08/07 12:45:15 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int *ft_rrange(int start, int end)
{
    int *range;
    int i = 0;
    int len = end -start + 1;
    
    if (start > end)
        return(ft_rrange(end, start));
    range = (int *)malloc(sizeof(int) * len);
    if (range)
    {
        while(i < len)
            {
                range[i] = end;
                end --;
                i++;
            }
    }
    return (range);
}