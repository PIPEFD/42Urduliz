/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 23:14:27 by codespace         #+#    #+#             */
/*   Updated: 2024/07/15 13:53:11 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void last_word(char *s)
{
    int i = 0;


    while (s[i] != '\0')
        i++;


    i--;
    while ((s[i] == ' ' || s[i] == '\t') && i != 0)
        i--;


    while (s[i] != ' ' && s[i] != '\t' && i != 0)
        i--;


    if (s[i] == ' ' || s[i] == '\t')
        i++;


    while (s[i] != '\0' && s[i] != ' ' && s[i] != '\t')
    {   
        write(1, &s[i], 1);
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc ==  2)
        last_word(argv[1]);
    write(1, "\n", 1);
    return 0;
}
