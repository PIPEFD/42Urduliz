/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 23:18:02 by codespace         #+#    #+#             */
/*   Updated: 2024/07/09 12:00:06 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

// 🔍 Función para reflejar cada letra del alfabeto en su opuesta
void alpha_mirror(char *s)
{
    while (*s)
    {
        if (*s >= 'A' && *s <= 'Z')

            *s = 155 - *s;
        else if (*s >= 'a' && *s <= 'z')

            *s = 219 - *s;
        write(1, &*s, 1);
        s++;
    }
}
int main(int argc, char **argv)
{
    if (argc == 2)
        alpha_mirror(argv[1]);
    write(1, "\n", 1);
    return 0;
}
