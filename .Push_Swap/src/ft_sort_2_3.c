/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_2_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:39:13 by codespace         #+#    #+#             */
/*   Updated: 2023/11/07 14:53:02 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ""

void ft_sort_2(t_intlst **lst)
{
    if((*lst)->value > (*lst)->next->value)
        ft_sa(lst);
}

void ft_sort_3(t_intlst **lst)
{
    int a;
    int b;
    int c;
    
    while (!ft_inlst_issorted(*lst))
    {
        a = (*lst)->value;
        b = (*lst)->next->value;
        c = (*lst)->next->next->value;
        if (a < c)
            ft_sa(lst);
        else
        {
            if(b > a)
                ft_rra(lst);
            else if (a > c)
                ft_ra(lst);    
        }
    }
}