#include "sokoban.h"

int main(){
    printf("Commençons la partie ...");

    game sokoban;
    init_game(&sokoban);

    game_loop(&sokoban);

    if(check_win(&sokoban) == 1){
        printf("You win !");
    }
    else if(check_loss(&sokoban) == -1){
        printf("You lose !");
    }

    int i = 0;
    while(i <= 10){
        free(sokoban.map[i]);
        i++;
    }
    free(sokoban.map);

    exit(0);
}