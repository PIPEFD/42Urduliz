#include <unistd.h>

int ft_putnbr(int nbr)
{
    if (nbr >= 10)
        ft_putnbr(nbr / 10);
    char c =  nbr % 10 + '0';
    write(1, &c, 1);
    return(0);
}

void tab_mult(int nbr)
{
    int  i = 1;
    while (i < 10)
    {
        ft_putnbr(i);
        write(1, " x ", 3);
        ft_putnbr(nbr);
        write(1, " = ", 3);
        ft_putnbr(i * nbr);
        write(1, "\n", 1);
        i++;
    }
}


int ft_atoi(char *s)
{
    int sign = 1;
    int result  = 0;
    while(*s == ' ' || (*s >= 9 && *s<= 32))
        s++;
    if(*s == '-')
        sign = -1;
    if (*s  == '-' || *s == '+')
        s++;
    while(*s >= '0' && *s <= '9')
    {
        result  = result * 10 + *s - '0';
        s++;
    }
    return(sign * result);
}
int main (int argc, char **argv)
{
    if (argc == 2)
        tab_mult((ft_atoi(argv[1])));
    else
        write(1, "\n", 1);
    return(0);
}