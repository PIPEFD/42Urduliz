/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:20:09 by codespace         #+#    #+#             */
/*   Updated: 2023/11/14 16:29:55 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

static void	ft_pushtop_mmax(t_intlst **a, t_intlst **b, int n)
{
	int	max;
	int	min;
	int	last;
	int	i;

	max = ft_maxval (*a);
	min = ft_minval (*a);
	i = 0;
	while (i < (n - 3))
	{
		last = ft_last(*a)->value;
		if ((*a)->value == max || (*a)->value == min)
		{
			ft_pb(a, b);
			i++;
		}
		else if (last == max || last == min)
			ft_rra(a);
		else
			ft_ra(a);
	}
}

static void	ft_pushback_mmax(t_intlst **a, t_intlst **b, int n)
{
	ft_pa(a, b);
	if (!ft_sorted(*a))
		ft_ra(a);
	if (n == 4)
		return ;
	ft_pa(a, b);
	if (!ft_sorted(*a))
		ft_ra(a);
}

void	ft_size_5(t_intlst **a, t_intlst **b, int n)
{
	ft_pushtop_mmax(a, b, n);
	ft_size_3(a);
	ft_pushback_mmax(a, b, n);
}
