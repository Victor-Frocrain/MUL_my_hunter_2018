/*
** EPITECH PROJECT, 2018
** manage_pause
** File description:
** manage_pause
*/

#include "my.h"

void manage_pause(sfRenderWindow *window, graph *s)
{
    sfVector2f exit_pos = {1920 / 2 - (305 / 2 * 1.2), 1080 / 2 + 100};

    if (sfKeyboard_isKeyPressed(sfKeyEscape) == true &&
    s->pause == false && s->escape_released == true) {
        s->pause = true;
        sfSprite_setPosition(s->sp->button_exit, exit_pos);
        s->escape_released = false;
        s->mouse_pos = sfMouse_getPositionRenderWindow(window);
    }
    else if (sfKeyboard_isKeyPressed(sfKeyEscape) &&
    s->escape_released == true) {
        s->pause = false;
        s->escape_released = false;
        sfMouse_setPositionRenderWindow(s->mouse_pos, window);
    }
    if (sfKeyboard_isKeyPressed(sfKeyEscape) == false)
        s->escape_released = true;
}
