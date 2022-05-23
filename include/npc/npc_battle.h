#ifndef _NPC_BATTLE_H
#define _NPC_BATTLE_H

#include "battle/battle_common.h"
#include "battle/battle_structs.h"
#include "battle/battle_moves.h"

// NPC_BATTLE STRUCTURE DEFINITION --------------------------------------------

/* Hostility level options */
typedef enum hostility {
    FRIENDLY = 0,
    CONDITIONAL_FRIENDLY = 1,
    HOSTILE = 2
} hostility_t;

/* Info used for battles with NPCs */
typedef struct npc_battle {
    /* NPC health level */
    int health;

    /* pointer to an existing stat struct */
    stat_t *stats;

    /* pointer to an existing move struct */
    move_t *moves;

    /* difficulty of the NPC's ai */
    difficulty_t ai;
    
    /* hostility level of the npc */
    hostility_t hostility_level;

    /* health level at which the NPC will surrender */
    int surrender_level;

    /* class of the npc */
    class_t *class_type;

    /* An inventory of items that can be used in battle */
    battle_item_t *items;
} npc_battle_t;

// STRUCT FUNCTIONS -----------------------------------------------------------

/*
 * Initializes an npc's battle info (npc_battle) with the given parameters.
 *
 * Parameters:
 *  npc_battle: an npc_battle struct; must point to already allocated memory
 *  health: an int with the npc's starting health level
 *  stats: a pointer to an existing stat_t struct defining the npc's battle 
           stats (see /include/battle/battle_structs.h)
 *  moves: a pointer to an existing move_t struct defining the npc's battle 
           moves (see /include/battle/battle_structs.h)
 *  ai: the npc's difficulty level (see /include/battle/battle_common.h)
 *  hostility_level: the npc's hostility level 
 *  surrender_level: the level of health at which the npc surrenders the battle
 *  class_type: the class struct of the npc
 *  items: a doubly linked list of items that the npc can use during battle
 *
 * Returns:
 *  SUCCESS on success, FAILURE if an error occurs
 */
int npc_battle_init(npc_battle_t *npc_battle, int health, stat_t* stats, 
                    move_t* moves, difficulty_t ai, hostility_t hostility_level,
                    int surrender_level, class_t *class_type, 
                    battle_item_t *items);
/*
 * Allocates a new npc_battle struct in the heap.
 *
 * Parameters:
 *  health: an int with the npc's starting health level
 *  stats: a pointer to an existing stat_t struct defining the npc's battle 
           stats (see /include/battle/battle_structs.h)
 *  moves: a pointer to an existing move_t struct defining the npc's battle 
           moves (see /include/battle/battle_structs.h)
 *  ai: the npc's difficulty level (see /include/battle/battle_common.h)
 *  hostility_level: the npc's hostility level 
 *  surrender_level: the level of health at which the npc surrenders the battle
 *  class_type: the class struct of the npc
 *  items: a doubly linked list of items that the npc can use during battle
 *
 * Returns:
 *  pointer to allocated npc_battle
 */
npc_battle_t *npc_battle_new(int health, stat_t* stats, move_t* moves, 
		                    difficulty_t ai, hostility_t hostility_level, 
			                int surrender_level, class_t *class_type,
                            battle_item_t *items);

/*
 * Frees resources associated with an npc_battle struct.
 *
 * Parameters:
 *  npc_battle: the npc_battle struct to be freed
 *
 * Returns:
 *  SUCCESS if successful, FAILURE if an error occurs
 */
int npc_battle_free(npc_battle_t *npc_battle);

/*
 * Changes the hostility level of an npc_batle struct from 
 * CONDITIONAL_FRIENDLY to HOSTILE.
 * 
 * Parameters:
 *   npc_battle: the npc_battle struct to be modified
 * 
 * Returns:
 *   SUCCESS if successful, FAILURE if an error occurs
 */
int make_npc_hostile(npc_battle_t *npc_battle);

#endif
