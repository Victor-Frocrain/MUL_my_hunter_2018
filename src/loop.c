/*
** EPITECH PROJECT, 2018
** loop
** File description:
** loop
*/

#include "my.h"

void draw_sprites_game(sfRenderWindow *window, graph *s)
{
    sfRenderWindow_drawSprite(window, s->sp->background, NULL);
    sfRenderWindow_drawSprite(window, s->sp->ship, NULL);
    sfRenderWindow_drawSprite(window, s->sp->target, NULL);
    sfRenderWindow_drawSprite(window, s->sp->lifebar, NULL);
    sfRenderWindow_drawSprite(window, s->sp->lifebar_tip, NULL);
    sfRenderWindow_drawText(window, s->disp->lvl, NULL);
    if (s->pause == true) {
        sfRenderWindow_drawSprite(window, s->sp->pause, NULL);
        change_button_resume(window, s);
        change_button_exit(window, s, 1920 / 2 - (305 / 2 * 1.2),
        1080 / 2 + 100);
        sfRenderWindow_drawSprite(window, s->sp->button_resume, NULL);
        sfRenderWindow_drawSprite(window, s->sp->button_exit, NULL);
        sfRenderWindow_drawSprite(window, s->sp->mouse_menu, NULL);
    }
}

void draw_sprites_score(sfRenderWindow *window, graph *s)
{
    sfRenderWindow_drawSprite(window, s->sp->backscore, NULL);
    sfRenderWindow_drawText(window, s->disp->score, NULL);
    sfRenderWindow_drawText(window, s->disp->best, NULL);
    sfRenderWindow_drawSprite(window, s->sp->retry, NULL);
    sfRenderWindow_drawSprite(window, s->sp->button_exit, NULL);
    sfRenderWindow_drawSprite(window, s->sp->mouse_menu, NULL);
}

void game_actions(sfRenderWindow *window, graph *s)
{
    sfRenderWindow_clear(window, sfBlack);
    if (s->begin == true)
        main_scene(window, s);
    else if (s->life > 0) {
        manage_pause(window, s);
        set_level(s, 135, 913, 50);
        move_mouse(window, s);
        if (s->destroy == false && s->pause == false)
            move_ship(window, s);
        else if (s->pause == false)
            spray_ship(s);
        draw_sprites_game(window, s);
    }
    else
        score_scene(window, s);
    sfRenderWindow_display(window);
}

void check_close(sfRenderWindow *window, sfEvent event)
{
    while (sfRenderWindow_pollEvent(window, &event))
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
}

void game_loop(sfRenderWindow *window)
{
    sfEvent event;
    graph *s = init_graph(s);

    init_rect(s);
    init_textures(s);
    init_pictures(s);
    init_audio(s);
    sfMusic_play(s->mus->main);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    sfRenderWindow_setFramerateLimit(window, 60);
    while (sfRenderWindow_isOpen(window) && s->exit == false) {
        if (sfTime_asMilliseconds
        (sfClock_getElapsedTime(s->clock->move)) >= 10) {
            check_close(window, event);
            game_actions(window, s);
            sfClock_restart(s->clock->move);
        }
    }
    destroy_ressources(s);
    sfRenderWindow_destroy(window);
}
