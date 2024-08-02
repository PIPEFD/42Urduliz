#include <unistd.h>


void hidenp(char *s1, char *s2)
{

    while(*s1 && s2)
    {
        if (*s1 ==  s2)
           s1++;
        s2++;
    }
    if(*s1 == '\0')
        write(1, "1", 1);
    else    
        write(1, "0", 1);
}

int main (int argc, char **argv)
{
    if (argc ==  3)
        hidenp(argv[1], argv[2]);
    write(1, "\n", 1);
    return(0);
}

// Examples :

// $>./hidenp "fgex.;" "tyf34gdgf;'ektufjhgdgex.;.;rtjynur6" | cat -e
// 1$
// $>./hidenp "abc" "2altrb53c.sse" | cat -e
// 1$
// $>./hidenp "abc" "btarc" | cat -e
// 0$
// $>./hidenp | cat -e
// $
// $>