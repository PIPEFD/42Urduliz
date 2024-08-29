#include <unistd.h>

// Función 'rostring' que maneja la lógica principal
void rostring(char *str) {
    int i = 0;
    int j;

    // Bucle para saltar espacios iniciales
    while (str[i] && (str[i] == ' ' || str[i] == '\t')) {
        i++;
    }
    j = i;  // Posición inicial de la primera palabra

    // Bucle para manejar las palabras y su impresión
    while (str[i]) {
        while (str[i] && (str[i] != ' ' && str[i] != '\t')) {  // Encuentra la siguiente palabra
            i++;
        }
        while (str[i] && (str[i] == ' ' || str[i] == '\t')) {  // Salta espacios entre palabras
            i++;
        }
        while (str[i] && (str[i] != ' ' && str[i] != '\t') \
            && (str[i - 1] == ' ' || str[i - 1] == '\t')) 
        {
            while (str[i] && (str[i] != ' ' && str[i] != '\t')) {
                write(1, &str[i], 1);
                i++;
            }
            write(1, " ", 1);
        }
    }

    // Imprimir la primera palabra después de haber impreso el resto
    while (str[j] && (str[j] != ' ' && str[j] != '\t')) {
        write(1, &str[j], 1);
        j++;
    }
    write(1, "\n", 1);  // Nueva línea al final
}

// Función 'main' modificada para usar 'rostring'
int main(int ac, char **av) {
    if (ac >= 2) {
        rostring(av[1]);
    }
    return 0;
}
