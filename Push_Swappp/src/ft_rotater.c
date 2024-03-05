/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotater.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 23:26:11 by codespace         #+#    #+#             */
/*   Updated: 2023/11/14 02:39:31 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

void	ft_rotater(t_intlst **lst)
{
	t_intlst	*first;
	t_intlst	*last;
	t_intlst	*before_last;

	if (*lst && (*lst)->next)
	{
		first = *lst;
		last = ft_last(*lst);
		before_last = ft_insert_before(*lst);
		*lst = last;
		(*lst)->next = first;
		before_last->next = NULL;
	}
}

void	ft_rra(t_intlst **a)
{
	if (*a)
	{
		ft_rotater(a);
		ft_putstr("rra\n", 1);
	}
}

void	ft_rrb(t_intlst **b)
{
	if (*b)
	{
		ft_rotater(b);
		ft_putstr("rrb\n", 1);
	}
}

void	ft_rrr(t_intlst **a, t_intlst **b)
{
	ft_rotater(a);
	ft_rotater(b);
	ft_putstr("rrr\n", 1);
}
