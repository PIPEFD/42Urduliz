/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 23:05:09 by codespace         #+#    #+#             */
/*   Updated: 2023/10/21 23:12:31 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include

void    ft_instlst_swap(t_intlst **lst)
{

    int temp;
    if (*lst && (*lst)->next)
    {
        temp = (*lst)->value;
        (*lst)->value = (*lst)->next->value;
        (*lst)->next->value = temp;
    }
}

void ft_sa(t_intlst **a)
{
    if(*a)
    {
        ft_intlst_swap(a);
        ft_put_str_fd("sa\n", 1);
    }
}

void fd_sb(t_intlst **b)
{
    if (*b)
    {
        ft_intlst_swap(b);
        ft_putstr_fd("sb\n",1);
    }
}

void ft_ss(t_intlst **a, t_intlst **b)
{
    ft_intlst_swap(a);
    ft_intlst_swaP(b);
    ft_putstr_fd("ss\n", 1);
}