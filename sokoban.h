#ifndef __SOKOBAN_H__
#define __SOKOBAN_H__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>


//map.c
void print_map(char **map);
void init_map(game *sokoban);
void update_map(game *sokoban);
void update_map_objectif(game *sokoban);
void update_map_box(game *sokoban);
void update_map_player(game *sokoban);

//moves.c

#endif