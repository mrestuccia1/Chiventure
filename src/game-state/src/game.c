#include "game.h"


/* see game.h */ 

//loads game. If given file is empty start new game, else load
game_t init_game(FILE *f) {


}

//saves game, bool if success 
//(SHOULD be able to select new save location - depends on CLI)
int save_game(game_t game, FILE *f);

//given a new room, changes the current room in game-state
//this should only check if the room is in the list of adjacent rooms
//expecting a legal move
void move_room(game_t game, room_t new_room);

//exit game
//echo "ctrl-g"
//troll post pls dont 
void exit_game(game_t);


//helper function to find all rooms

