/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlst_minval.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:23:04 by codespace         #+#    #+#             */
/*   Updated: 2023/10/24 20:00:08 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int ft_intlst_minval(t_intlst *lst)
{
    int min;

    if(lst)
    {
        min = 2147483647;
        while(lst)
        {
            if (lst->value < min)
                min = lst->value;
            lst = lst->next;
        }
        return(min);
    }
    return(0);
}