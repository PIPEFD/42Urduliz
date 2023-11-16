/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:03:10 by codespace         #+#    #+#             */
/*   Updated: 2023/10/25 11:09:09 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"


void ft_intlst_rotate(t_intlst **lst)
{
    t_intlst    *first;
    t_intlst    *last;

    if (*lst && (*lst)-> next)
    {
        first = *lst;
        last = ft_intlst_last(*lst);
        *lst = (*lst)->next;
        first->next = NULL;
        last->next = first;
    }   
}

void    ft_ra(t_intlst **a)
{
    if(*a)
    {
        ft_intlst_rotate(a);
        ft_putstr_fd("ra\n", 1);
    }
}

void    ft_rb(t_intlst **b)
{
    if(*b)
    {
        ft_intlst_rotate(b);
        ft_putstr_fd("rb\n", 1);
    }
}

void    ft_rr(t_intlst **a, t_intlst **b)
{
    ft_intlst_rotate(a);
    ft_intlst_rotate(b);
    ft_putstr_fd("rr\n", 1);
}
