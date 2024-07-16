#include <unistd.h>
void rot_13(char *s)
{
    while (*s)
    {
      
        if (*s >= 'a' && *s <= 'z')          
            *s = ((*s - 'a' + 13) % 26) + 'a';
        else if (*s >= 'A' && *s <= 'Z')
            *s = ((*s - 'A' + 13) % 26) + 'A';
        write(1, &*s, 1);
        s++;
    }
}

int main (int argc, char **argv)
{
    if (argc == 2)
        rot_13(argv[1]);
    write(1, "\n", 1);
    return (0);
}



// #include <stdlib.h>
// #include <stdio.h>
// #include <unistd.h>

// int main (int argc, char **argv)
// {
//     if (argc == 4)
//     {
//         if (argv[2][0] == '+')
//             printf("%d", (atoi(argv[1]) + atoi(argv[3])));
//         else if (argv[2][0] == '-')
//             printf("%d", (atoi(argv[1]) - atoi(argv[3])));
//         else if (argv[2][0] == '/')
//             printf("%d", (atoi(argv[1]) / atoi(argv[3])));
//         else if (argv[2][0] == '*')
//             printf("%d", (atoi(argv[1]) * atoi(argv[3])));
//         else if (argv[2][0] == '%')
//             printf("%d", (atoi(argv[1]) % atoi(argv[3])));
//     }
//     printf("\n");
//     return(0);
// }