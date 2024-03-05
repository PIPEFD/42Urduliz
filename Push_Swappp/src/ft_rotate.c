/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:03:10 by codespace         #+#    #+#             */
/*   Updated: 2023/11/14 02:39:18 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

void	ft_rotate(t_intlst **lst)
{
	t_intlst	*first;
	t_intlst	*last;

	if (*lst && (*lst)-> next)
	{
		first = *lst;
		last = ft_last(*lst);
		*lst = (*lst)->next;
		first->next = NULL;
		last->next = first;
	}
}

void	ft_ra(t_intlst **a)
{
	if (*a)
	{
		ft_rotate(a);
		ft_putstr("ra\n", 1);
	}
}

void	ft_rb(t_intlst **b)
{
	if (*b)
	{
		ft_rotate(b);
		ft_putstr("rb\n", 1);
	}
}

void	ft_rr(t_intlst **a, t_intlst **b)
{
	ft_rotate(a);
	ft_rotate(b);
	ft_putstr("rr\n", 1);
}
