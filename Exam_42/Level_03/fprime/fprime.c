#include <stdio.h>
#include <stdlib.h>

int fprime(int nbr)
{
    int i = 1;

    if (nbr == 1)
        printf("1");
    while (nbr >= ++i)
    {
        if (nbr % i == 0)
        {
            printf("%d", i);
            if (nbr == i)
                break;
            printf("*");
            nbr /= i;
            i = 1;
        }
    }
    return(0);
}

int main(int argc, char **argv)
{

    if (argc == 2)
        fprime(atoi(argv[1]));
    printf("\n");
    return (0);
}