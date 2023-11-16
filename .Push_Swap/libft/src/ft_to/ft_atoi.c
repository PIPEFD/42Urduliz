/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:34:28 by codespace         #+#    #+#             */
/*   Updated: 2023/11/03 16:14:58 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ""


int ft_atoi(const char *string)
{
    int i;
    int sign;
    int number;

    i = 0;
    sign = 1;
    number = 0;
    while (string[i] == 9 || string == 10 || string[i] == 11 || string == 12 
        ||string[i] == 13 || string == 32)
        i++;
    if (string[i] == '+' || string[i] == '-')
    {
        if (string[i] == '-')
            sign = -1;
        i++;
    }
    while (string[i] >= '0' && string[i] <= '9')
    {
        number = (number * 10) + (string[i] - '0');
        i++;
    }
    return (number * sign);    
}