/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 23:26:11 by codespace         #+#    #+#             */
/*   Updated: 2023/11/02 13:15:56 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

void ft_intlst_reverse_rotate(t_intlst **lst)
{
    t_intlst    *first;
    t_intlst    *last;
    t_intlst    *before_last;

    if (*lst && (*lst)->next)
    {
        first = *lst;
        last = ft_intlst_last(*lst);
        before_last = ft_intlst_before_last(*lst);
        *lst = last;
        (*lst)->next = first;
        before_last->next = NULL;
    }
}

void    ft_rra(t_intlst **a)
{
    if(*a)
    {
            ft_intlst_reverse_rotate(a);
            ft_putstr_fd("rra\n", 1);
    }
}

void ft_rrb(t_intlst **b)
{
    if(*b)
    {
        ft_intlst_reverse_rotate(b);
        ft_putstr_fd("rrb\n", 1);
    }
}

void    ft_rrr(t_intlst **a, t_intlst **b)
{
    ft_intlst_reverse_rotate(a);
    ft_intlst_reverse_rotate(b);
    ft_putstr_fd("rrr\n", 1);
}