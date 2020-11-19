/*
** EPITECH PROJECT, 2018
** manage_ships
** File description:
** manage_ships
*/

#include "my.h"

void res_ship(graph *s)
{
    sfVector2f scale_ship = {0.6, 0.6};

    s->rect->explosion.left = 0;
    s->rect->explosion.top = 0;
    s->pos->ship.x = -197;
    srand(time(NULL));
    s->pos->ship.y = rand() % 850;
    sfSprite_setScale(s->sp->ship, scale_ship);
    sfSprite_setTexture(s->sp->ship, s->tex->ship, sfTrue);
    sfSprite_setPosition(s->sp->ship, s->pos->ship);
    s->destroy = false;
}

void spray_ship(graph *s)
{
    sfSprite_setTexture(s->sp->ship, s->tex->explose, sfFalse);
    if (sfTime_asMilliseconds(sfClock_getElapsedTime
    (s->clock->explose)) >= 50) {
        sfSprite_setTextureRect(s->sp->ship, s->rect->explosion);
        if (s->rect->explosion.left < 512)
            s->rect->explosion.left += 768 / 3;
        else {
            s->rect->explosion.left = 0;
            s->rect->explosion.top += 512 / 4;
        }
        if (s->rect->explosion.top > 384)
            res_ship(s);
        sfClock_restart(s->clock->explose);
    }
}

void move_ship(sfRenderWindow *window, graph *s)
{
    if (s->pos->ship.x < 1920 &&
        detect_shoot(window,
        sfMouse_getPositionRenderWindow(window),
        s) == false)
        s->pos->ship.x += s->speed * sfTime_asMilliseconds
        (sfClock_getElapsedTime(s->clock->move));
    else if (s->pos->ship.x >= 1920) {
        s->life--;
        s->rect->lifebar.left += 419 / 3;
        s->pos->life.x += 419 / 3;
        s->pos->life_tip.x += 418 / 3;
        sfSprite_setPosition(s->sp->lifebar, s->pos->life);
        sfSprite_setPosition(s->sp->lifebar_tip, s->pos->life_tip);
        sfSprite_setTextureRect(s->sp->lifebar, s->rect->lifebar);
        s->pos->ship.x = -197;
        srand(time(NULL));
        s->pos->ship.y = rand() % 850;
    }
    sfSprite_setPosition(s->sp->ship, s->pos->ship);
}
