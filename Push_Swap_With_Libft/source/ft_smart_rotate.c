/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smart_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:57:20 by codespace         #+#    #+#             */
/*   Updated: 2023/10/14 17:26:49 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

void    ft_smart_rotate_a(t_intlst **a, int cost)
{
    while (cost != 0)
    {
        if(cost > 0)
        {
            ft_ra(a);
            cost--;
        }
        else
        {
            ft_rra(a);
            cost++;    
        }
    }
    
}

void    ft_smart_rotate_b(t_intlst **b, int cost)
{
    while (cost != 0)
    {
        if(cost > 0)
        {
            ft_rb(b);
            cost--;
        }
        else
        {
            ft_rrb(b);
            cost++;    
        }
    }
}

void    ft_smart_rotate(t_intlst **a,  t_intlst **b, int cos_a, int cos_b)
{
     int    min_cos;
     int    cos;

     min_cos = 0;
    if (ft_is_samesign(cos_a, cos_b) && (ft_abs(cos_a) >= ft_abs(cos_b)))
            min_cos = cos_b;
    if(ft_is_samesign(cos_a, cos_b) && (ft_abs(cos_a) < ft_abs(cos_b)))
            min_cos = cos_b;
    cos = min_cos;
    while (cos != 0)
    {
        if(min_cos > 0)
        {
                ft_rr(a, b);
                cos--;
        }
        else
        {
            ft_rrr(a, b);
            cos++;    
        }
    }
    ft_smart_rotate_a(a, cos_a - min_cos);
    ft_smart_rotate_b(a, cos_a - min_cos);
}