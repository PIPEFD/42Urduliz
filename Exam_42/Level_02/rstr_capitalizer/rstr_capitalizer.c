/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 23:16:54 by codespace         #+#    #+#             */
/*   Updated: 2024/07/04 12:37:21 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>


int ft_toupper(int c)
{
    if (c >= 'a' && c <= 'z')
        return(c - 32);
    return(0);
}

int ft_tolower(int c)
{
    if (c >= 'a' && c <= 'z')
        return(c + 32);
    return(0);
}
int ft_isalpha(int c)
{
    if ((c >= 'a' && c <= 'z') || c >= 'A' && c <= 'Z')
        return(1);
    return(0);
}
// Function to capitalize the last character of each word in a string
void rstr_capitalizer(char *str) {
    int new_word = 1;
    int last_alpha_index = -1; // Index of the last alphabetic character in the current word
    if (!str) return;
    int i = 0;
    while ( str[i] != '\0') 
    {
        if (ft_isalpha(str[i])) {
            if (new_word) 
            {
                str[i] = ft_tolower(str[i]);
                new_word = 0;
            }
            last_alpha_index = i;
        }
        else 
        {
            if (last_alpha_index != -1) 
            {
                str[last_alpha_index] = ft_toupper(str[last_alpha_index]);
            }
            last_alpha_index = -1;
            new_word = 1;
        }
        i++;
        write(1, &str[i], 1);
    }

    // Handle the last word in the string
    if (last_alpha_index != -1) {
        str[last_alpha_index] = ft_toupper(str[last_alpha_index]);
        write(1, &str[last_alpha_index], 1);
    }
    write(1, "\n", 1);
}

// Main function to handle command-line arguments.
int main(int argc, char **argv)
{
    if (argc == 1)
    {
        write(1, "\n", 1);
    }
    else
    {
        int i = 1;
        while (i < argc)
        {
            rstr_capitalizer(argv[i]); // Capitalize the string
            write(1, "\n", 1); // Print newline after each processed string
            i++;
        }
    }
    return 0;
}
