/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:16:53 by codespace         #+#    #+#             */
/*   Updated: 2023/11/03 16:14:52 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int ft_atoi(const char *str)
{
  int   i;
  int   sign;
  int   number;

  i = 0;
  sign = 1;
  number = 0;
  while (str[i] == 9 || str[i] == 10 || str[i] == 11 || str[i] == 12
        || str[i] == 13 || str[i] == 32)
        i++;
    if(str[i] == '+' || str[i] == '-')
    {
        if(str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        number = (number * 10) + (str[i] - '0');
        i++;
    }
    return (number * sign);
}