#include <stdio.h>
#include <string.h>


char *ft_strpbrk(const char *s1, const char *s2)
{
    int i = 0;
    if (!s1 || !s2)
        return(0);
    while(*s1 != '\0')
    {
        i = 0;
        while(s2[i])
        {
            if (*s1 == s2[i])
                return((char *)s1);
            i++;
        }

        s1++;
    }
    return(NULL);
}
int main ()
{
    char str[128] = "HOLA";
    char str2[128] = "MUNDA";
    char str3[128] = "HOLA";
    char str4[128] = "MUNDA";
    printf("result->> %s\n", ft_strpbrk(str, str2));
    printf("result->> %s\n", strpbrk(str3, str4));
    return(0);

}