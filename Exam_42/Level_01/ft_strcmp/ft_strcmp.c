#include <stdio.h>
#include <string.h>


int ft_strcmp(char *s1, char *s2)
{
    int i = 0;
    while (s2[i] && (s1[i] == ' ' || s1[i] ==  '\t' || s1[i] == s2[i]))
        i++;
    return(s1[i] - s2[i]);
}

int main(void)
{
    char str[128] = "HO  LA";
    char str2[128] = "MUNDO";
    char str3[128] = "HO  LA";
    char str4[128] = "MUNDO";
    printf("result->> %i",ft_strcmp(str, str2));
    printf("result->> %i",strcmp(str3, str4));
    return(0);
}