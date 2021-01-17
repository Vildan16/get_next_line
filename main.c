#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
    int fd = open("file", O_RDONLY);
    char *line;
    int i;
    while ((i = get_next_line(fd, &line)))
    {
        printf("i = %d %s\n", i, line);
        free(line);
    }
    //printf("i = %d %s\n", i, line);
    //free(line);
    close(fd);
    return (0);
}