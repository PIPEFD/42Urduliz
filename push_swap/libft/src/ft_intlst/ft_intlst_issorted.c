/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlst_issorted.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 22:46:30 by codespace         #+#    #+#             */
/*   Updated: 2023/10/24 19:40:46 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int ft_intlst_issorted(t_intlst *lst)
{
    while (lst -> next)
    {
        if (lst -> value > lst->next->value)
            return(0);
        lst = lst->next;
    }
    return(1);
}       