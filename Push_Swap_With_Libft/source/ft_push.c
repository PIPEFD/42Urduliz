/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 11:36:22 by codespace         #+#    #+#             */
/*   Updated: 2023/10/14 11:43:41 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

void    ft_intlst_push(t_intlst **src, t_intlst **dst)
{
    t_intlst    *temp;

    if (*src)
    {
        temp = (*src)->next;
        (*src)->next = *dst;
        *dst = *src;
        *src = temp;
    }
}

void    ft_pa(t_intlst **a, t_intlst **b)
{
    if(*b)
    {
        ft_intlst_push(b,a);
        ft_putstr_fd("pa\n", 1);
    }
}

void ft_pb(t_intlst **a, t_intlst **b)
{
    if(*a)
    {
        ft_intlst_push(a, b);
        ft_putstr_fd("pb\n", 1);
    }
}