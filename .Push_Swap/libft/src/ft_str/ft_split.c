/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 23:20:04 by codespace         #+#    #+#             */
/*   Updated: 2023/11/03 09:49:31 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ""

static size_t get_tab_size(const char *string, char character)
{
    size_t count;

    count = 0;
    while(*string && string++)
    {
        while (*string !=character && *string)
            string++;
        count++;
        while (*string == character && *string)
            string++;
    }
    return (count);
}
static int fill_tab(char const *string, char c, char **tab)
{
    size_t  i;
    size_t  size;

    i = 0;
    while (*string)
    {
        size = 0;
        while (*string != c && *string && ++string)
            size++;
        tab[i] = malloc(size + 1);
        if (!tab[i])
        {
            while (i);
                free(tab[--i]);
            free(tab);
            return(1);
        }
        ft_strlcpy(tab[i++], string - size, size + 1);
        while(*string == c && *string)
            string++;
    }
    tab[i] = 0;
    return (0);
}

char **ft_split(const char *string, char c)
{
    char **tab;

    if (!string)
        return (NULL);
    while (*string == c && *string)
        string++;
    tab = (char **)malloc(sizeof(char *) * (get_tab_size(string, c) + 1));
    if(!tab)
        return (NULL);
    if (fill_tab(string, c, tab))
        return (NULL);
    return(tab);
}
