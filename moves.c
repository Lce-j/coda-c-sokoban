#include "sokoban.h"

void move_up(game *sokoban){
    if(sokoban->player.pos_y > 0){
        position tmp;
        tmp.pos_y = sokoban->player.pos_y - 1;
        tmp.pos_x = sokoban->player.pos_x;

        sokoban->player.pos_y = tmp.pos_y;
        sokoban->player.pos_x = tmp.pos_x;
        move_box(sokoban, "up");

    } else {
        printf("Vous ne pouvez pas aller plus haut");
    }
}

void move_down(game *sokoban){
    if(sokoban->player.pos_y < 10){
        position tmp;
        tmp.pos_y = sokoban->player.pos_y + 1;
        tmp.pos_x = sokoban->player.pos_x;

        sokoban->player.pos_y = tmp.pos_y;
        sokoban->player.pos_x = tmp.pos_x;
        move_box(sokoban, "down");

    } else{
        printf("Vous ne pouvez pas aller plus bas");
    }
}

void move_left(game *sokoban){
    if(sokoban->player.pos_x > 0){
        position tmp;
        tmp.pos_y = sokoban->player.pos_y;
        tmp.pos_x = sokoban->player.pos_x - 1;

        sokoban->player.pos_y = tmp.pos_y;
        sokoban->player.pos_x = tmp.pos_x;
        move_box(sokoban, "left");

    } else {
        printf("Vous ne pouvez pas aller plus à gauche");
    }
}

void move_right(game *sokoban){
    if(sokoban->player.pos_x < 10){
        position tmp;
        tmp.pos_y = sokoban->player.pos_y;
        tmp.pos_x = sokoban->player.pos_x + 1;

        sokoban->player.pos_y = tmp.pos_y;
        sokoban->player.pos_x = tmp.pos_x;
        move_box(sokoban, "right");

    } else {
        printf("Vous ne pouvez pas aller plus à droite");
    }
}

void move_box(game *sokoban, char *move){
    if(compare_positions(sokoban->player, sokoban->box) == 1){
        
        if(strcmp(move, "up") == 0){
            if(sokoban->box.pos_y > 0){
                sokoban->box.pos_y--;
            }
        }
        else if(strcmp(move, "down") == 0){
            if(sokoban->box.pos_y < 9){
                sokoban->box.pos_y++;
            }
        }
        else if(strcmp(move, "left") == 0){
            if(sokoban->box.pos_x > 0){
                sokoban->bos.pos_x--;
            }
        }
        else if(strcmp(move, "right") == 0){
            if(sokoban->box.pos_x < 9){
                sokoban->bos.pos_x++;
            }
        }
    }
}

void ask_for_move(game *sokoban){
    char * next_mv;
    printf("Would you like to go: up, domwn, left, right ?\n");
    scanf("%s", next_mv);
    handle_move(sokoban, next_mv);
}

void handle_move(game * sokoban, char * move)
{
   if ( strcmp(move, "up") == 0)
   {
        move_up(sokoban);
   }
   else if (strcmp(move, "down") == 0)
   {
        move_down(sokoban);
   }
   else if (strcmp(move, "right") == 0)
   {
        move_right(sokoban);
   }
   else if ( strcmp(move, "left") == 0 )
   {
        move_left(sokoban);
   }
}