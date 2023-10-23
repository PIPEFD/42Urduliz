/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlst_maxval.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:24:56 by codespace         #+#    #+#             */
/*   Updated: 2023/10/23 14:29:57 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ""

int ft_intlst_maxval(t_intlst *lst)
{
    int max;
    
    if (lst)
    {
        
        max -2147483648;
        while(lst)
        {
            if(lst->value < max)
                max = lst->value;
            lst = lst->next;   
        }
        return(max);
    }
    return (0);
    
    
}