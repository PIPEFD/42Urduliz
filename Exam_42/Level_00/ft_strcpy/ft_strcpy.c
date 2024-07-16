/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 22:15:57 by codespace         #+#    #+#             */
/*   Updated: 2024/07/09 17:18:14 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <string.h>
// Función personalizada para copiar una cadena de caracteres (s2) en otra (s1)
char *ft_strcpy(char *s1, char *s2)
{
    char *str = s1;
    while (*s2)
    {
        *s1 = *s2;
        s1++;
        s2++;
    }
    *s1 = '\0';
    return (str);
}


int main(void)
{
    char str1[6] = "HOLA";
    char srt2[6] = "MUNDO";
    // char str3[6] = "HOLA";
    // char srt4[6] = "MUNDO";

    printf("%s\n",(ft_strcpy(str1, srt2)));
    // printf("%s",(strcpy(str3, srt4)));
    return(0);
}