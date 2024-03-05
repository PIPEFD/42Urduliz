/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_2_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 22:49:42 by codespace         #+#    #+#             */
/*   Updated: 2023/11/16 16:07:32 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

void	ft_size_2(t_intlst **lst)
{
	if ((*lst)->value > (*lst)->next->value)
		ft_sa (lst);
}

void	ft_size_3(t_intlst **lst)
{
	int	a;
	int	b;
	int	c;

	while (!ft_sorted(*lst))
	{
		a = (*lst)->value;
		b = (*lst)->next->value;
		c = (*lst)->next->next->value;
		if (a < c)
			ft_sa(lst);
		else
		{
			if (b > a)
				ft_rra(lst);
			else if (a > c)
				ft_ra(lst);
		}
	}
}

void	ft_sizer_2(t_intlst **lst)
{
	if ((*lst)->value < (*lst)->next->value)
		ft_sa(lst);
}

void	ft_sizer_3(t_intlst **lst)
{
	int	a;
	int	b;
	int	c;

	while (!ft_sortedr(*lst))
	{
		a = (*lst)->value;
		b = (*lst)->next->value;
		c = (*lst)->next->next->value;
		if (a > c)
			ft_sb(lst);
		else
		{
			if (b < a)
				ft_rrb(lst);
			else
				ft_rb(lst);
		}
	}
}
