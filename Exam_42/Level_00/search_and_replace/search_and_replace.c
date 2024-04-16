#include <unistd.h>

// 🔍 Función para buscar y reemplazar un carácter en una cadena
void search_and_replace(char *s1, char *s2, char *s3)
{
    if (s2[1] == '\0' && s3[1] == '\0') // 🔍 Verifica que s2 y s3 sean caracteres individuales
    {
        while (*s1) // 🔁 Recorre la cadena s1
        {
            if (*s1 == *s2) // 🔍 Busca el carácter a reemplazar
                *s1 = *s3; // 🔁 Reemplaza el carácter
            write(1, &*s1, 1); // 🔠 Escribe el carácter modificado en stdout
            s1++;
        }
    }
}

int main(int argc, char **argv)
{
    if (argc == 4) // 🔍 Verifica si se proporcionaron tres argumentos
        search_and_replace(argv[1], argv[2], argv[3]); // 🔍 Llama a la función para buscar y reemplazar
    write(1, "\n", 1); // 🔠 Imprime una nueva línea en stdout
    return 0;
}