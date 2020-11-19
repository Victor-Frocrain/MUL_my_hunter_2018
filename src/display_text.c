/*
** EPITECH PROJECT, 2018
** display_text
** File description:
** display_text
*/

#include "my.h"

void set_level(graph *s, float x, float y, int size)
{
    sfVector2f pos = {x, y};

    sfText_setString(s->disp->lvl, s->level);
    sfText_setFont(s->disp->lvl, s->font);
    sfText_setPosition(s->disp->lvl, pos);
    sfText_setColor(s->disp->lvl, sfYellow);
    sfText_setCharacterSize(s->disp->lvl, size);
}

void set_text(graph *s, char *str)
{
    sfVector2f pos = {640 - my_strlen(str) * 35, 250};

    sfText_setString(s->disp->best, str);
    sfText_setFont(s->disp->best, s->font);
    sfText_setPosition(s->disp->best, pos);
    sfText_setColor(s->disp->best, sfYellow);
    sfText_setCharacterSize(s->disp->best, 100);
    free(str);
}

void write_new_best(graph *s, char *buff)
{
    int fd = open("score", O_RDWR);
    char *score = convert_int_str(s->score);

    if (fd < 0)
        return;
    write(fd, score, my_strlen(score));
    buff = my_strcpy(buff, score);
    close(fd);
}

void read_best(graph *s)
{
    int red = 0;
    char *buff;
    int fd = open("score", O_RDWR);

    if (fd < 0)
        return;
    buff = malloc(sizeof(char) * 5);
    if (buff == NULL) {
        close(fd);
        return;
    }
    red = read(fd, buff, 4);
    close(fd);
    buff[red] = 0;
    if (my_getnbr(buff) < s->score)
        write_new_best(s, buff);
    set_text(s, buff);
}

void display_score(graph *s)
{
    char *str = convert_int_str(s->score);
    sfVector2f pos = {1335 - my_strlen(str) * 35, 250};

    sfText_setString(s->disp->score, str);
    sfText_setFont(s->disp->score, s->font);
    sfText_setPosition(s->disp->score, pos);
    sfText_setColor(s->disp->score, sfYellow);
    sfText_setCharacterSize(s->disp->score, 100);
    free(str);
}
