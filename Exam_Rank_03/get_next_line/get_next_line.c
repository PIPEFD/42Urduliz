#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>



char *ft_strdup(char *str)
{
    int i = 0;

    if (!str)
        return(NULL);
    while(str[i])
        i++;
    char *dst = (char *)malloc(sizeof(char) * (i + 1));
    i = -1;
    while(str[++i])
        dst[i] = str[i];
    dst[i] = '\0';
    return(dst);
}


char *get_next_line(int fd)
{
    char line[70000];
    static char buffer[BUFFER_SIZE];
    static int buffer_readed;
    static int buffer_pos;
    int i;

    i = 0;
    if (fd < 0 || BUFFER_SIZE <= 0)
        return(NULL);
    while(1)
    {
        if(buffer_pos >= buffer_readed)
        {
            buffer_readed = read(fd, buffer, BUFFER_SIZE);
            buffer_pos = 0;
            if(buffer_readed <= 0)
                break;
        }
        line[i++] = buffer[buffer_pos++];
        if (line[i -1] == '\n')
            break;
    }
    line[i] = '\0';
    if (i == 0)
        return(NULL);
    return(ft_strdup(line));
}
int main(int argc, char **argv)
{
    int fd;
    char *line;

    if(argc != 2)
    {
        printf("Can't read file %s\n", argv[0]);
        return(1);
    }
    fd = open(argv[1], O_RDONLY);
    if(fd == -1)
    {
        printf("Error en el archivo\n");
        return(1);
    }
    while((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    printf("\n");
    close(fd);
    return(0);    
}

// gcc -Wall -Wextra -Werror -D BUFFER_SIZE=1 -fsanitize=address -g3 get_next_line.c -o get_next_line