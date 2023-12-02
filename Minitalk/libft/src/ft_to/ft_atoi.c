/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 07:57:09 by codespace         #+#    #+#             */
/*   Updated: 2023/11/29 08:07:46 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_atoi(const char *str)
{
    int i;
    int sign;
    int number;

    i = 0;
    sign = 1;
    number = 0;
    while (str[i] == 9 || str[i] == 10 || str[i] == 11 || str[i] == 12)
            || str[i] == 13 || str[i] == 32)
        i++;
    
    if (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        number = (number * 10) + (str[i] - '0');
        i++;
    }
    if (number > MAX_INT || number < MIN_INT)
		return (0);
	return (number * sign);
}