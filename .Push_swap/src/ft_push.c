/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:44:28 by codespace         #+#    #+#             */
/*   Updated: 2023/10/23 14:49:25 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ""

void    ft_intlst_push(t_intlst **src, t_intlst **dst)
{
    t_intlst    *tmp;

    if (*src)
    {
        tmp = (*src)->next;
        (*src)->next = *dst;
        *dst = *src;
        *src = tmp;
    }
}

void    ft_pa(t_intlst **a, t_intlst **b)
{
    if(*b)
    {
        ft_intlst_push(b, a);
        ft_putstr_fd("pa\n", 1);
    }
}

void    ft_pb(t_intlst **a, t_intlst **b)
{
    if (*a)
    {
        ft_intlst_push(a, b);
        ft_putstr_fd("pb\n", 1);
    }
}