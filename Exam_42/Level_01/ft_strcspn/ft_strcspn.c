#include <string.h>
#include <stdio.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
    size_t i = 0;
    int k = 0;
    while (s[i] != '\0')
    {
        while (reject[k] != '\0')
        {
            if(s[i] ==  reject[k])
                return(i);
            k++;
        }
        k = 0;
        i++;
        
    }
    return(i);
}



int main(void)
{
    char str[128] = "HO dasdas LA";
    char str2[128] = "MUND";
    char str3[128] = "HO dasdas LA";
    char str4[128] = "MUND";
    printf("result->> %li",ft_strcspn(str, str2));
    printf("result->> %li",strcspn(str3, str4));
    return(0);
}   
