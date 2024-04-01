#include <unistd.h>


// Función para convertir una cadena de caracteres a un entero
int ft_atoi(char *s)
{
    int n = 0;

    // Mientras el carácter actual sea un dígito
    while (*s >= '0' && *s <= '9')
    {
        n = n * 10; // Multiplica el número actual por 10 para agregar un nuevo dígito
        n = n + *s - '0'; // Agrega el dígito actual a la variable n
        ++s; // Avanza al siguiente carácter
    }
    return (n); // Devuelve el número entero obtenido
}

// Función para imprimir un número entero en la salida estándar
int ft_putnbr(int n)
{
    if (n >= 10)
        ft_putnbr(n / 10); // Llama a la función recursivamente para imprimir los dígitos restantes
    char c = (n % 10) + '0'; // Obtiene el carácter correspondiente al dígito de las unidades
    write(1, &c, 1); // Escribe el carácter en la salida estándar
}

// Función para imprimir la tabla de multiplicar de un número
void tab_mult(char *s)
{
    int i = 1;

    int n = ft_atoi(s); // Convierte la cadena de entrada en un número entero
    while (i <= 9)
    {
        ft_putnbr(i); // Imprime el multiplicador
        write(1, " x ", 3); // Imprime el símbolo de multiplicación
        ft_putnbr(n); // Imprime el multiplicando
        write(1, " = ", 3); // Imprime el símbolo de igualdad
        ft_putnbr(i * n); // Imprime el resultado de la multiplicación
        write(1, "\n", 1); // Salto de línea para la siguiente línea de la tabla
        ++i; // Incrementa el multiplicador
    }
}

int main(int argc, char **argv)
{
    if (argc == 2)
        tab_mult(argv[1]); // Llama a la función para imprimir la tabla de multiplicar
    else
        write(1, "\n", 1); // Si no se proporciona ningún argumento, imprime una nueva línea
    return (0); // Retorna 0 para indicar que el programa finalizó con éxito
}



