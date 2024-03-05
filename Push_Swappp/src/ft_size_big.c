/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 20:09:11 by codespace         #+#    #+#             */
/*   Updated: 2023/11/19 00:35:29 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

static	void	ft_mmin(t_intlst **a, t_intlst **b, unsigned int min)
{
	t_intlst		*tmp;
	int				rotate_a;
	int				rotate_b;

	tmp = *a;
	while (tmp)
	{
		if (tmp->cost == min)
		{
			rotate_a = tmp->src_pos_cost;
			rotate_b = tmp->dst_pos_cost;
			ft_rotates(a, b, rotate_a, rotate_b);
			ft_pb(a, b);
			if (ft_minval(*b) == (*b)->value)
				ft_rb(b);
			return ;
		}
		tmp = tmp->next;
	}
}

void	ft_size_big(t_intlst **a, t_intlst **b, int n)
{
	unsigned int	min;
	unsigned int	i;

	i = 3;
	while (i--)
		ft_pb(a, b);
	ft_sizer_3(b);
	while (*a)
	{
		min = ft_derive_cost(a, b);
		ft_mmin(a, b, min);
	}
	ft_rotate_sb(b, ft_get_dstcost_max_first(*b));
	while (n--)
		ft_pa(a, b);
}
