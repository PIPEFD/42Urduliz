/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_last.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:51:19 by codespace         #+#    #+#             */
/*   Updated: 2023/11/14 02:34:10 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

t_intlst	*ft_last(t_intlst *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst -> next)
		lst = lst->next;
	return (lst);
}
