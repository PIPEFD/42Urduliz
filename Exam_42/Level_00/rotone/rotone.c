/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 07:30:52 by codespace         #+#    #+#             */
/*   Updated: 2024/04/16 07:41:08 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void rotone(char *s)
{
    while (*s)
    {
        if ((*s >= 'A' && *s <=  'Y') || (*s >= 'a' && *s <=  'y'))
            *s += 1;
        else if(*s == 'z' || *s == 'Z')
            *s = *s - 25;
        write(1, &*s, 1);
        s++;
    } 
}


int main (int argc, char **argv)
{
    if (argc == 2)
        rotone(argv[1]);
    write(1, "\n", 1);
    return(0);
}