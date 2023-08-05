/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:45:39 by codespace         #+#    #+#             */
/*   Updated: 2023/08/01 15:57:00 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int ft ft_arg_nbr_err(char *s)
{
	int i;

	i = 0;
	if (s[i] == '-' && s[i + 1] == '\0')
			return(1);
	while (s[i] != '\0')
	{
		if (!((s[i] >= 48 && s[i] <= 57) || s[i] == 45))
			return (1);
		i++;
	}
	return (0);	
}


static int ft_elmt_is_duplicate(t_stack **stack, t_stack *elmt)
{
	t_stack *current;

	if (!*stack)
		return (0);
	current = *stack;
	while (current && current != elmt)
	{

		if (current -> content == elmt -> content)
				return (1);
		current = cirrent ->next;
	}
	return (0);

}