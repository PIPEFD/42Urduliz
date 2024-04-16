/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:37:49 by codespace         #+#    #+#             */
/*   Updated: 2024/04/16 16:40:04 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
// 📏 Función para obtener el tamaño del array resultante
static size_t	get_tab_size(const char *s, char c)
{
    size_t	cnt;

    cnt = 0;
    while (*s && s++) // 🔁 Mientras no se llegue al final de la cadena
    {
        while (*s != c && *s) // 🔍 Busca el carácter delimitador
            s++;
        cnt++; // ➕ Incrementa el contador
        while (*s == c && *s) // 🔍 Busca el siguiente carácter no delimitador
            s++;
    }
    return (cnt); // 📤 Devuelve el contador
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	char	*pt_src;

	pt_src = (char *)src;
	i = 0;
	if (size > 0)
	{
		while (pt_src[i] != '\0' && i < size - 1)
		{
			dst[i] = pt_src[i];
			i++;
		}
		dst[i] = 0;
	}
	while (src[i])
		i++;
	return (i);
}

// 🖊️ Función para llenar el array resultante
static int	fill_tab(char const *s, char c, char **tab)
{
    size_t	i;
    size_t	len;

    i = 0;
    while (*s) // 🔁 Mientras no se llegue al final de la cadena
    {
        len = 0;
        while (*s != c && *s && ++s) // 🔍 Busca el carácter delimitador y cuenta la longitud de la subcadena
            len++;
        tab[i] = malloc(len + 1); // 🧠 Asigna memoria para la subcadena
        if (!tab[i]) // ❗ Si la asignación falla
        {
            while (i) // 🔁 Libera la memoria ya asignada
                free(tab[--i]);
            free(tab);
            return (1); // ❌ Devuelve un error
        }
        ft_strlcpy(tab[i++], s - len, len + 1); // 📝 Copia la subcadena al array
        while (*s == c && *s) // 🔍 Busca el siguiente carácter no delimitador
            s++;
    }
    tab[i] = 0; // 📝 Termina el array con un puntero nulo
    return (0); // ✅ Devuelve éxito
}

// 📦 Función principal para dividir la cadena
char	**ft_split(const char *s, char c)
{
    char	**tab;

    if (!s) // ❗ Si la cadena es nula
        return (NULL); // ❌ Devuelve un error
    while (*s == c && *s) // 🔍 Busca el primer carácter no delimitador
        s++;
    tab = (char **)malloc(sizeof(char *) * (get_tab_size(s, c) + 1)); // 🧠 Asigna memoria para el array resultante
    if (!tab) // ❗ Si la asignación falla
        return (NULL); // ❌ Devuelve un error
    if (fill_tab(s, c, tab)) // 🖊️ Llena el array
        return (NULL); // ❌ Devuelve un error si la función falla
    return (tab); // 📤 Devuelve el array resultante
}