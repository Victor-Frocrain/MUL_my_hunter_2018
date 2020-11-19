/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "my.h"

int read_help(void)
{
    int fd = open("README", O_RDONLY);
    char *buff;

    if (fd < 0)
        return (MY_EXIT_ERROR);
    buff = malloc(sizeof(char) * SIZE_README);
    if (buff == NULL) {
        close(fd);
        return (MY_EXIT_ERROR);
    }
    read(fd, buff, SIZE_README);
    write(1, buff, SIZE_README);
    close(fd);
    free(buff);
    return (MY_EXIT_SUCCESS);
}

int main(int ac, char **av)
{
    sfVideoMode mode = {WIDTH, HEIGHT, 32};
    sfRenderWindow *window;

    if (ac == 2 && my_strcmp(av[1], "-h") == 0)
        return (read_help());
    window = sfRenderWindow_create
    (mode, "STAR WARS SHIPFIGHTER", sfResize | sfClose, NULL);
    if (!window)
        return (MY_EXIT_ERROR);
    game_loop(window);
    return (MY_EXIT_SUCCESS);
}
