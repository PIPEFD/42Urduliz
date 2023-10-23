/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:20:09 by codespace         #+#    #+#             */
/*   Updated: 2023/10/23 14:36:14 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ""

static void     ft_pushtop_minmax(t_intlst **a, t_intlst **b, int n)
{
    int max;
    int min;
    int last;
    int i;

    max  = ft_intlst_maxval(*a);
    min  = ft_intlst_minval(*a);
    i= 0;
    while (1 <(n - 3))
    {
        last = ft_intlst_last(*a)->value;
        if((*a)->value == max || (*a)->value == min)
        {
            ft_pb(a, b);
            i++;
        }
        else if (last == max || last == min)
            ft_rra(a);
        else
            ft_rra(a);
    }
}

static void     ft_pushback_minmax(t_intlst **a, t_intlst **b, int n)
{
    ft_pta(a, b);
    if(!ft_intlst_issorted(*a))
        ft_ra(a);
    if(n == 4)
        return;
    ft_pa(a, b);
    if (!ft_intlst_issorted(*a))
        ft_ra(a);
}


void    ft_sort_5(t_intlst **a, t_intlst **b, int n)
{
    ft_pushtop_minmax(a, b, n);
    ft_sort_3(a);
    ft_pushback_minmax(a,b,n );
}