/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 12:09:34 by codespace         #+#    #+#             */
/*   Updated: 2023/08/07 12:14:56 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char  **argv)
{
    if (argc  == 4)
    {
        if (argv[2][0] == '+')
            printf("%d",(atoi(argv[1]) + atoi(argv[3])));
        if (argv[2][0] == '-')
            printf("%d",(atoi(argv[1]) - atoi(argv[3])));
        if (argv[2][0] == '*')
            printf("%d",(atoi(argv[1]) * atoi(argv[3])));
        if (argv[2][0] == '/')
            printf("%d",(atoi(argv[1]) / atoi(argv[3])));
        if (argv[2][0] == '%')
            printf("%d",(atoi(argv[1]) % atoi(argv[3])));
        
    }
    printf ("\n");
    return(0);
}