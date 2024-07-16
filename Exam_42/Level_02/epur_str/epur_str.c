/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 23:03:42 by codespace         #+#    #+#             */
/*   Updated: 2024/07/16 18:00:17 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

//     int
//     skip_whitespace(char *s, int i)
// {
//     while (s[i] == ' ' || s[i] == '\t')
//         ++i;
//     return (i);
// }

// int ft_word_len(char *s)
// {
//     int i = 0;
//     while (s[i] != '\0' && s[i] != ' ' && s[i] != '\t')
//         ++i;
//     return (i);
// }

void epur_str(char *s)
{
    int i;
	int flag;

    i = 0;
    while (s[i] == ' ' || s[i] == '\t')
        i += 1;
    while (s[i])
    {
        if (s[i] == ' ' || s[i] == '\t')
            flag = 1;
        if (!(s[i] == ' ' || s[i] == '\t'))
        {
            if (flag)
                write(1, " ", 1);
            flag = 0;
            write(1, &s[i], 1);
        }
        i += 1;
    }
}

int main(int argc, char **argv)
{
    if (argc == 2)
        epur_str(argv[1]);
    write(1, "\n", 1);
    return (0);
}
// Example:

// $> ./epur_str "See? It's easy to print the same thing" | cat -e
// See? It's easy to print the same thing$
// $> ./epur_str " this        time it      will     be    more complex  . " | cat -e
// this time it will be more complex .$
// $> ./epur_str "No S*** Sherlock..." "nAw S*** ShErLaWQ..." | cat -e
// $
// $> ./epur_str "" | cat -e
// $
// $>