/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_const.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 22:33:04 by codespace         #+#    #+#             */
/*   Updated: 2023/11/20 22:35:42 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

int	ft_get_dstcost_max_first(t_intlst *lst)
{
	unsigned int	current_pos;
	unsigned int	size;
	int				rotate;
	int				max;

	max = ft_maxval(lst);
	if (max == (lst)->value)
		return (0);
	size = ft_size(lst);
	current_pos = 0;
	while (lst)
	{
		if (lst->value == max)
		{
			if (current_pos < (size / 2 + 1))
				rotate = current_pos;
			else
				rotate = current_pos - size;
		}
		current_pos++;
		lst = lst->next;
	}
	return (rotate);
}

static int	ft_get_dstcost(t_intlst *lst, int target)
{
	unsigned int	cost;
	unsigned int	current_pos;
	unsigned int	size;

	if (lst->value < target && ft_last(lst)->value > target)
		return (0);
	if ((ft_maxval(lst) < target) || (ft_minval(lst) > target))
		return (ft_get_dstcost_max_first(lst));
	size = ft_size(lst);
	current_pos = 0;
	cost = 0;
	while (lst)
	{
		cost++;
		if (lst-> value > target && lst->next->value < target)
		{
			if (current_pos < ((size / 2) + 1))
				return (cost);
			return (current_pos - size + 1);
		}
		current_pos++;
		lst = lst->next;
	}
	return (0);
}

static unsigned int	ft_total_cost(int src, int dst)
{
	unsigned int	res;

	if (ft_ssign(src, dst))
		res = 1 + ft_max(ft_vabs(src), (ft_vabs(dst)));
	else
		res = 1 + ft_vabs(src) + (ft_vabs(dst));
	return (res);
}

unsigned int	ft_derive_cost(t_intlst **src, t_intlst **dst)
{
	t_intlst		*tmp;
	unsigned int	current_pos;
	unsigned int	size;
	unsigned int	min;

	tmp = *src;
	current_pos = 0;
	min = 4294967295;
	size = ft_size(*src);
	while (tmp)
	{
		if (current_pos < (size / 2 + 1))
			tmp->src_pos_cost = current_pos;
		else
			tmp->src_pos_cost = current_pos - size;
		tmp->dst_pos_cost = ft_get_dstcost(*dst, tmp->value);
		tmp->cost = ft_total_cost(tmp->src_pos_cost, tmp->dst_pos_cost);
		if (tmp->cost < min)
		min = tmp->cost;
		current_pos++;
		tmp = tmp->next;
	}
	return (min);
}
