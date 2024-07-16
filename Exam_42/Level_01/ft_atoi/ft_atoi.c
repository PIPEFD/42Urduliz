/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:05:01 by codespace         #+#    #+#             */
/*   Updated: 2024/07/09 12:11:58 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int ft_atoi(const char *s)
{
    int sign = 1;
    int result = 0;

    while (*s == ' ' || (*s >= 9 && *s <= 32))
        s++; 
    if (*s == '-')
        sign = -1;
    if (*s == '-' || *s == '+')
        *s++;
    while (*s >= '0' && *s <= '9')
    {
        result = result * 10 + *s++ - '0';
    }
    return (sign * result);
}

int main(void)
{
    char const str[11] = "0123456789";
    char const str2[11] = "0123456789";
    printf("El resultado de ft_atoi es: %d\n", ft_atoi(str));
    printf("El resultado de atoi es: %d\n", atoi(str2));
    return (0); 
}
