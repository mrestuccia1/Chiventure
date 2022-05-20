#ifndef QUESTS_STRUCTS_H
#define QUESTS_STRUCTS_H

// REMEMBER TO INCLUDE ANY ADDITIONAL RELEVANT FILES (NPC)
#include "game-state/item.h"
#include "common/common.h"
#include "common/utlist.h"
#include "npc/npc.h"

/* Forward declaration */
typedef struct npc npc_t;

/*
 * This struct represents a mission.
 *
 * Components:
 *  item_to_collect: an item to collect
 *  npc_to_meet: an npc to meet
 *  npc_to_kill: an npc to kill
 *  room_to_visit: a room to visit
 * 
 * Note: Only one of these can be active (not NULL) at a time
 */
typedef struct mission {
    item_t *item_to_collect;
    npc_t *npc_to_meet;
    npc_t *npc_to_kill;
    room_t *room_to_visit;
} mission_t;

/* 
 * This struct represents a reward for completing a quest or task.
 *
 * Components:
 *  xp: an xp amount gained
 *  item: an item gained
 */
typedef struct reward {
   int xp;
   item_t *item;
} reward_t;

/*
 * A single quest/task id node for the linked list
*/
typedef struct id_list_node {
    char *id;
    struct id_list_node *next;
} id_list_node_t;

/*
 * A linked list of quest/task ids
*/
typedef struct id_list {
    id_list_node_t *head;
    int length;
} id_list_t;

/*
 * This struct represents a prerequisite for a quest or task.
 *
 * Components:
 *  hp: health points 
 *  level: a number of levels gained
 *  task_list: a list of task ids that will all be checked for completion
 *  quest_list: a list of quest ids that will all be checked for completion
 */
typedef struct prereq {
    int hp;
    int level;
    id_list_t *task_list;
    id_list_t *quest_list;
} prereq_t;

/* 
 * This struct represents a task.
 * 
 * Components:
 *  mission: mission to be completed
 *  id: string identifier for the task
 *  reward: reward for completing the task.
 */
typedef struct task {
    mission_t *mission;
    char *id;
    reward_t *reward;
    prereq_t *prereq;
} task_t;

/*
 * This is a non-binary tree struct of tasks (to replace linked list)
 *
 * Components:
 *  task: task in tree
 *  parent: parent node of task
 *  rsibling: the nearest right-hand sibling of the task node
 *  lmostchild: the leftmost child of the task node
 */
typedef struct task_tree {
    task_t *task;
    struct task_tree *parent;
    struct task_tree *rsibling;
    struct task_tree *lmostchild;
} task_tree_t;

/* 
 * This is the hashable struct for a quest 
 * Elements:
 * quest_id: the id of the quest
 * task_tree: non-binary tree struct holding a tree of
 *                   tasks that make up a quest
 * reward: reward of the quest is either experience, an item, or both
 * stat_req: stat requirement for the quest
 */
typedef struct quest  {
    char *quest_id;
    task_tree_t *task_tree;
    reward_t *reward;
    prereq_t *prereq;
    UT_hash_handle hh;
} quest_t;

/*
 * This typedef distinguishes between quest_t pointers
 * which are used to point to quest_t structs in the 
 * traditional sense and those which are used to hash
 * quest_t structs with the UTHASH macros as specified
 * in include/common
 */
typedef struct quest quest_hash_t;


#endif 
