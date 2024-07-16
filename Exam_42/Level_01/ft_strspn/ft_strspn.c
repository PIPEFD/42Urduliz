#include <stdio.h>
#include <string.h>



char *ft_strchr(const char *s, int c)
{
    while (*s != '\0')
    {
        if (*s == c)
            return((char *)s);
        s++;
    }
    return(0);
}


size_t	ft_strspn(const char *s, const char *accept)
{

    size_t  i = 0;
    while (s[i] != '\0')
    {
        if(ft_strchr(accept, s[i]) == 0)
            break;
        i++;
    }
    return(i);
}

int main(void)
{
    char str[128] = "HOLA";
    char str2[128] = "MUNDO";
    char str3[128] = "HOLA";
    char str4[128] = "MUNDO";
    printf("result->> %li\n",ft_strspn(str, str2));
    printf("result->> %li\n",strspn(str3, str4));
    return(0);
}
