#include <unistd.h>


int ft_strchr(char  *s, char c)
{
    while (*s)
    {
        if (*s == c)
            return(1);
        else
            s++;
    }
    return(0);
}


void inter (char *s1, char *s2)
{
    int  i = 0;
    char printed[128] = {0};

    while (*s1)
    {
        if(ft_strchr(s2, *s1) && !ft_strchr(printed, *s1))
        {
            write(1, s1, 1);
            printed[i] = *s1;
            i++;
        }
        s1++;
    }
}


int main (int argc, char **argv)
{
    if (argc == 3)
        inter(argv[1], argv[2]);
    write(1, "\n", 1);
    return(0);
}