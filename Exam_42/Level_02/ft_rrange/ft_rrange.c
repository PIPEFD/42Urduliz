// #include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int ft_putnbr(int n) 
{
    if (n < 0) {
        write(1, "-", 1);
        n = -n;
    }
    if (n >= 10) 
        ft_putnbr(n / 10);
    char c = n % 10 + '0';
    write(1, &c, 1);
    return(0);
}

int ft_abs(int n)
{
    if (n < 0)
        return( n * -1);
    return (n);
}

int *ft_rrange(int start, int end) {
    int size = abs(end - start) + 1;

    int *range = (int *)malloc(size * sizeof(int));

    if (!range) 
        return NULL;

    int i = 0;
    if (start <= end) {
        while (i < size) 
        {
            range[i] = end - i;
            i++;
        }
    } else {
        while (i < size) {
            range[i] = end + i;
            i++;
        }
    }
    
    return range;
}

int ft_atoi(char *s)
{
    int sign = 1;
    int result = 0;

    while (*s == ' ' || (*s >= 9 && *s <= 32))
        s++;
    if (*s == '-')
        sign = -1;
    if (*s == '+' && *s == '-')
        s++;
    while(*s >= '0' && *s <= '9')
    {
        result = result  * 10 + *s - '0';
        s++;
    }
    return(sign * result);
}



int main(int argc, char **argv)
{
    int start;
    int end;
    int *range;
    int i;
    if (argc == 3)
    {
        start =  ft_atoi(argv[1]);
        end =  ft_atoi(argv[2]);
        range = ft_rrange(start, end); // Example values 1 to 5
        if (range)
        {
            i = 0;
            int size = ft_abs(end - start ) + 1; // Manually calculate size
            while(i < size) 
            {
                ft_putnbr(range[i]);
                write(1, " ", 1);
                i++;
            }
            write(1, "\n", 1);
            free(range);
        }
    }
    else 
         write(1, "\n", 1);
    return 0;
}

