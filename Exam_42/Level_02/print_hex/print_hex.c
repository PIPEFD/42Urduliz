#include <unistd.h>
#include <stdio.h>


int print_hex(int nbr)
{
    char characters[] =  "0123456789abcdef";
    printf("print_hex --> nbr %i\n", nbr);

    if (nbr >= 16)
        print_hex(nbr / 16);
    write(1, &characters[nbr % 16], 1);
    return(0);
}

int ft_atoi(char *s)
{
    int sign = 1;
    int result  = 0;

    while (*s == ' '  || (*s >=  9 && *s <= 32))
        s++;
    if (*s == '-')
        sign = -1;
    if (*s == '-' || *s == '+')
        s++;
    while(*s >= '0' && *s <= '9')
    {
        result = result  *  10  + *s - '0';
        s++;
    }
    printf("ft_atoi --> resul %i\n", result);
    return(sign * result);
}


int main (int argc, char **argv)
{
    if (argc == 2)
        print_hex(ft_atoi(argv[1]));
    write(1, "\n", 1);
    return(0);
}