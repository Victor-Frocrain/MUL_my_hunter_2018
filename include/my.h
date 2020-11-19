/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my.h
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

#define MY_EXIT_ERROR 84
#define MY_EXIT_SUCCESS 0
#define SIZE_README 442
#define WIDTH 1920
#define HEIGHT 1080
#ifndef MY_H_
#define MY_H_

struct texts_s {
    sfText *life;
    sfText *score;
    sfText *best;
    sfText *lvl;
};

struct textures_s {
    sfTexture *background;
    sfTexture *ship;
    sfTexture *target;
    sfTexture *explose;
    sfTexture *backscore;
    sfTexture *mouse;
    sfTexture *lifebar;
    sfTexture *lifebar_tip;
    sfTexture *mouse_menu;
    sfTexture *pause;
    sfTexture *retry;
    sfTexture *main;
    sfTexture *button_play;
    sfTexture *button_exit;
    sfTexture *button_resume;
};

struct sprites_s {
    sfSprite *background;
    sfSprite *ship;
    sfSprite *target;
    sfSprite *explose[4];
    sfSprite *backscore;
    sfSprite *mouse;
    sfSprite *lifebar;
    sfSprite *lifebar_tip;
    sfSprite *mouse_menu;
    sfSprite *pause;
    sfSprite *retry;
    sfSprite *main;
    sfSprite *button_play;
    sfSprite *button_exit;
    sfSprite *button_resume;
};

struct times_s {
    sfClock *explose;
    sfClock *move;
};

struct positions_s {
    sfVector2f ship;
    sfVector2f life;
    sfVector2f life_tip;
};

struct rectangles_s {
    sfIntRect explosion;
    sfIntRect lifebar;
    sfIntRect mouse_menu;
};

struct audio_s {
    sfMusic *fire;
    sfMusic *battle;
    sfMusic *score;
    sfMusic *main;
};

typedef struct texts_s text;
typedef struct textures_s texture;
typedef struct sprites_s sprite;
typedef struct rectangles_s rectangle;
typedef struct times_s times;
typedef struct positions_s position;
typedef struct audio_s audio;

struct graph_s {
    sprite *sp;
    texture *tex;
    rectangle *rect;
    times *clock;
    position *pos;
    audio *mus;
    float speed;
    bool destroy;
    int life;
    int score;
    int lvl;
    bool click;
    text *disp;
    bool end;
    bool pause;
    bool escape_released;
    bool begin;
    bool exit;
    sfFont *font;
    sfVector2i mouse_pos;
    char *level;
};

typedef struct graph_s graph;
sfIntRect create_rect(int left, int top, int width, int height);
void init_pictures(graph *s);
void draw_sprites(sfRenderWindow *window, graph *s);
void move_ship(sfRenderWindow *window, graph *s);
void move_mouse(sfRenderWindow *window, graph *sp);
void spray_ship(graph *s);
graph *init_graph(graph *s);
void init_rect(graph *s);
void init_textures(graph *s);
void init_pictures(graph *s);
bool detect_shoot(sfRenderWindow *window, sfVector2i mousei, graph *s);
int my_strcmp(char const *s1, char const *s2);
void destroy_ressources(graph *s);
void game_loop(sfRenderWindow *window);
void display_life(graph *s);
void destroy_textures(graph *s);
void destroy_sprites(graph *s);
char *convert_int_str(int nb);
char *my_revstr(char *str);
void display_score(graph *s);
void read_best(graph *s);
int my_strlen(char const *str);
int my_getnbr(char const *str);
char *my_strcpy(char *dest, char const *src);
void manage_pause(sfRenderWindow *window, graph *s);
void init_audio(graph *s);
void destroy_audio(graph *s);
void play_sounds(graph *s);
void score_scene(sfRenderWindow *window, graph *s);
void draw_sprites_score(sfRenderWindow *window, graph *s);
graph *init_values(graph *s);
void main_scene(sfRenderWindow *window, graph *s);
void change_button_retry(sfRenderWindow *window, graph *s);
void change_button_play(sfRenderWindow *window, graph *s);
void change_button_exit(sfRenderWindow *window, graph *s,
float button_x, float button_y);
void check_if_retry(graph *s);
void change_button_resume(sfRenderWindow *window, graph *s);
void set_level(graph *s, float x, float y, int size);

#endif /* MY_H_ */
