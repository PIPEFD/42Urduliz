#include <unistd.h>



void expand_str(const char *s)
{
    int i;
    int flag = 0;

    i = 0;
    while (s[i] == ' ' || s[i] == '\t')
        i++;
    while (s[i])
    {
        if (s[i] == ' ' || s[i] == '\t')
            flag = 1;
        else
        {
            if (flag)
                write(1, "   ", 3);
            flag = 0;
            write(1, &s[i], 1);
        }
        i++;
    }
}

int main(int argc, char const **argv)
{
    if (argc == 2)
        expand_str(argv[1]);
    write(1, "\n", 1);
    return (0);
}


// Examples:

// $> ./expand_str "See? It's easy to print the same thing" | cat -e
// See?   It's   easy   to   print   the   same   thing$
// $> ./expand_str " this        time it      will     be    more complex  " | cat -e
// this   time   it   will   be   more   complex$
// $> ./expand_str "No S*** Sherlock..." "nAw S*** ShErLaWQ..." | cat -e
// $
// $> ./expand_str "" | cat -e
// $
// $>