/*
** EPITECH PROJECT, 2018
** manage_mouse
** File description:
** manage_mouse
*/

#include "my.h"

void detect_unclick(graph *s)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
        if (s->click == false)
            sfMusic_play(s->mus->fire);
        s->click = true;
    }
    else if (sfMouse_isButtonPressed(sfMouseLeft) == sfFalse)
        s->click = false;
}

void check_level(graph *s)
{
    int lvl = s->score / 10;

    if (lvl * 10 == s->score) {
        if (s->level != NULL)
            free(s->level);
        s->level = convert_int_str(1 + s->score / 10);
        s->life = 3;
        s->rect->lifebar.left = 0;
        s->pos->life.x = 1480;
        s->pos->life_tip.x = 1480 - 33;
        sfSprite_setPosition(s->sp->lifebar, s->pos->life);
        sfSprite_setPosition(s->sp->lifebar_tip, s->pos->life_tip);
        sfSprite_setTextureRect(s->sp->lifebar, s->rect->lifebar);
    }
}

bool detect_shoot(sfRenderWindow *window, sfVector2i mousei, graph *s)
{
    sfVector2f ship = sfSprite_getPosition(s->sp->ship);
    sfVector2f mousef = {(float)mousei.x, (float)mousei.y};

    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue &&
    mousef.x < ship.x + 196.8 && mousef.x > ship.x &&
    mousef.y < ship.y + 76.8 && mousef.y > ship.y &&
    s->click == false) {
        s->destroy = true;
        s->click = true;
        s->speed += 0.2;
        if (s->score < 9999)
            s->score++;
        check_level(s);
        sfMusic_play(s->mus->fire);
        return (true);
    }
    else
        detect_unclick(s);
    return (false);
}

void move_mouse(sfRenderWindow *window, graph *s)
{
    sfVector2i posi = sfMouse_getPositionRenderWindow(window);
    sfVector2f posf;

    if (s->life > 0 && s->begin == false && s->pause == false) {
        posf.x = (float)(posi.x - 85 / 2);
        posf.y = (float)(posi.y - 87 / 2);
        sfSprite_setPosition(s->sp->target, posf);
    }
    else {
        posf.x = (float)posi.x;
        posf.y = (float)posi.y;
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
            s->rect->mouse_menu.left = 1766 / 2;
        else
            s->rect->mouse_menu.left = 0;
        sfSprite_setTextureRect(s->sp->mouse_menu, s->rect->mouse_menu);
        sfSprite_setPosition(s->sp->mouse_menu, posf);
    }
}
