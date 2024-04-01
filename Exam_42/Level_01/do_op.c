#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

// ➕➖✖️➗✅ Función para realizar operaciones aritméticas básicas
int do_op(char *n1, char *sign, char *n3)
{
    // 🧮 Convierte los números de cadena a enteros
    int number1 = atoi(n1);
    int number3 = atoi(n3);

    // 🔁 Realiza la operación mientras ambos números sean diferentes de cero
    while (number1 && number3)
    {
        // 🔍 Verifica el signo de la operación y realiza la operación correspondiente
        if (*sign == '+')
            return(printf("%d", (number1 + number3))); // ➕ Imprime la suma
        else if (*sign == '-')
            return(printf("%d", (number1 - number3))); // ➖ Imprime la resta
        else if (*sign == '*')
            return(printf("%d", (number1 * number3))); // ✖️ Imprime la multiplicación
        else if (*sign == '/')
            return(printf("%d", (number1 / number3))); // ➗ Imprime la división
        else if (*sign == '%')
            return(printf("%d", (number1 % number3))); // ✅ Imprime el residuo de la división
    }
    return(0);
}

int main (int argc, char **argv)
{
    // 🔍 Verifica si se proporcionaron tres argumentos
    if (argc == 4)
        do_op(argv[1],argv[2],argv[3]); // 🔄 Llama a la función para realizar la operación
    printf("\n"); // 🔠 Imprime una nueva línea
    return(0);
}
