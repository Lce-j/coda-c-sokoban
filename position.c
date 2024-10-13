#include "sokoban.h"

void init_positions(game *sokoban){
    int objectif = rand() % 100;
    int box = rand() % 100;
    int player = rand() % 100;

    sokoban->objectif.pos_y = objectif / 100;
    sokoban->objectif.pos_x = objectif % 100;

    sokoban->box.pos_y = box / 100;
    sokoban->box.pos_x = box % 100;

    if(sokoban->box.pos_y == 0){
        sokoban->box.pos_y = 1;
    }
    else if(sokoban->box.pos_x == 99){
        sokoban->box.pos_x = 98;
    }

    if(sokoban->box.pos_y == 99){
        sokoban->box.pos_y = 98;
    }
    else if(sokoban->box.pos_x == 0){
        sokoban->box.pos_x = 1;
    }

    sokoban->player.pos_y = player / 100;
    sokoban->player.pos_x = player % 100;
}

int compare_position(position pos1, position pos2){
    if(pos1.pos_y == pos2.pos_y){
        if(pos1.pos_x == pos2.pos_x){
            return(1);
        } else {
            return(-1);
        }
    } else {
        return(-1);
    }
}