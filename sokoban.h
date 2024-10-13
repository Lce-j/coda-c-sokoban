#ifndef __SOKOBAN_H__
#define __SOKOBAN_H__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

struct s_pos{
    int pos_y;
    int pos_x
};

typedef struct s_pos position;

struct s_game{
    char **map;
    position box;
    position player;
    position objectif;
};

typedef struct s_game game;

//map.c
void print_map(char **map);
void init_map(game *sokoban);
void update_map(game *sokoban);
void update_map_objectif(game *sokoban);
void update_map_box(game *sokoban);
void update_map_player(game *sokoban);

//position.c
void init_positions(game *sokoban);
int compare_position(position pos1, position pos2);

//moves.c
void ask_for_move(game *sokoban);
void move_up(game *sokoban);
void move_down(game *sokoban);
void move_left(game *sokoban);
void move_right(game *sokoban);
void move_box(game *sokoban, char *move);
void handle_move(game *sokoban, char *move);

//game.c
void init_game(game *sokoban);
int can_box_move_to_objectif(game *sokoban);
int check_win(game *sokoban);
int check_loss(game *sokoban);
void game_loop(game *sokoban);
void refresh(game *sokoban);

#endif