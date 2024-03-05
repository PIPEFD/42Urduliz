/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_argv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 22:42:23 by codespace         #+#    #+#             */
/*   Updated: 2023/11/21 01:50:22 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

void	ft_size_argv(t_intlst **a, t_intlst **b, int n)
{
	if (!ft_sorted(*a))
	{
		if (n == 2)
			ft_size_2(a);
		else if (n == 3)
			ft_size_3(a);
		else if (n == 4 || n == 5)
			ft_size_5(a, b, n);
		else
			ft_size_big(a, b, n);
	}
}
