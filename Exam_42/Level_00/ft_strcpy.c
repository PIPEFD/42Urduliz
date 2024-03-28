/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 22:15:57 by codespace         #+#    #+#             */
/*   Updated: 2024/03/28 22:15:58 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Función personalizada para copiar una cadena de caracteres (s2) en otra (s1)
char *ft_strcpy(char *s1, char *s2)
{
    int i = 0;

    // 🔄 Recorre la cadena s2 hasta llegar al final
    while (s2[i])
    {
        // 📌 Copia el carácter actual de s2 en la misma posición de s1
        s1[i] = s2[i];
        i++; // ➡️ Incrementa el índice para avanzar al siguiente carácter
    }

    // 📌 Agrega el carácter nulo al final de s1 para marcar el final de la cadena
    s1[i] = '\0';

    // ✅ Devuelve un puntero a la cadena s1 (que ahora contiene la copia de s2)
    return (s1);
}


// int main(void)
// {
//     char str1[6] = "HOLA";
//     char srt2[6] = "MUNDO";
//     char str3[6] = "HOLA";
//     char srt4[6] = "MUNDO";

//     printf("%s\n",(ft_strcpy(str1, srt2)));
//     printf("%s",(strcpy(str3, srt4)));


//     return(0);
// }