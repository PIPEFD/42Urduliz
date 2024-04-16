

#include <string.h>
#include <stdio.h>

int ft_strlen(char *s)
{
    int size = 0;
    while (*s != '\0')
    {
        s++;
        size++;
    }
    return (size);
}

// int main (void)
// {
//     char str[] = "Hello World!";
//     printf("%d\n", ft_strlen(str));
//     printf("%ld\n", strlen(str));
    
// }