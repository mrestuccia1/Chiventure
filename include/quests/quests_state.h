#ifndef QUESTS_STATE_H
#define QUESTS_STATE_H

#include <stdbool.h>
#include <string.h>
#include "quests_structs.h"

#include "player.h"

/* Creates a new passive mission struct (allocates memory)
 * 
 * Parameters:
 * - xp: integer list of experience milestones to reach
 * - levels: integer list of level milestones to reach
 * - health: integer list of health milestones to reach
 *
 * Returns: a pointer to the newly allocated passive mission, that is not completed
 */
passive_mission_t *passive_mission_new(int *xp, int *levels, int *health);

/* Creates a new active mission struct (allocates memory)
 * 
 * Parameters:
 * - item_to_collect: the item to be collected for the mission
 * - npc_to_meet: the npc to be met for the mission
 * - npc_to_kill: the npc to kill for the mission
 * - room_to_visit: the room to visit for the mission 
 *
 * Returns: a pointer to the newly allocated passive mission, that is not completed
 */
active_mission_t *active_mission_new(item_t *item_to_collect, npc_t *npc_to_meet, 
                              npc_t *npc_to_kill, room_t *room_to_visit);

/* Creates a new achievement struct (allocates memory)
 * 
 * Parameters:
 * - mission: the mission to be completed for the quest
 * - id: the id of the achievement
 * 
 * Returns: a pointer to the newly allocated achievement that is not completed
 */
achievement_t *achievement_new(mission_t *mission, char *id);

/* Creates a new quest struct (allocates memory)
 * 
 * Parameters:
 * - quest_id: long integer for the specific quest_id 
 * - achievement_tree: non-binary tree  struct holding a tree of 
 *                     achievements that make up a quest
 * - reward: reward of the quest is an item
 * 
 * Returns: a pointer to the newly allocated quest, with default status of 0
 *         (not started)
 */
quest_t *quest_new(long int quest_id, achievement_tree_t *achievement_tree,
                    item_t *reward);

/* Initialize an already allocated passive mission struct 
 *
 * Parameters:
 * - mission: an already allocated mission_t (of passive type)
 * - item_to_collect: the item to be collected for the mission
 * - npc_to_meet: the npc to be met for the mission
 * 
 * Returns:
 * - SUCCESS for successful init
 * - FAILURE for unsuccessful init
 */
int passive_mission_init(passive_mission_t *mission, int *xp, int *levels, int *health);

/* Initialize an already allocated active mission struct 
 *
 * Parameters:
 * - mission: an already allocated mission_t (of active type)
 * - item_to_collect: the item to be collected for the mission
 * - npc_to_meet: the npc to be met for the mission
 * 
 * Returns:
 * - SUCCESS for successful init
 * - FAILURE for unsuccessful init
 */
int active_mission_init(active_mission_t *mission, item_t *item_to_collect, npc_t *npc_to_meet,
                        npc_t *npc_to_kill, room_t *room_to_visit);

/* Initialize an already allocated achievement struct
 *
 * Parameters:
 * - achievement: an already allocated achievement
 * - mission: the mission to be completed for the achievement
 * - id: the id of the achievement
 * 
 * Returns:
 * - SUCCESS for successful init
 * - FAILURE for unsuccessful init
 */
int achievement_init(achievement_t *achievement, mission_t *mission, char *id);


/* Initialize an already allocated quest struct
 *
 * Parameters:
 * - q: an already allocated quest
 * - quest_id: long int for the specific quest_id 
 * - achievement_tree: non-binary tree struct holding a tree of 
 *                     achievements that make up a quest
 * - reward: reward of the quest is an item
 * - status: int indicating the status of the quest (refer to
 *           quests_structs.h for all possible statuses)
 * 
 * Returns:
 * - SUCCESS for successful init
 * - FAILURE for unsuccessful init
 * 
 */
int quest_init(quest_t *q, long int quest_id, achievement_tree_t *achievement_tree, 
               item_t *reward, int status);

/* 
 * Frees a passive mission struct from memory
 * 
 * Parameter:
 * - mission: the mission to be freed
 * 
 * Returns:
 * - SUCCESS for successful free
 * - FAILURE for unsuccessful free
 */
int passive_mission_free(passive_mission_t *mission);

/* 
 * Frees an active mission struct from memory
 * 
 * Parameter:
 * - mission: the mission to be freed
 * 
 * Returns:
 * - SUCCESS for successful free
 * - FAILURE for unsuccessful free
 */
int active_mission_free(active_mission_t *mission);

/* 
 * Frees an achievement struct from memory but does not free 
 * its associated pointers
 * 
 * Parameter:
 * - achievement: the achievement to be freed
 * 
 * Returns:
 * - SUCCESS for successful free
 * - FAILURE for unsuccessful free
 */
int achievement_free(achievement_t *achievement);

/* 
 * Frees a quest struct from memory including the achievement list
 * and reward, but otherwise does not free associated pointers
 * 
 * Parameter:
 * - quest: the quest to be freed
 * 
 * Returns:
 * - SUCCESS for successful free
 * - FAILURE for unsuccessful free
 */
int quest_free(quest_t * quest);

/* 
 * Determines whether two quests are the same
 * 
 * Parameter:
 * - quest1: first quest
 * - quest2: second quest
 * 
 * Returns:
 * - 0 for false
 * - 1 for true
 */
int compare_quests(quest_t *quest1, quest_t *quest2);

/*
 * Helper function used to find the bottom node on the left side of a tree
 *
 * Parameters:
 * - a pointer to a tree
 *
 * Returns:
 * - a pointer to the tree with no children on the left side of the tree
 */
achievement_tree_t *get_bottom_node(achievement_tree_t *t);

/*
 * Function to determine the parent node of a given node.
 *
 * Parameters:
 * - tree: a pointer to a tree
 * - id: char id associated with an achievement node
 *
 * Returns:
 * - parent node
 */
achievement_tree_t *find_parent(achievement_tree_t *tree, char *id);

/* Adds an achievement to the tree given an parent tree id
 *
 * Parameters:
 * - quest: pointer to a quest 
 * - achievement_to_add: pointer to an achievement to add to the list
 * - parent_id: string that is parent achievement's id
 * 
 * Returns:
 * - SUCCESS 
 * - FAILURE 
 */
int add_achievement_to_quest(quest_t *quest, achievement_t *achievement_to_add, char *parent_id)

/* Updates a quest's status to started
 *
 * Parameter:
 * - quest: pointer to quest to be marked started
 * 
 * Returns:
 * - SUCCESS 
 * - FAILURE
 */
int start_quest(quest_t *quest);

/* Updates a quest's status to failed
 *
 * Parameter:
 * - quest: pointer to quest to be marked failed
 * 
 * Returns:
 * - SUCCESS 
 * - FAILURE
 */
int fail_quest(quest_t *quest);

/*
 * Traverses the achievement tree to find the achievement with the
 * given string identifier along a valid quest path.
 *
 * Parameters:
 * - tree: pointer to the achievement tree to be traversed
 * - id: pointer to a string identifier for the desired achievement
 *
 * Returns:
 * - pointer to the desired achievement, OR
 * - NULL if achievement cannot be found along a valid path
 *
 * Note: Achievements must be completed in order according to this
 *       traversal. Only one achievement on each level can be completed,
 *       so this "locks" a user into a path once they've begun
 *       completing achievements.
 */
achievement_t *find_achievement(achievement_tree_t *tree, char *id)


/* Completes an achievement in a quest by checking if a given
 * achievement ID matches any incomplete achievements in the
 * appropriate level of the achievement tree.
 * 
 * Parameters:
 * - quest: pointer to the quest
 * - id: the string identifier of the completed achievement
 *
 * Returns:
 * - SUCCESS
 * - FAILURE
 */
int complete_achievement(quest_t *quest, char *id);

/* Checks if a quest is completed
 * 
 * Parameter:
 * - quest: pointer to the quest
 *
 * Returns:
 * - 0 if quest is incomplete
 * - 1 if quest is complete
 */
int is_quest_completed(quest_t *quest);

/* Checks a quest's status.
 *
 * Parameter:
 * - quest: pointer to a quest
 * 
 * Returns: 
 * - the quest's status code, as described in quests_structs.h
 */
int get_quest_status(quest_t *quest);

/* Returns the quest's reward item if the quest has been completed.
 *
 * Parameter:
 * - quest: pointer to a quest
 * 
 * Returns:
 * - the quest's reward item
 * - NULL if the quest is incomplete
 * 
 * Note:
 * The status of the quest should first be checked before this function is called
 */
item_t *complete_quest(quest_t *quest);


#endif /* QUESTS_STATE_H */
