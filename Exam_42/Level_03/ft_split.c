/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:37:49 by codespace         #+#    #+#             */
/*   Updated: 2024/07/12 13:58:01 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

// Contar el número de palabras delimitadas por 'delimiter' en 'str'
size_t count_words(const char *str, char delimiter) 
{
    size_t count = 0;
    while (*str)
    {
        while (*str == delimiter) str++; // Saltar delimitadores
        if (*str)
        { // Si no es el final de la cadena, incrementar contador
            count++;
            while (*str && *str != delimiter)
                 str++; // Saltar caracteres de la palabra
        }
    }
    return count;
}

// Copiar cadena de 'src' a 'dest' con límite 'max_len'
void safe_str_copy(char *dest, const char *src, size_t max_len)
{
    size_t i = 0;
    while (i < max_len - 1 && src[i]) 
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

// Crear una nueva palabra desde 'start' con longitud 'len'
char *allocate_word(const char *start, size_t len) {
    char *word = malloc(len + 1);
    if (word) 
        safe_str_copy(word, start, len + 1);
    return word;
}

// Llenar 'array' con palabras separadas por 'delimiter' en 'str'
int fill_array(const char *str, char delimiter, char **array) {
    size_t i = 0;
    while (*str) 
    {
        while (*str == delimiter) 
            str++; // Saltar delimitadores
        const char *start = str;
        while (*str && *str != delimiter) 
            str++; // Identificar palabra
        if (start != str) 
        { // Si hay una palabra
            size_t len = str - start;
            if (!(array[i] = allocate_word(start, len))) 
            { // Asignar y verificar error
                while (i > 0) free(array[--i]);
                return 1;
            }
            i++;
        }
    }
    array[i] = NULL;
    return 0;
}

// Dividir 's' en un array de palabras basado en el delimitador 'c'
char **ft_split(const char *s, char c) {
    if (!s) return NULL;
    char **result = malloc(sizeof(char *) * (count_words(s, c) + 1));
    if (!result || fill_array(s, c, result)) 
    {
        free(result);
        return NULL;
    }
    return result;
}
