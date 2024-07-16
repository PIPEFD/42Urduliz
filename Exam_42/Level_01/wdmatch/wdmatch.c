#include <unistd.h>


void ft_putchar(char c)
{
    write (1, &c, 1);
}

void ft_putstr(char *s)
{
    while (*s != '\0')
    {
        ft_putchar(*s);
        s++;
    }
}



char wdmatch(char *s1, char *s2)
{
    while (*s2)
    {
        if (*s1 == *s2)
            s1++;
        s2++;
    }
    return(*s1 == '\0');
}



int main(int argc, char **argv)
{
    if (argc == 3)
    {
        if (wdmatch(argv[1], argv[2]))
            ft_putstr(argv[1]);
    }
    ft_putstr("\n");
    return(0);
}