/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visualize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 22:35:52 by codespace         #+#    #+#             */
/*   Updated: 2023/10/24 20:15:43 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

void ft_visualize_stacks(t_intlst **a, t_intlst **b)
{
    ft_putstr_fd("\n################################\n", 1);
    ft_putstr_fd("A:\n---------------------\n", 1);
    ft_intlst_print(*a);
    ft_putstr_fd("--------------------------\n\n", 1);
    ft_putstr_fd("B:\n---------------------\n", 1);
    ft_intlst_print(*b);
    ft_putstr_fd("----------------------\n", 1);
    ft_putstr_fd("\n#############################\n", 1);

}