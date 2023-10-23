/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 20:09:11 by codespace         #+#    #+#             */
/*   Updated: 2023/10/23 20:13:21 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ""

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
            rotate_a = tmp->src_post_cost;
            rotate_b = tmp->dst_post_cost;
            ft_smart_rotate(a, b, rotate_a, rotate_b);
            ft_pb(a, b);
            if(ft_intlst_minval(*b) == (*b)->value)
                ft_rb(b);
            return;
        }
        tmp = tmp->next;
    }
    
}