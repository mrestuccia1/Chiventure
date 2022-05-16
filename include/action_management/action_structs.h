#ifndef _ACTION_STRUCTS_H_
#define _ACTION_STRUCTS_H_

#include "game-state/game_state_common.h"


/* Forward declarations. Full typedefs can be found in item.h */
typedef struct attribute attribute_t;
typedef struct attribute_wrapped_for_llist attribute_list_t;
typedef union attribute_value attribute_value_t;
typedef struct attribute attribute_hash_t;
typedef struct item item_t;
typedef struct item item_hash_t;
typedef struct item_wrapped_for_llist item_list_t;

/* Forward declaration. Full typedef can be found in condition.h */
typedef struct condition condition_list_t;


/* File consisting of all action structs created by action management
   =========================================================================== */

/* An enumeration of all supported actions.
 * KIND 1 ACTIONS - ACTION <item>
 * KIND 2 ACTIONS - ACTION <path>
 * KIND 3 ACTIONS - ACTION <item> <item>
 */
enum actions {
// ITEM ACTIONS
    /* KIND 1 ACTIONS - ACTION <item> */
    OPEN,
    CLOSE,
    PUSH,
    PULL,
    TURNON,
    TURNOFF,
    TAKE,
    PICKUP,
    DROP,
    CONSUME,
    USE,
    DRINK,
    EAT,

    /* KIND 2 ACTIONS - ACTION <path> */
    GO,
    WALK,

    /* KIND 3 ACTIONS - ACTION <item_item> */
    USE_ON,
    PUT,

    // NPC ACTIONS
    /* KIND 4 ACTIONS */
    ATTACK,
    TALK_TO,
    IGNORE,
    
    /* KIND 5 ACTIONS */
    GIVE,
    STEAL,

    /* KIND 6 ACTIONS */
    TRADE,
    BUY
} actions_t;


/* A linked list struct that contains the following:
 * - action: the action at the head of the list
 * - next: the next item in the linked list
 */
 typedef struct list_action {
    enum actions *npc_action;
    struct list_action *next;
} list_action_t;


// Each enum corresponds to a different "KIND" of action
enum action_kind {
// ITEM ACTIONS
    ITEM = 1, // ACTION <item> i.e. Action Type 1
    PATH = 2, // ACTION <path i.e. Action Type 2
    ITEM_ITEM = 3, // ACTION <item> <item> i.e. Action Type 3
// NPC ACTIONS
    NPC = 4,
    NPC_ITEM = 5,
    NPC_ITEM_ITEM = 6
};


/* Forward room declaration */
typedef struct room room_t;

// ACTION STRUCTURE DEFINITION + BASIC FUNCTIONS ------------------------------
/*typedef struct game_action_effect{
    enum agent_tag agent_tag;
    agent_t *agent;
    attribute_t* attribute_to_modify;
    attribute_value_t *new_value;
    struct game_action_effect *next; //mandatory for utlist macros
} game_action_effect_t;*/

/* This typedef is to distinguish between game_action_effect_t
* pointers which are used to point to the game_action_effect_t structs
* in the traditional sense, and those which are used to enable UTLIST functionality
* on the game_action_effect_t structs as specified in src/common/include
*/
//typedef struct game_action_effect action_effect_list_t;


/*typedef struct game_action {
    UT_hash_handle hh;
    char* action_name;
    condition_list_t *conditions; //must be initialized to NULL
    action_effect_list_t *effects; //must be initialized to NULL
    char* success_str;
    char* fail_str;
} game_action_t;*/

/* An action struct that contains the following:
 * - c_name: the 'canonical' string that should call the enum
 * - kind: an enumeration of the kind of action
 * - room: the room that requires the action to be done before entry.
 * - direction: direction of path.
 */
typedef struct action_type{
    char *c_name; // e.g. "eat"
    enum action_kind kind; // e.g. KIND_1
    room_t *room;
    char *direction;
} action_type_t;


/* A linked list struct that contains two components
 * - act: the data component
 * - next: the next item in the linked list
 * - trigger: room_id of the room that requires this action as a condition
 * This struct is primarily used in the get_supported_actions function.
*/
typedef struct list_action_type {
    action_type_t *act;
    struct list_action_type *next;
} list_action_type_t;

#endif
