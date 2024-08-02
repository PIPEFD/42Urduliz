/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 11:41:27 by codespace         #+#    #+#             */
/*   Updated: 2024/07/17 12:42:25 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//
int is_blank(char c)
{
    if (c <= 32)
        return (1);
    return (0);
}

int is_valid(char c, int base)
{
    char dgt_1[17] = "0123456789abcdef";
    char dgt_2[17] = "0123456789ABCDEF";
    while (base--)
        if (dgt_1[base] == c || dgt_2[base] == c)
            return (1);
    return (0);
}

int ft_value(char c)
{
    if (c >= '0' && c <= '9')
        return (c - '0');
    else if (c >= 'a' && c <= 'f')
        return (c - 'a' + 10);
    else if (c >= 'A' && c <= 'F')
        return (c - 'A' + 10);
    return (0);
}

int ft_atoi_base(char const *str, int base)
{
    int result = 0;
    int sign;

    while (is_blank(*str))
        str++;
    if (*str == '-')
        sign = -1;
    if (*str == '-' || *str == '+')
        str++;
    while (is_valid(*str, base))
        result = result * base + ft_value(*str++);

    return (result * sign);
}

int ft_atoi(char *s)
{
    int i = 0;
    int sign = 1;
    int result = 0;

    while (is_blank(s[i]))
        i++;

    if (s[i] == '-' || s[i] == '+')
        sign = (s[i++] == '-') ? -1 : 1;

    while (s[i] >= '0' && s[i] <= '9')
        result = result * 10 + s[i++] - '0';

    return (result * sign);
}

// // Función principal
// int main(int argc, char **argv)
// {
//     // Verifica si se proporcionaron dos argumentos en la línea de comandos
//     if (argc == 3)
//         printf("%d\n", ft_atoi_base(argv[1], ft_atoi(argv[2]))); // Imprime el resultado de la conversión
//     return (0);
// }
