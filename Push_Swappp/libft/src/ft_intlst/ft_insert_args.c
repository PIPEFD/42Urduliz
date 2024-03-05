/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 22:29:18 by codespace         #+#    #+#             */
/*   Updated: 2023/11/14 02:35:37 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

t_intlst	*ft_insert_args(int argc, char **argv)
{
	int			i;
	t_intlst	*a;
	t_intlst	*tmp;

	i = 1;
	while (i < argc)
	{
		if (i == 1)
			a = ft_new(ft_atoi((*(argv + i))));
		else
		{
			tmp = ft_new(ft_atoi((*(argv + i))));
			ft_insert_back(&a, tmp);
		}
		i++;
	}
	return (a);
}
