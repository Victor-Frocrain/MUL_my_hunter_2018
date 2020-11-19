/*
** EPITECH PROJECT, 2018
** init
** File description:
** init
*/

#include "my.h"

void init_rect(graph *s)
{
    s->rect->explosion.left = 0;
    s->rect->explosion.top = 0;
    s->rect->explosion.width = 768 / 3;
    s->rect->explosion.height = 512 / 4;
    s->rect->lifebar.left = 0;
    s->rect->lifebar.top = 0;
    s->rect->lifebar.width = 419;
    s->rect->lifebar.height = 65;
    s->rect->mouse_menu.left = 0;
    s->rect->mouse_menu.top = 0;
    s->rect->mouse_menu.width = 1766 / 2;
    s->rect->mouse_menu.height = 904;
}

graph *init_values(graph *s)
{
    s->destroy = false;
    s->pos->ship.x = -197;
    s->pos->ship.y = 0;
    s->click = false;
    s->life = 3;
    s->speed = 0.2;
    s->pos->life.x = 1480;
    s->pos->life.y = 900;
    s->pos->life_tip.x = 1480 - 33;
    s->pos->life_tip.y = 900;
    s->score = 0;
    s->pause = false;
    s->escape_released = true;
    s->mouse_pos.x = 0;
    s->mouse_pos.y = 0;
    s->begin = true;
    s->exit = false;
    s->level = convert_int_str(1);
    return (s);
}

graph *init_graph(graph *s)
{
    s = malloc(sizeof(graph));
    s->tex = malloc(sizeof(texture));
    s->sp = malloc(sizeof(sprite));
    s->rect = malloc(sizeof(rectangle));
    s->disp = malloc(sizeof(text));
    s->clock = malloc(sizeof(clock));
    s->pos = malloc(sizeof(position));
    s->mus = malloc(sizeof(audio));
    s->disp->score = sfText_create();
    s->disp->best = sfText_create();
    s->disp->lvl = sfText_create();
    s->clock->explose = sfClock_create();
    s->clock->move = sfClock_create();
    init_values(s);
    return (s);
}

void destroy_ressources(graph *s)
{
    sfText_destroy(s->disp->score);
    sfText_destroy(s->disp->best);
    sfText_destroy(s->disp->lvl);
    sfFont_destroy(s->font);
    sfClock_destroy(s->clock->explose);
    sfClock_destroy(s->clock->move);
    destroy_sprites(s);
    destroy_textures(s);
    destroy_audio(s);
    free(s->level);
    free(s->mus);
    free(s->pos);
    free(s->clock);
    free(s->disp);
    free(s->tex);
    free(s->sp);
    free(s->rect);
    free(s);
}
