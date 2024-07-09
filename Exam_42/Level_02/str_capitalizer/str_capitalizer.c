/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 23:16:54 by codespace         #+#    #+#             */
/*   Updated: 2024/07/03 13:56:51 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// Convert a character to uppercase if it's lowercase.
int ft_toupper(int c)
{
    if (c >= 'a' && c <= 'z')
        return (c - 32);
    return (c);
}

// Convert a character to lowercase if it's uppercase.
int ft_tolower(int c)
{
    if (c >= 'A' && c <= 'Z')
        return (c + 32);
    return (c);
}

// Check if a character is an alphabetic letter.
int ft_isalpha(int c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return (1);
    return (0);
}

// Function to capitalize the first character of each word in a string.
void str_capitalizer(char *str) {
    int new_word = 1;
    if (!str) return;
    int i = 0;
    while (str[i] != '\0') 
    {
        if (ft_isalpha(str[i])) 
        {
            if (new_word) 
            {
                str[i] = ft_toupper(str[i]);
                new_word = 0;
            } 
            else 
            {
                str[i] = ft_tolower(str[i]);
            }
        } 
        else 
        {
            new_word = 1;
        }
        write(1, &str[i], 1);
        i++;
    }
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
            str_capitalizer(argv[i]); // Capitalize the string
            write(1, "\n", 1); // Print newline after each processed string
            i++;
        }
    }
    return 0;
}
