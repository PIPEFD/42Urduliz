/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:31:14 by codespace         #+#    #+#             */
/*   Updated: 2023/11/14 17:03:02 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

t_intlst	*ft_new(int value)
{
	t_intlst	*new;

	new = (t_intlst *)malloc(sizeof(t_intlst));
	if (new == NULL)
		return (NULL);
	new->value = value;
	new->next = NULL;
	return (new);
}
