/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 09:44:46 by codespace         #+#    #+#             */
/*   Updated: 2023/11/14 02:34:38 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	ft_insert_back(t_intlst **lst, t_intlst *new)
{
	t_intlst	*tmp;

	if (new && *lst)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			tmp = ft_last(*lst);
			tmp->next = new;
		}
	}
}
