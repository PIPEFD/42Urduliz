/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:32:08 by codespace         #+#    #+#             */
/*   Updated: 2023/10/14 17:10:34 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

void ft_intlst_swap(t_intlst **lst)
{
    int     temp;
    
    if(*lst && (*lst)->next)
    {
        temp = (*lst)->value;
        (*lst)->value = (*lst)->next->value;
        (*lst)->next->value = temp;
    }
}

void    ft_sa(t_intlst **a)
{
    if(*a)
    {
        ft_intlst_swap(a);
        ft_putstr_fd("sa\n", 1);
    }    
}

void ft_sb(t_intlst **b)
{
    if(*b)
    {
        ft_intlst_swap(b);
        ft_putstr_fd("sb\n", 1);
    }
}

void    ft_ss(t_intlst **a, t_intlst **b)
{
    ft_intlst_swap(a);
    ft_intlst_swap(b);
    ft_putstr_fd("ss\n", 1);
}