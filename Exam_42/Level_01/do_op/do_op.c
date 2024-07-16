#include <stdio.h>




int ft_atoi (char *s)
{
    int sign = 1;
    int result = 0;

    while (*s ==  ' ' && (*s >= '0' && *s <= '9'))
        s++;
    if (*s == '-')
        sign = -1;
    if (*s == '-' || *s == '+')
        s++;
    while(*s >= '0' && *s <= '9')
    {
        result = result * 10 + *s - '0';
        s++;
    }
    return(sign * result);

}


// ➕➖✖️➗✅ Función para realizar operaciones aritméticas básicas
int do_op(char *n1, char *sign, char *n3)
{
    int number1 = ft_atoi(n1);
    int number3 = ft_atoi(n3);

    while (number1 && number3)
    {

        if (*sign == '+')
            return(printf("%d", (number1 + number3))); // ➕ Imprime la suma
        else if (*sign == '-')
            return(printf("%d", (number1 - number3))); // ➖ Imprime la resta
        else if (*sign == '*')
            return(printf("%d", (number1 * number3))); // ✖️ Imprime la multiplicación
        else if (*sign == '/')
            return(printf("%d", (number1 / number3))); // ➗ Imprime la división
        else if (*sign == '%')
            return(printf("%d", (number1 % number3))); // ✅ Imprime el modulo de la división
    }
    return(0);
}

int main (int argc, char **argv)
{
    if (argc == 4)
        do_op(argv[1],argv[2],argv[3]);
    printf("\n");
    return(0);
}
