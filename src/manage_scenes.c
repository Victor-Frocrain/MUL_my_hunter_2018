/*
** EPITECH PROJECT, 2018
** manage_scenes
** File description:
** manage_scenes
*/

#include "my.h"

void display_main(sfRenderWindow *window, graph *s)
{
    sfRenderWindow_drawSprite(window, s->sp->main, NULL);
    sfRenderWindow_drawSprite(window, s->sp->button_play, NULL);
    sfRenderWindow_drawSprite(window, s->sp->button_exit, NULL);
    sfRenderWindow_drawSprite(window, s->sp->mouse_menu, NULL);
}

void check_if_retry(graph *s)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
        s->life = 3;
        s->score = 0;
        s->level = convert_int_str(1);
        s->end = false;
        s->speed = 0.2;
        s->rect->lifebar.left = 0;
        s->rect->lifebar.top = 0;
        s->rect->lifebar.width = 419;
        s->rect->lifebar.height = 65;
        s->pos->life.x = 1480;
        s->pos->life.y = 900;
        s->pos->life_tip.x = 1480 - 33;
        s->pos->life_tip.y = 900;
        sfSprite_setPosition(s->sp->lifebar_tip, s->pos->life_tip);
        sfSprite_setPosition(s->sp->lifebar, s->pos->life);
        sfSprite_setTexture(s->sp->lifebar, s->tex->lifebar, sfTrue);
        sfMusic_stop(s->mus->score);
        sfMusic_play(s->mus->battle);
    }
}

void score_scene(sfRenderWindow *window, graph *s)
{
    sfVector2f exit_pos = {1190, 1080 / 1.56};

    if (s->end == false) {
        sfMusic_stop(s->mus->battle);
        sfMusic_play(s->mus->score);
        read_best(s);
        display_score(s);
        sfSprite_setPosition(s->sp->button_exit, exit_pos);
        s->end = true;
    }
    move_mouse(window, s);
    change_button_retry(window, s);
    change_button_exit(window, s, 1190, 1080 / 1.56);
    draw_sprites_score(window, s);
}

void main_scene(sfRenderWindow *window, graph *s)
{
    move_mouse(window, s);
    change_button_play(window, s);
    change_button_exit(window, s,
    1235, 500 + (305 / 2 * 1.2) + 25);
    display_main(window, s);
}
