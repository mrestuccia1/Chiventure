#include <criterion/criterion.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "playerclass/class.h"
#include "game-state/item.h"
#include "game-state/room.h"
#include "game-state/player.h"
#include "quests/task.h"
#include "quests/quest.h"
/* Creates a sample class. Taken from test_class.c */
class_t* generate_test_class()
{
    class_t* c;
    char *name, *shortdesc, *longdesc;

    name = "Warrior";
    shortdesc = "Mechanically, the warrior focuses on up-close physical "
                "damage with weapons and survives enemy attacks "
                "using heavy armor.\n";
    longdesc = "The warrior is the ultimate armor and weapons expert,"
                " relying on physical strength and years of training to "
                "deal with any obstacle. Mechanically, the warrior focuses "
                "on up-close physical damage with weapons and survives enemy "
                "attacks using heavy armor.\n";

    c = class_new(name, shortdesc, longdesc, NULL, NULL, NULL);

}

/* Tests init function for passive mission struct */
Test(passive_mission, init)
{
    int xp = 30;
    int levels = 5;
    int health = 10;

    passive_mission_t *p_mission = passive_mission_new(xp, levels, health);

    int check = passive_mission_init(p_mission, xp, levels, health);

    cr_assert_eq(check, SUCCESS,"passive_mission_init() failed");
    cr_assert_eq(p_mission->xp, 30,
                    "mission_init() did not set xp");
    cr_assert_eq(p_mission->levels, 5,
                    "mission_init() did not set levels");   
    cr_assert_eq(p_mission->health, 10,
                    "mission_init() did not set health");   
}

/* Tests init function for active mission struct */
Test(active_mission, init)
{   
    class_t* class = generate_test_class();
    char *npc_meet_id = "meet_npc";
    char *npc_kill_id = "kill_npc";

   	item_t *item_to_get = item_new("test_item", "item for testing",
    "test item for item_new()");
    npc_t *mission_meet_npc = npc_new(npc_meet_id ,"npc1", "npc to meet",
                                class, NULL, false);

    npc_t *mission_meet_kill = npc_new(npc_kill_id , "npc to kill", 
                                       "An npc to kill", class, NULL, false);
    room_t* room_to_visit = room_new("Grand ballroom", "A room", "A test room");

    active_mission_t *a_mission = malloc(sizeof(active_mission_t));

    int check = active_mission_init(a_mission, item_to_get, mission_meet_npc,
                             mission_meet_kill, room_to_visit);

    cr_assert_eq(check,SUCCESS,"active_mission_init() failed");
}

/* Tests init function for task struct */
Test(task, init)
{
	item_t *item_to_get = item_new("test_item", "item for testing",
    "test item for item_new()");
    char *id = "test mission";

    active_mission_t *a_mission = active_mission_new(item_to_get, NULL, NULL, NULL);

    mission_t *mission = malloc(sizeof(mission_t));
    mission->a_mission = a_mission;
    mission->p_mission = NULL;

    item_t *item = item_new("reward_item", "item for rewarding",
    "test item for item_new()");
    int xp = 40;
    reward_t *rewards = reward_new(xp, item);

    task_t *task = malloc(sizeof(task_t));

	int check = task_init(task, mission, id, rewards);

	cr_assert_eq(check, SUCCESS, "task_init() test has failed!");
}

Test(reward, new)
{
    int xp = 40;
	item_t *item = item_new("test_item", "item for testing",
    "test item for item_new()");

    reward_t *rewards = reward_new(xp, item);

    cr_assert_str_eq(rewards->item->item_id, "test_item",
                     "reward_new did not set item_id reward");
    cr_assert_eq(rewards->xp, 40,  "reward_new did not set xp");                 
}

Test(stat_req, new)
{
    int hp = 40;
    int level = 5;

    stat_req_t *stat_req = stat_req_new(hp, level);

      
    cr_assert_eq(stat_req->hp, 40, "reward_new did not set xp");
    cr_assert_eq(stat_req->level, 5, "reward_new did not set level");  

}

reward_t *create_sample_rewards(int xp, item_t *item)
{
    reward_t *rewards = malloc(sizeof(reward_t));

    rewards->xp = xp;
    rewards->item = item;

    return rewards;
}

stat_req_t *create_sample_stat_req(int hp, int level)
{
    stat_req_t *stat_req = malloc(sizeof(stat_req));

    stat_req->hp = hp;
    stat_req->level = level;

    return stat_req;
}

/* Tests new task malloc (new uses init) */
Test(task, new)
{
    item_t *item_to_get = item_new("test_item", "item for testing",
    "test item for item_new()");
    char *id = "test mission";

    active_mission_t *a_mission = active_mission_new(item_to_get, NULL, NULL, NULL);

    mission_t *mission = malloc(sizeof(mission_t));
    mission->a_mission = a_mission;
    mission->p_mission = NULL;

    item_t *item = item_new("reward_item", "item for rewarding",
    "test item for item_new()");
    int xp = 40;
    reward_t *rewards = reward_new(xp, item);

	task_t* task = task_new(mission, id, rewards);

	cr_assert_not_null(task, "task_new() test has failed!");

    cr_assert_eq(task->completed, 0, 
                     "task_init did not initialize completed bool");
}

/* Tests task_free function */
Test(task, free)
{
	item_t *item_to_get = item_new("test_item", "item for testing",
    "test item for item_new()");
    char *id = "test mission";

    active_mission_t *a_mission = active_mission_new(item_to_get, NULL, NULL, NULL);
    mission_t *mission = malloc(sizeof(mission_t));
    mission->a_mission = a_mission;
    mission->p_mission = NULL;

    item_t *item = item_new("reward_item", "item for rewarding",
    "test item for item_new()");
    int xp = 30;
    reward_t *rewards = reward_new(xp, item);

	task_t* task_to_free = task_new(mission, id, rewards);


	cr_assert_not_null(task_to_free, "task_free(): room is null");

	int freed = task_free(task_to_free);

	cr_assert_eq(freed, SUCCESS, "task_free() test has failed!");
}

/* Tests passive_mission_free function */
Test(active_mission, free)
{
    class_t* class = generate_test_class();
    char *npc_meet_id = "meet_npc";
    char *npc_kill_id = "kill_npc";

    item_t *item_to_get = item_new("test_item", "item for testing",
    "test item for item_new()");
    npc_t *mission_meet_npc = npc_new(npc_meet_id ,"npc1", "npc to meet",
                                class, NULL, false);

    npc_t *mission_meet_kill = npc_new(npc_kill_id ,"npc2", "npc to kill", 
                                       class, NULL, false);
    room_t* room_to_visit = room_new("Grand ballroom", "A room", "A test room");

    active_mission_t *a_mission = active_mission_new(item_to_get, mission_meet_npc,
                                                     mission_meet_kill, room_to_visit); 

    cr_assert_not_null(a_mission, "active_mission_free(): room is null");
    
    int freed = active_mission_free(a_mission);

    cr_assert_eq(freed, SUCCESS, "active_mission_free() test has failed!");
}

/* Tests passive_mission_free function by making xp node */
Test(passive_mission_xp, free)
{   
    int xp = 5;
    int level = 1;
    int health = 10;

    passive_mission_t *p_mission = passive_mission_new(xp, level, health);

    cr_assert_not_null(p_mission, "passive_mission_free(): room is null");

    int freed = passive_mission_free(p_mission);

	cr_assert_eq(freed, SUCCESS, "passive_mission_free() test has failed!");
}

/* Tests passive_mission_free function by making xp node */
Test(passive_mission_levels, free)
{   
    int xp = 5;
    int level = 1;
    int health = 10;

    passive_mission_t *p_mission = passive_mission_new(xp, level, health);

    cr_assert_not_null(p_mission, "passive_mission_free(): room is null");

    int freed = passive_mission_free(p_mission);

	cr_assert_eq(freed, SUCCESS, "passive_mission_free() test has failed!");
}

/* Tests passive_mission_free function by making xp node */
Test(passive_mission_health, free)
{   
    int xp = 5;
    int level = 1;
    int health = 10;

    passive_mission_t *p_mission = passive_mission_new(xp, level, health);

    cr_assert_not_null(p_mission, "passive_mission_free(): room is null");

    int freed = passive_mission_free(p_mission);

	cr_assert_eq(freed, SUCCESS, "passive_mission_free() test has failed!");
}
