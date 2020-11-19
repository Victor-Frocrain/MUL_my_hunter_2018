/*
** EPITECH PROJECT, 2018
** init_textures
** File description:
** init_textures
*/

#include "my.h"

void init_textures2(graph *s)
{
    s->font = sfFont_createFromFile("fonts/starjedi.ttf");
    s->tex->pause = sfTexture_createFromFile
    ("pictures/pause.png", NULL);
    s->tex->retry = sfTexture_createFromFile
    ("pictures/button_retry.png", NULL);
    s->tex->button_play = sfTexture_createFromFile
    ("pictures/button_play.png", NULL);
    s->tex->button_exit = sfTexture_createFromFile
    ("pictures/button_exit.png", NULL);
    s->tex->button_resume = sfTexture_createFromFile
    ("pictures/button_resume.png", NULL);
    s->tex->main = sfTexture_createFromFile
    ("pictures/main.png", NULL);
}

void init_textures(graph *s)
{
    s->tex->background = sfTexture_createFromFile
    ("pictures/background.jpg", NULL);
    s->tex->ship = sfTexture_createFromFile
    ("pictures/spaceship.png", NULL);
    s->tex->target = sfTexture_createFromFile
    ("pictures/target.png", NULL);
    s->tex->explose = sfTexture_createFromFile
    ("pictures/explose.png", NULL);
    s->tex->backscore = sfTexture_createFromFile
    ("pictures/backscore.jpg", NULL);
    s->tex->mouse = sfTexture_createFromFile
    ("pictures/lightsaber.png", NULL);
    s->tex->lifebar = sfTexture_createFromFile
    ("pictures/lifebar.png", NULL);
    s->tex->lifebar_tip = sfTexture_createFromFile
    ("pictures/lifebar_tip.png", NULL);
    s->tex->mouse_menu = sfTexture_createFromFile
    ("pictures/lightsaber.png", NULL);
    init_textures2(s);
}

void destroy_textures(graph *s)
{
    sfTexture_destroy(s->tex->background);
    sfTexture_destroy(s->tex->ship);
    sfTexture_destroy(s->tex->target);
    sfTexture_destroy(s->tex->explose);
    sfTexture_destroy(s->tex->backscore);
    sfTexture_destroy(s->tex->mouse);
    sfTexture_destroy(s->tex->lifebar);
    sfTexture_destroy(s->tex->lifebar_tip);
    sfTexture_destroy(s->tex->mouse_menu);
    sfTexture_destroy(s->tex->pause);
    sfTexture_destroy(s->tex->retry);
    sfTexture_destroy(s->tex->main);
    sfTexture_destroy(s->tex->button_play);
    sfTexture_destroy(s->tex->button_exit);
    sfTexture_destroy(s->tex->button_resume);
}
