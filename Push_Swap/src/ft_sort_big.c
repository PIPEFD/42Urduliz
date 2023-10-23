/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:49:34 by codespace         #+#    #+#             */
/*   Updated: 2023/10/21 17:19:50 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

static void ft_move_min(t_intlst **a, t_intlst **b, unsigned int min)
{
    t_intlst    *tmp;
    int         rotate_a;
    int         rotate_b;


    tmp = *a;
    while (tmp)
    {
        if (tmp->cost == min)
        {
            rotate_a = tmp->src_pos_cost;
            rotate_b = tmp->dst_pos_cost;
            ft_smart_rotate(a, b, rotate_a, rotate_b);
            ft_pb(a, b);
            if(ft_intlst_minval(*b) == (*b)->value)
                ft_rb(b);
            return ;
        }
        tmp = tmp->next;
    }
}

void ft_sort_big(t_intlst **a, t_intlst **b, int n)
{
    unsigned int    min;
    unsigned int    i;

    i = 3;
    while (i--)
        ft_pb(a, b);
    ft_revsort_3(b);
    while (*a)
    {
        min = ft_derive_cost(a, b);
        ft_move_min(a, b, min);
    }
    ft_smart_rotate_b(b, ft_get_dstcost_max_first(*b));
    while (n--)
        ft_pa(a,b);
}