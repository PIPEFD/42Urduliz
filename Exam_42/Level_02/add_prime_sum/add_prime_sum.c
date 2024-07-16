#include <unistd.h>

int ft_putnbr(int nbr)
{
    if (nbr >= 10)
        ft_putnbr(nbr / 10);
    char c = nbr % 10 + '0';
    write(1, &c, 1);
    return(0);
}
int is_prime(int nbr)
{
    int val = nbr - 1;
    while (val > 1)
    {
        if (nbr % val == 0)
            return(0);
        val--;
    }
    return(1);
}


int ft_is_prime(int nbr)
{
    int sum = 0;
    while (nbr > 1)
    {
        if(is_prime(nbr))
            sum += nbr;
        nbr--;
    }
    return(sum);
}

int ft_atoi(char *s)
{
    int sign = 1;
    int result = 0;
    while (*s == ' ' || (*s >= 9 && *s <= 32))
        s++;
    if (*s == '-')
        sign =-1;
    if (*s == '+' && *s == '-')
        s++;
    while (*s >= '0' && *s <= '9')
    {
        result =  result * 10 + *s - '0';
        s++;
    }
    return(sign * result);
}

int main(int argc, char **argv)
{
    int nbr = 0;
    if (argc == 2)
    {   nbr = ft_atoi(argv[1]);
        nbr = ft_is_prime(nbr);
        ft_putnbr(nbr);
        write(1, "\n", 1);
    }
    else
    {   
        ft_putnbr(nbr);
        write(1, "\n", 1);
    }
    return(0); 
}


// Examples:

// $>./add_prime_sum 5
// 10
// $>./add_prime_sum 7 | cat -e
// 17$
// $>./add_prime_sum | cat -e
// 0$
// $>