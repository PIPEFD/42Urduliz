#include <unistd.h>

int ft_strchr(char *s, char c)
{
    while (*s)
    {
        if(*s == c)
            return(1);
        else
            s++;
    }    
    return(0);
}

void ft_union(char *s1, char *s2)
{
    char see[256] = {0};
    int i = 0;
    while (*s1)
    {
        if(!ft_strchr(see, *s1))
        {
            write(1, s1, 1);
            see[i] = *s1;
            s1++;
        }
    }
    while (*s2)
    {
        if(!ft_strchr(see, *s2))
        {
            write(1, s2, 1);
            see[i] = *s2;
            i++;
        }
        s2++;
    }
}

int main (int argc, char **argv)
{
    if (argc == 3)
        ft_union(argv[1], argv[2]);
    write(1, "\n", 1);
    return(0);
}