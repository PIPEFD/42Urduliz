#include <unistd.h>

// 🔍 Función para buscar y reemplazar un carácter en una cadena
void search_and_replace(char *s1, char *s2, char *s3)
{
    if (s2[1] == '\0' && s3[1] == '\0') 
    {
        while (*s1)
        {
            if (*s1 == *s2)
                *s1 = *s3;
            write(1, &*s1, 1);
            s1++;
        }
    }
}

int main(int argc, char **argv)
{
    if (argc == 4)
        search_and_replace(argv[1], argv[2], argv[3]);
    write(1, "\n", 1);
    return 0;
}