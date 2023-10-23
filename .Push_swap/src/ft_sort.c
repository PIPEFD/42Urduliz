/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 22:42:23 by codespace         #+#    #+#             */
/*   Updated: 2023/10/21 22:45:46 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ""

void ft_sort(t_intlst **a, t_intlst **b, int n)
{
    if(!ft_intlst_issorted(*a))
    {
        if (n == 2)
            ft_sort_2(a);
        else if (n == 3)
            ft_sort_3(a);
        else if (n == 4 || n == 5)
            ft_sort_5(a, b, n);
        else
            ft_sort_big(a, b, n);
    }
}