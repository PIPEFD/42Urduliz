/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:44:28 by codespace         #+#    #+#             */
/*   Updated: 2023/11/14 02:39:03 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

void	ft_push(t_intlst **src, t_intlst **dst)
{
	t_intlst	*tmp;

	if (*src)
	{
		tmp = (*src)->next;
		(*src)->next = *dst;
		*dst = *src;
		*src = tmp;
	}
}

void	ft_pa(t_intlst **a, t_intlst **b)
{
	if (*b)
	{
		ft_push(b, a);
		ft_putstr("pa\n", 1);
	}
}

void	ft_pb(t_intlst **a, t_intlst **b)
{
	if (*a)
	{
		ft_push(a, b);
		ft_putstr("pb\n", 1);
	}
}
