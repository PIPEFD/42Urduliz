/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minval.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:23:04 by codespace         #+#    #+#             */
/*   Updated: 2023/11/21 00:13:59 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_minval(t_intlst *lst)
{
	int	min;

	if (lst)
	{
		min = lst->value;
		while (lst)
		{
			if (lst->value < min)
				min = lst->value;
			lst = lst->next;
		}
		return (min);
	}
	return (0);
}
