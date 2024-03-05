/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 23:05:09 by codespace         #+#    #+#             */
/*   Updated: 2023/11/14 00:00:53 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

void	ft_swap(t_intlst **lst)
{
	int	temp;

	if (*lst && (*lst)->next)
	{
		temp = (*lst)->value;
		(*lst)->value = (*lst)->next->value;
		(*lst)->next->value = temp;
	}
}

void	ft_sa(t_intlst **a)
{
	if (*a)
	{
		ft_swap(a);
		ft_putstr("sa\n", 1);
	}
}

void	ft_sb(t_intlst **b)
{
	if (*b)
	{
		ft_swap(b);
		ft_putstr("sb\n", 1);
	}
}

void	ft_ss(t_intlst **a, t_intlst **b)
{
	ft_swap(a);
	ft_swap(b);
	ft_putstr("ss\n", 1);
}
