#include <stdlib.h>
// #include <string.h>
// #include <stdio.h>
int ft_strlen(char *s)
{
    int i = 0;
    int count = 0;
    while (s[i] != '\0')
    {
        i++;
        count++;
    }
    return(count);
}
char *ft_strdup(char *src)
{
    int i = 0;
    int len = ft_strlen(src);
    char *new = malloc(sizeof (char *)* len + 1);
    if (!new)
        return(NULL);
    while (src[i] && i < len)
    {
        new[i] = src[i];
        i++;
    }
    new[i] = src[i];
    return(new);
}


// int main (void)
// {
//     char *str = "";
//     printf("result->> %s\n", ft_strdup(str));
//     printf("result->> %s\n", strdup(str));

//     return(0);
// }