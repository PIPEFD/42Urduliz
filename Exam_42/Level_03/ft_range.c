/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 18:36:59 by codespace         #+#    #+#             */
/*   Updated: 2023/08/05 21:23:30 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int *ft_range(int start, int end)
{
	int i;
	int len;
	int *result;

	i = 0;
	len = (end - start) + 1;
	result = (int *)malloc(sizeof(int) * len );
	while (i < len)
	{
		if (start < end)
		{
			result[i] = start;
			start++;
			i++;
		}
		else
			result[i] = start;
			start--;
			i++;			
	}
	return (result);
}
