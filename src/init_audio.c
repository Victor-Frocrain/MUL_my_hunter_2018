/*
** EPITECH PROJECT, 2018
** init_audio
** File description:
** init_audio
*/

#include "my.h"

void init_audio(graph *s)
{
    s->mus->fire = sfMusic_createFromFile("audio/fire.ogg");
    s->mus->battle = sfMusic_createFromFile("audio/battle.ogg");
    sfMusic_setLoop(s->mus->battle, sfTrue);
    s->mus->score = sfMusic_createFromFile("audio/score.ogg");
    s->mus->main = sfMusic_createFromFile("audio/main.ogg");
}

void destroy_audio(graph *s)
{
    sfMusic_destroy(s->mus->fire);
    sfMusic_destroy(s->mus->battle);
    sfMusic_destroy(s->mus->score);
    sfMusic_destroy(s->mus->main);
}
