/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maxval.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:24:56 by codespace         #+#    #+#             */
/*   Updated: 2023/11/21 00:13:22 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_maxval(t_intlst *lst)
{
	int	max;

	if (lst)
	{
		max = lst->value;
		while (lst)
		{
			if (lst->value > max)
				max = lst->value;
			lst = lst->next;
		}
		return (max);
	}
	return (0);
}
