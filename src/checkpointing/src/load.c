#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.pb-c.h"
#include "load.h"
#define MAX_BUF_SIZE 1000000


size_t read_file(char *filename, unsigned max_length, uint8_t *out)
{
    size_t cur_len = 0;
    size_t nread;
    FILE *fp = fopen(filename, "r");
    while ((nread = fread(out + cur_len, 1, max_length - cur_len, fp)) != 0) {
	cur_len += nread;
	if (cur_len == max_length) {
	    fprintf(stderr, "max message length exceed\n");
	    return max_length;
	}
    }
    fclose(fp);
    return cur_len;
}
    
int load_item(Item *i, item_t *i_t)
{
    if(i_t == NULL) {
	fprintf(stderr, "given null item_t struct\n");
	return -1;
    }

    i_t->item_id = i->item_id;
  
    if (i->short_desc != NULL) {
	i_t->short_desc = i->short_desc;
    } else {
	i_t->short_desc = NULL;
    }
  
    if (i->long_desc != NULL) {
	i_t->long_desc = i->long_desc;
    } else {
	i_t->long_desc = NULL;
    }

    // bool condition reserved for future expansion

    // repeated Attribute HERE
    //ITER_ALL_ITEMS
    return 0;
}

int load_room(Room *r, room_t *r_t)
{
    if (r_t == NULL) {
	fprintf(stderr, "given null room_t struct\n");
	return -1;
    }

    r_t->room_id = r->room_id;
  
    if (r->short_desc != NULL) {
	r_t->short_desc = r->short_desc;
    } else {
	r_t->short_desc = NULL;
    }
  
    if (r->long_desc != NULL) {
	r_t->long_desc = r->long_desc;
    } else {
	r_t->short_desc = NULL;
    }

    // Load items here
    // note that object is now called item
    
    /* object_t **objs = malloc(sizeof(object_t*) * r->objs_len);

    for (int i = 0; i < r->objs_len; i++) {
	objs[i] = malloc(sizeof(object_t));
	load_object(r->objs[i], objs[i]);
    }
  
    r_t->objs = objs;

    // path stuff here

    */
    return 0;
}

int load_player(Player *p, player_t *p_t)
{
    if (p_t == NULL) {
	fprintf(stderr, "given null player_t struct\n");
	return -1;
    }

    p_t->player_id = p->player_id;

    if (p->has_level == 1) {
	p_t->level = p->level;
    } else {
	p_t->level = -1;
    }

    if (p->has_health == 1) {
	p_t->health = p->health;
    } else {
	p_t->health = -1;
    }

    if (p->has_xp == 1) {
	p_t->xp = p->xp;
    } else {
	p_t->xp = -1;
    }
    
    // Load inventory here
    /*
    object_t **inventory = malloc(sizeof(object_t*) * p->inventory_len);

    for (int i = 0; i < p->inventory_len; i++) {
	inventory[i] = malloc(sizeof(object_t));
	load_object(p->inventory[i], inventory[i]);
    }
    p_t->inventory = inventory;
	
    p_t->inventory_len = p->inventory_len;
  
    */
    return 0;
}    

int load_game(Game *g, game_t *g_t)
{
    if (g_t == NULL) {
	fprintf(stderr, "given null game_t struct\n");
	return -1;
    }

    // repeated all_players
    /*
    player_t **players = malloc(sizeof(player_t*) * g->players_len);
    for (int i = 0; i < g->players_len; i++) {
	players[i] = malloc(sizeof(player_t));
	load_player(g->players[i], players[i]);
    }

    g_t->players = players;
  
    g_t->players_len = g->players_len;
  
    // repeated all_rooms

    room_t **rooms = malloc(sizeof(room_t*) * g->rooms_len); 
    for (int j = 0; j < g->rooms_len; j++) {
	rooms[j] = malloc(sizeof(room_t));
	load_room(g->rooms[j], rooms[j]);
    }

    g_t->rooms = rooms;
  
    g_t->rooms_len = g->rooms_len;  
    */

    // Note: in game state structs, curr_room is a room struct that contains a room_id
    // In the proto struct, curr_room is simply the room_id as a string
    if(g->curr_room != NULL) {
	room_t *curr_r;
	ITER_ALL_ROOMS(g_t, curr_r) {
	    if (curr_r->room_id == g->curr_room) {
		g_t->curr_room = curr_r;
	    }
	}
    }

    if (g->curr_player != NULL) {
	player_t *curr_p;
	ITER_ALL_PLAYERS(g_t, curr_p) {
	    if (curr_p->player_id == g->curr_player) {
		g_t->curr_player = curr_p;
	    }
	}
    }
    
    return 0;
}

int load(char *filename, Game *g, game_t *g_t)
{
    uint8_t buffer[MAX_BUF_SIZE];
    size_t game_len = read_file(filename, MAX_BUF_SIZE, buffer);
	
    printf("game_len: %ld\n", game_len);
  
    g = game__unpack(NULL, game_len, buffer);
	
    if (g == NULL) {
	fprintf(stderr, "error unpacking incoming game\n");
	exit(1);
    }

    load_game(g, g_t);

    game__free_unpacked(g, NULL);
  
    return 0;
}
