#include "sokoban.h"

void init_game(game *sokoban){
    init_map(sokoban);
    init_positions(sokoban);
    update_map(sokoban);
}

int can_box_move_to_objectif(game *sokoban){

    if (sokoban->box.pos_y == 0 && sokoban->objectif.pos_y > 0){
        return(-1);
    }
    else if(sokoban->box.pos_y == 9 && sokoban->objectif.pos_y > 9){
        return(-1);
    }
    else if(sokoban->box.pos_x == 0 && sokoban->objectif.pos_x > 0){
        return(-1);
    }
    else if(sokoban->box.pos_y == 9 && sokoban->objectif.pos_y > 9){
        return(-1);
    }
    return(1);
}

int check_win(game *sokoban){
    if(compare_positions(sokoban->objectif, sokoban->box) == 1){
        return(1);
    }
    return(0);
}

int check_loss(game *sokoban){
    if(can_box_move_to_objectif(sokoban) == -1){
        return(-1);
    }
    return(0);
}

void game_loop(game *sokoban){
    while(check_win(sokoban) != 1 && check_loss(sokoban) != -1){
        ask_for_move(sokoban);
        refresh(sokoban);
    }
}

void refresh(game *sokoban){
    sleep(1);
    system("clear");
    update_map(sokoban);
    print_map(sokoban->map);
}