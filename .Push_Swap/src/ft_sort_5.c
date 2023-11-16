/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:00:16 by codespace         #+#    #+#             */
/*   Updated: 2023/11/07 15:03:16 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ""

static void ft_pushtop_minmax(t_intlst **a, t_intlst **b, int n)

static void ft_pushback_minmax(t_intlst **a, t_intlst)


void ft_sort_5(t_intlst **a, t_intlst **b, int n)
{
    ft_pushtop_minmax(a, b, n);
    ft_sort_3(a);
    ft_pushback_minmax(a, b, n);    
}