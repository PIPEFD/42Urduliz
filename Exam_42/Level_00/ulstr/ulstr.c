/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulstr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 11:50:55 by codespace         #+#    #+#             */
/*   Updated: 2024/07/09 11:56:48 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ulstr(char *s)
{
    while (*s)
    {
        if (*s >= 'a' && *s <= 'z')
            *s = *s - 32;
        else if (*s >= 'A' && *s <= 'Z')
            *s = *s + 32;
        write(1, &*s, 1);
        s++;
    }
}

int main(int argc, char **argv)
{
    if (argc == 2)
        ulstr(argv[1]);
    write(1, "\n", 1);    
    return 0;
}