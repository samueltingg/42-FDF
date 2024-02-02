#include ".././includes/fdf.h"
/**
 * returns line_count of an open file.
 * - run gnl until it return NULL, to get number of lines in file
*/
int get_line_count(int fd)
{
    char *input;
    int line_count;

    line_count = 0;
    while (1)
    {
        input = get_next_line(fd);
        if (input == NULL)
            break;
        line_count++;
    }
    close(fd);
    return (line_count);
}

// int main(void)
// {
//     int fd;
//     fd = open(".././maps/42.fdf", O_RDONLY);
//     if (fd == -1) {
//         perror("Unable to open the file");
//         return 1;
//     }
//     printf("Number of lines: %d\n", get_line_count(fd));
// }
