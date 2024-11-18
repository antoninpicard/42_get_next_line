#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"
#include <stdlib.h>

void	free_stash(char **stash)
{
    if (*stash)
    {
        free(*stash);
        *stash = NULL;
    }
}

void	test_gnl(const char *filename)
{
    int		fd;
    char	*line;

    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return ;
    }
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
}

int	main(void)
{
    static char	*stash = NULL;

    printf("=== Test avec test.txt ===\n");
    test_gnl("1char.txt");
    free_stash(&stash); // Libérez `stash` pour éviter les fuites de mémoire
    return (0);
}

