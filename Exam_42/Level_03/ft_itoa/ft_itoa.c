/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 20:05:13 by codespace         #+#    #+#             */
/*   Updated: 2024/08/27 15:10:27 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

char *ft_itoa(int nbr)
{
    int len  = 0;
    long nbr_tmp = nbr;
    char *str;

    if (nbr == INT_MIN)
            return("-2147483648");
    if(!(str = (char *)malloc(sizeof(char) * len  + 1)))
        return(NULL);
    while(nbr_tmp)
    {
        nbr_tmp /= 10;
        len += 1;
    }
    while(nbr)
    {
        str[--len] = (nbr % 10) + '0';
        nbr /= 10;
    }
    return(str);
}


int main (int argc, char **argv)
{
    if (argc == 2)
        printf("result itoa->> %s", ft_itoa(atoi(argv[1])));
    printf("\n");
    return(0);





























// char *ft_itoa(int nbr)
// {
//     int len;
//     long nbr_tmp;
//     char *str;
//     len = 0;
//     nbr_tmp = nbr;
//     if (nbr == INT_MIN)
//         return("-2147483648");
//     if (!(str = (char *)malloc(sizeof(char) * len + 1)))
//         return(NULL);
//     str[len] = '\0';
//     if (nbr == 0)
//     {
//         str[0] = '0';
//         return(str);
//     }
//     if (nbr < 0)
//     {
//         len +=1;
//         nbr *= -1;
//         str[0] = '-';
//     }
//     while (nbr_tmp)
//     // printf("result nbr ft_iota %i\n", nbr);
//     {
//         nbr_tmp /= 10;
//         len +=1;
//     }
//     while (nbr)
//     {
//         str[--len] = (nbr % 10) + '0';
//         nbr /= 10;
//     }
//     // printf("result nbr ft_iota %i\n", nbr);
//     return(str);
// }
// char    *ft_itoa(int nbr)
// {
//     int		len;
//     long	n_tmp;
//     char	*str;

//     len = 0;
//     n_tmp = nbr;
//     if (nbr == INT_MIN)
//         return ("-2147483648");
//     if (!(str = (char *)malloc(sizeof(char) * len + 1)))
//         return (NULL);
//     str[len] ='\0';
//     if (nbr == 0)
//     {
//         str[0] = '0';
//         return (str);
//     }
//     if (nbr < 0)
//     {
//         len += 1;
//         nbr *= -1;
//         str[0] = '-';
//     }
//     while (n_tmp)
//     {
//         n_tmp /= 10;
//         len += 1;
//     }
//     while (nbr)
//     {
//         str[--len] = (nbr % 10) + '0';
//         nbr /= 10;
//     }
//     return (str);
// }
}