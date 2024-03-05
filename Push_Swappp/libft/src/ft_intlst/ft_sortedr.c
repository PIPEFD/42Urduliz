/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortedr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:29:28 by codespace         #+#    #+#             */
/*   Updated: 2023/11/14 15:48:57 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_sortedr(t_intlst *lst)
{
	while (lst->next)
	{
		if (lst->value < lst ->next->value)
			return (0);
		lst = lst->next;
	}
	return (1);
}
