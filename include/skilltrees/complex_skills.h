/*
 * Complex Skill implementation for chiventure
 */

#ifndef INCLUDE_COMPLEX_SKILL_H_
#define INCLUDE_COMPLEX_SKILL_H_

#include "skilltrees/skilltrees_common.h"
#include "skilltrees/effect.h"
#include "skilltrees/skill.h"

/*
 * Allocates a new complex skill in the heap.
 *
 * Parameters:
 *  - type: The complex skill type
 *  - skills: A list of the sub-skills to be stored within complex_skill
 *  - num_skills: The number of sub-skills the complex skill will use
 *
 * Returns:
 *  - A pointer to the complex skill, or NULL if a complex skill cannot be 
 *    allocated
 */
complex_skill_t* complex_skill_new(complex_skill_type_t type, skill_t** skills, int num_skills);

/*
 * Initializes a complex skill.
 *
 * Parameters:
 *  - complex_skill: A complex skill. Must pointer to skill allocated with 
 *    complex_skill_new
 *  - complex_skill_type_t: the type of complex skill it is.
 *  - skills: A list of the sub-skills to be stored within complex_skill
 *  - num_skills: The number of sub-skills the complex skill will use
 * 
 * Returns:
 *  - 0 on success, 1 if an error occurs
 */
int complex_skill_init(complex_skill_t* complex_skill, complex_skill_type_t type, skill_t** skills, int num_skills);

/*
 * Frees the resources associated with a complex skill.
 *
 * Parameters:
 *  - complex_skill: A complex skill. Must point to skill allocated with 
 *    complex_skill_new
 *
 * Returns:
 *  - Always returns 0
 */
int complex_skill_free(complex_skill_t* complex_skill);

/*
 * Executes each subskill in order. Behavior will vary depending on the type of 
 * skill.
 * Ex: Combined skills will run skill_execute on each subskill regardless of 
 *     success or failure
 *     Sequential skills will stop execution once a sub_skill fails
 * 
 * Note: Random complex skills are executed via a different function
 *
 *
 * Parameters:
 *  - complex_skill: A complex skill
 *  - chiventure_ctx_t* ctx - A context object to pull data from to execute the 
 *    skill
 * Returns:
 * 0 if success
 * 1 if failure
 */
int complex_skill_execute(complex_skill_t* complex_skill, chiventure_ctx_t* ctx);

/*
 * Executes a combined skill, executing each subskill regardless of success or 
 * failure
 *
 * Parameters:
 *  - complex_skill: A complex skill
 *  - chiventure_ctx_t* ctx - A context object to pull data from to execute the 
 *    skill
 * 
 * Returns:
 * 0 if success
 * 1 if failure
 */
int combined_complex_skill_execute(complex_skill_t* complex_skill, chiventure_ctx_t* ctx);

/*
 * Executes a sequential skill, stopping execution once a sub_skill fails
 *
 * Parameters:
 *  - complex_skill: A complex skill
 *  - chiventure_ctx_t* ctx - A context object to pull data from to execute the 
 *    skill
 * 
 * Returns:
 * 0 if success
 * 1 if failure
 */
int sequential_complex_skill_execute(complex_skill_t* complex_skill, chiventure_ctx_t* ctx);

/* NOTICE
 * The following 2 functions may not be necessary in final implementation, by 
 * changing the skill_level_up and skill_xp_up functions to just check for the 
 * presence of a complex skill
 * And increment each sub-skill respectfully.
 * These are included depending on that future decision
*/

/*
 * Levels each skill within complex_skill using skill_level_up.
 *
 * Parameters:
 *  - complex_skill: A complex skill.
 *
 * Returns:
 * SUCCESS if leveling up worked.
 * FAILURE if the maximum level was already achieved, so levelling up won't happen 
 * or if leveling up failed, such as invalid parameters for instance, or if 
 *  not every subskill was able to be leveled up
 */
int complex_skill_level_up(complex_skill_t* complex_skill);

/*
 * Increments each sub-skill's exp
 *
 * Parameters:
 *  - complex_skill: A complex skill.
 *  - xp_gained: Amount of xp to add onto a skill.
 *
 * Returns:
 * SUCCESS if incrementing experience worked.
 * FAILURE if the maximum level was already reached and you tried to level up again
 * or if incrementing xp failed, such as giving invalid parameters, or if 
 *  not every subskill was able to be incremented. 
 */
int complex_skill_xp_up(complex_skill_t* complex_skill, unsigned int xp_gained);

/* 
* Executes a random skill using a chance effect
*
* Parameters:
* - chance_skill: the random_chance_type_t complex skill being used
* - ctx: A context object to pull data from to execute the
*   skill
*
* Returns:
* 0 if success
* 1 if failure
*/
int execute_random_chance_complex_skill(random_chance_type_t* chance_skill, chiventure_ctx_t* ctx);

/* 
* Executes a random skill using a range effect–executes a skill a random number 
* of times within the given range
*
* Parameters:
* - range_skill: the random_range_type_t complex skill being used
* - chiventure_ctx_t* ctx: A context object to pull data from to execute the
*   skill
*
* Returns:
* 0 if success
* 1 if failure
*/
int execute_random_range_complex_skill(random_range_type_t* range_skill, chiventure_ctx_t* ctx);

/* 
* Executes a random skill using a switch effect
*
* Parameters:
* - random_switch_type_t* switch_skill: a struct with complex skill type 
*       RANDOM_SWITCH and an array of the chances of execution of each subskill
* - chiventure_ctx_t* ctx: A context object to pull data from to execute the
*   skill
*
* Returns:
* 0 if success
* 1 if failure
*/
int execute_random_switch_complex_skill(random_switch_type_t* switch_skill, chiventure_ctx_t* ctx);

#endif