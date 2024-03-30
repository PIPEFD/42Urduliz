#include <unistd.h>

// Función para cifrar una cadena utilizando el cifrado ROT13
void rot_13(char *s)
{
    int i = 0;
    // 🔄 Itera sobre la cadena hasta encontrar el carácter nulo que indica el final de la cadena
    while (s[i])
    {
        // 📌 Si el carácter es una letra minúscula
        if (s[i] >= 'a' && s[i] <= 'z')
            // 🔠 Aplica el cifrado ROT13 (desplazamiento de 13 posiciones en el alfabeto)
            s[i] = ((s[i] - 'a' + 13) % 26) + 'a';
        // 📌 Si el carácter es una letra mayúscula
        else if (s[i] >= 'A' && s[i] <= 'Z')
            // 🔠 Aplica el cifrado ROT13 (desplazamiento de 13 posiciones en el alfabeto)
            s[i] = ((s[i] - 'A' + 13) % 26) + 'A';
        // ✍️ Escribe el carácter cifrado en la salida estándar
        write(1, &s[i], 1);
        // ➡️ Incrementa el índice para pasar al siguiente carácter
        i++;
    }
}

int main (int argc, char **argv)
{
    // 🔍 Verifica si se proporcionó un argumento al programa
    if (argc == 2)
        // 🔄 Llama a la función rot_13 con el primer argumento como entrada
        rot_13(argv[1]);
    // ✏️ Escribe un salto de línea en la salida estándar
    write(1, "\n", 1);
    return (0);
}



// #include <stdlib.h>
// #include <stdio.h>
// #include <unistd.h>

// int main (int argc, char **argv)
// {
//     if (argc == 4)
//     {
//         if (argv[2][0] == '+')
//             printf("%d", (atoi(argv[1]) + atoi(argv[3])));
//         else if (argv[2][0] == '-')
//             printf("%d", (atoi(argv[1]) - atoi(argv[3])));
//         else if (argv[2][0] == '/')
//             printf("%d", (atoi(argv[1]) / atoi(argv[3])));
//         else if (argv[2][0] == '*')
//             printf("%d", (atoi(argv[1]) * atoi(argv[3])));
//         else if (argv[2][0] == '%')
//             printf("%d", (atoi(argv[1]) % atoi(argv[3])));
//     }
//     printf("\n");
//     return(0);
// }