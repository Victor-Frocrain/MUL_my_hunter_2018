/*
** EPITECH PROJECT, 2018
** change_buttons
** File description:
** change_buttons
*/

#include "my.h"

void change_button_resume(sfRenderWindow *window, graph *s)
{
    sfIntRect resume = {0, 305 / 2, 305, 305 / 2};
    sfVector2i posi = sfMouse_getPositionRenderWindow(window);
    sfVector2f posf;
    float button_x = 1920 / 2 - (305 / 2 * 1.2);
    float button_y = 1080 / 2 - 150;

    posf.x = (float)posi.x;
    posf.y = (float)posi.y;
    if (posf.x >= button_x && posf.x <= button_x + 305 * 1.2 &&
    posf.y >= button_y && posf.y <= button_y + (305 / 2) * 1.2) {
        resume.top = 0;
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
            sfMouse_setPositionRenderWindow(s->mouse_pos, window);
            s->pause = false;
        }
    }
    else
        resume.top = 305 / 2;
    sfSprite_setTextureRect(s->sp->button_resume, resume);
}

void change_button_exit(sfRenderWindow *window, graph *s,
float button_x, float button_y)
{
    sfIntRect quit = {0, 305 / 2, 305, 305 / 2};
    sfVector2i posi = sfMouse_getPositionRenderWindow(window);
    sfVector2f posf;

    posf.x = (float)posi.x;
    posf.y = (float)posi.y;
    if (posf.x >= button_x && posf.x <= button_x + 305 * 1.2 &&
    posf.y >= button_y && posf.y <= button_y + (305 / 2) * 1.2) {
        quit.top = 0;
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
            s->exit = true;
    }
    else
        quit.top = 305 / 2;
    sfSprite_setTextureRect(s->sp->button_exit, quit);
}

void change_button_play(sfRenderWindow *window, graph *s)
{
    sfIntRect play = {0, 305 / 2, 305, 305 / 2};
    sfVector2i posi = sfMouse_getPositionRenderWindow(window);
    sfVector2f posf;
    float button_x = 1235;
    float button_y = 500;

    posf.x = (float)posi.x;
    posf.y = (float)posi.y;
    if (posf.x >= button_x && posf.x <= button_x + 305 * 1.2 &&
    posf.y >= button_y && posf.y <= button_y + (305 / 2) * 1.2) {
        play.top = 0;
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
            s->begin = false;
            sfMusic_stop(s->mus->main);
            sfMusic_play(s->mus->battle);
        }
    }
    else
        play.top = 305 / 2;
    sfSprite_setTextureRect(s->sp->button_play, play);
}

void change_button_retry(sfRenderWindow *window, graph *s)
{
    sfIntRect retry = {0, 305 / 2, 305, 305 / 2};
    sfVector2i posi = sfMouse_getPositionRenderWindow(window);
    sfVector2f posf;
    float button_x = 450;
    float button_y = 1080 / 1.56;

    posf.x = (float)posi.x;
    posf.y = (float)posi.y;
    if (posf.x >= button_x && posf.x <= button_x + 305 * 1.2 &&
    posf.y >= button_y && posf.y <= button_y + (305 / 2) * 1.2) {
        retry.top = 0;
        check_if_retry(s);
    }
    else
        retry.top = 305 / 2;
    sfSprite_setTextureRect(s->sp->retry, retry);
}
