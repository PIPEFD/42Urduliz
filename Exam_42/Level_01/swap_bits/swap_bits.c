#include <stdio.h>

unsigned char swap_bits(unsigned char c) 
{
    return ((c >> 4) | (c << 4));
}

int ft_atoi(char *s)
{
    int sign =  1;
    int result = 0;

    while (*s == ' ' || (*s >= 9 && *s <=  32))
            s++;
    if (*s == '-')
        sign  = -1;
    if ( *s == '-' ||* s == '+')
        s++;
    while (* s >= '0' && *s <= '9')
    {
        result = result * 10 + *s + '0';
        s++;
    }
    return(sign * result);
}

int ft_isdigit(char s)
{
    if (s >=  '0' && s <= '9')
        return(1);
    else 
        return (0);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <number or character>\n", argv[0]);
        return 1;
    }

    unsigned char num;
    
    if (ft_isdigit(argv[1][0]) || (argv[1][0] == '-' && ft_isdigit(argv[1][1])))
        num = (unsigned char) ft_atoi(argv[1]);
    else 
        num = argv[1][0]; 

    printf("Original byte: %u (binary: %02x)\n", num, num);
    unsigned char swapped = swap_bits(num);
    printf("Swapped byte: %u (binary: %02x)\n", swapped, swapped);
    return 0;
}
