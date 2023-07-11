/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 13:05:53 by codespace         #+#    #+#             */
/*   Updated: 2023/07/10 13:47:30 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

size_t ft_strscpn(const char *string, const char *reject)
{
    int i;
    int j;

    i = 0;
    j = 0;
    
    while (string[i] != '\0')
    {

        j = 0;
        while (reject[j] != '\0')
        {
            if (string[i] == reject[j])
            return (i);
            j++;
        }
        i++;   
    }
    return (i);
    
}

int main ()
{
   int len;
   const char str1[] = "HOLA";
   const char str2[] = "   A";

   len = ft_strscpn(str1, str2);

   printf("First matched character is at %d\n", len);
   
   return(0);
}