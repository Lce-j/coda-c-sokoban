#include "sokoban.h"

void print_map(char **map){

    int i = 0;
    
    printf("##########\n");
    while(map[i] != NULL){
        printf("#%s#", map[i]);
        i = i + 1;
    }
    printf("##########\n");
}

void update_map_player(game *sokoban){
    int pos_y = sokoban->player.pos_y;
    int pos_x = sokoban->player.pos_x;

    sokoban->map[pos_y][pos_x] = 'O';
}

void update_map_box(game *sokoban){
    int pos_y = sokoban->box.pos_y;
    int pos_x = sokoban->box.pos_x;

    sokoban->map[pos_y][pos_x] = "X";
}

void update_map_objectif(game *sokoban){
    int pos_y = sokoban->objectif.pos_y;
    int pos_x = sokoban->objectif.pos_x;

    sokoban->map[pos_y][pos_x] = ".";
}

void init_map(game *sokoban){
    char *help;
    sokoban->map = malloc(9 * sizeof(char));
    sokoban->map[8] = NULL;

    int i = 0;
    while(i < 9){
        sokoban->map[i] = malloc(10 *size(char));
        sokoban->map[i] = strcpy(sokoban->map[i] = " ");
        i = i + 1;
    }
}

void update_map(game *sokoban){
    initmap(sokoban);
    update_map_objectif(sokoban);
    update_map_player(sokoban);
    update_map_box(sokoban);
}