/*
** EPITECH PROJECT, 2018
** init_sprites
** File description:
** init_sprites
*/

#include "my.h"

void create_sprite(graph *s)
{
    s->sp->background = sfSprite_create();
    s->sp->ship = sfSprite_create();
    s->sp->target = sfSprite_create();
    s->sp->backscore = sfSprite_create();
    s->sp->mouse = sfSprite_create();
    s->sp->lifebar = sfSprite_create();
    s->sp->lifebar_tip = sfSprite_create();
    s->sp->mouse_menu = sfSprite_create();
    s->sp->pause = sfSprite_create();
    s->sp->retry = sfSprite_create();
    s->sp->main = sfSprite_create();
    s->sp->button_play = sfSprite_create();
    s->sp->button_exit = sfSprite_create();
    s->sp->button_resume = sfSprite_create();
}

void destroy_sprites(graph *s)
{
    sfSprite_destroy(s->sp->background);
    sfSprite_destroy(s->sp->target);
    sfSprite_destroy(s->sp->ship);
    sfSprite_destroy(s->sp->backscore);
    sfSprite_destroy(s->sp->mouse);
    sfSprite_destroy(s->sp->lifebar);
    sfSprite_destroy(s->sp->lifebar_tip);
    sfSprite_destroy(s->sp->mouse_menu);
    sfSprite_destroy(s->sp->pause);
    sfSprite_destroy(s->sp->retry);
    sfSprite_destroy(s->sp->main);
    sfSprite_destroy(s->sp->button_play);
    sfSprite_destroy(s->sp->button_exit);
    sfSprite_destroy(s->sp->button_resume);
}

void init_pictures3(graph *s)
{
    sfVector2f scale_button = {1.2, 1.2};
    sfVector2f resume_pos = {1920 / 2 - (305 / 2 * 1.2), 1080 / 2 - 150};

    sfSprite_setScale(s->sp->button_resume, scale_button);
    sfSprite_setPosition(s->sp->button_resume, resume_pos);
    sfSprite_setTexture(s->sp->button_resume, s->tex->button_resume, sfFalse);
}

void init_pictures2(graph *s)
{
    sfVector2f scale_mouse_menu = {0.2, 0.2};
    sfVector2f scale_button = {1.2, 1.2};
    sfVector2f retry_pos = {450, 1080 / 1.56};
    sfVector2f play_pos = {1235, 500};
    sfVector2f exit_pos = {1235, 500 + (305 / 2 * 1.2) + 25};

    sfSprite_setScale(s->sp->mouse_menu, scale_mouse_menu);
    sfSprite_setTexture(s->sp->mouse_menu, s->tex->mouse_menu, sfTrue);
    sfSprite_setTexture(s->sp->pause, s->tex->pause, sfFalse);
    sfSprite_setScale(s->sp->retry, scale_button);
    sfSprite_setPosition(s->sp->retry, retry_pos);
    sfSprite_setTexture(s->sp->retry, s->tex->retry, sfFalse);
    sfSprite_setTexture(s->sp->main, s->tex->main, sfFalse);
    sfSprite_setScale(s->sp->button_play, scale_button);
    sfSprite_setPosition(s->sp->button_play, play_pos);
    sfSprite_setTexture(s->sp->button_play, s->tex->button_play, sfFalse);
    sfSprite_setScale(s->sp->button_exit, scale_button);
    sfSprite_setPosition(s->sp->button_exit, exit_pos);
    sfSprite_setTexture(s->sp->button_exit, s->tex->button_exit, sfFalse);
    init_pictures3(s);
}

void init_pictures(graph *s)
{
    sfVector2f scale_ship = {0.6, 0.6};
    sfVector2f scale_target = {0.2, 0.2};
    sfVector2f scale_mouse = {0.6, 0.6};

    create_sprite(s);
    sfSprite_setTexture(s->sp->background, s->tex->background, sfFalse);
    sfSprite_setScale(s->sp->target, scale_target);
    sfSprite_setTexture(s->sp->target, s->tex->target, sfTrue);
    sfSprite_setScale(s->sp->ship, scale_ship);
    sfSprite_setTexture(s->sp->ship, s->tex->ship, sfTrue);
    sfSprite_setTexture(s->sp->backscore, s->tex->backscore, sfFalse);
    sfSprite_setScale(s->sp->mouse, scale_mouse);
    sfSprite_setTexture(s->sp->mouse, s->tex->mouse, sfTrue);
    sfSprite_setPosition(s->sp->lifebar, s->pos->life);
    sfSprite_setTexture(s->sp->lifebar, s->tex->lifebar, sfTrue);
    sfSprite_setPosition(s->sp->lifebar_tip, s->pos->life_tip);
    sfSprite_setTexture(s->sp->lifebar_tip, s->tex->lifebar_tip, sfTrue);
    init_pictures2(s);
}
