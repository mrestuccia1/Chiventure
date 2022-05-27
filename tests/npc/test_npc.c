#include <criterion/criterion.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../../include/battle/battle_test_utility.h"

/* Checks that npc_quest_init() properly inits a new npc_quest struct */
Test(npc_quest, init)
{
    convo_t *c = convo_new();
    npc_quest_t quest;

    int check = npc_quest_init(&quest, "test", c);

    cr_assert_eq(check, SUCCESS, "npc_quest_init() failed to initialize");
    cr_assert_eq(quest.dialogue, c, "npc_quest_init() failed to set dialogue");
    cr_assert_eq(strcmp(quest.id, "test"), 0, "npc_quest_init() failed to set id");
    cr_assert_null(quest.next, "npc_quest_init() failed to make next NULL");
}

/* Checks that npc_quest_new() properly mallocs and inits a new npc_quest struct */
Test(npc_quest, new)
{
    convo_t *c = convo_new();
    npc_quest_t *quest = npc_quest_new("test", c);

    cr_assert_not_null(quest, "npc_quest_new() failed");
    cr_assert_eq(quest->dialogue, c, "npc_quest_new() failed to set dialogue");
    cr_assert_eq(strcmp(quest->id, "test"), 0, "npc_quest_new() failed to set id");
}

/* Checks that npc_quest_free() properly frees a npc_quest struct */
Test(npc_quest, free)
{
    convo_t *c = convo_new();
    npc_quest_t *quest_to_free = npc_quest_new("test", c);
    cr_assert_not_null(quest_to_free, "npc_quest_free() did not properly allocate quest");

    int freed = npc_quest_free(quest_to_free);

    cr_assert_eq(freed, SUCCESS, "npc_quest_free() failed to free");
}

/* Checks that npc_task_init() properly inits a new npc_task struct */
Test(npc_task, init)
{
    convo_t *c = convo_new();
    npc_task_t task;

    int check = npc_task_init(&task, "test", c);

    cr_assert_eq(check, SUCCESS, "npc_task_init() failed to initialize");
    cr_assert_eq(task.dialogue, c, "npc_task_init() failed to set dialogue");
    cr_assert_eq(strcmp(task.id, "test"), 0, "npc_task_init() failed to set id");
    cr_assert_null(task.next, "npc_task_init() failed to make next NULL");
}

/* Checks that npc_task_new() properly mallocs and inits a new npc_task struct */
Test(npc_task, new)
{
    convo_t *c = convo_new();
    npc_task_t *task = npc_task_new("test", c);

    cr_assert_not_null(task, "npc_task_new() failed");
    cr_assert_eq(task->dialogue, c, "npc_task_init() failed to set dialogue");
    cr_assert_eq(strcmp(task->id, "test"), 0, "npc_task_init() failed to set id");
}

/* Checks that npc_task_free() properly frees a npc_task struct */
Test(npc_task, free)
{
    convo_t *c = convo_new();
    npc_task_t *task_to_free = npc_task_new("test", c);
    cr_assert_not_null(task_to_free, "npc_task_free() did not properly allocate quest");

    int freed = npc_task_free(task_to_free);

    cr_assert_eq(freed, SUCCESS, "npc_task_free() failed to free");
}

/* Checks that npc_quest_list_new() properly creates a npc_quest_list struct */
Test(npc_quest_list, new)
{
    npc_quest_list_t *quest_list = npc_quest_list_new();
    cr_assert_not_null(quest_list, "npc_quest_list_new() failed");
    cr_assert_null(quest_list->head->next, "npc_quest_list_new() failed to make next NULL");
    cr_assert_eq(quest_list->length, 1, "npc_quest_list_new() failed to make length 1");
}

/* Checks that npc_task_list_new() properly creates a npc_task_list struct */
Test(npc_task_list, new)
{
    npc_task_list_t *task_list = npc_task_list_new();
    cr_assert_not_null(task_list, "npc_task_list_new() failed");
    cr_assert_null(task_list->head->next, "npc_task_list_new() failed to make next NULL");
    cr_assert_eq(task_list->length, 1, "npc_task_list_new() failed to make length 1");
}

/* Checks that npc_quest_list_init() properly initializes a npc_quest_list struct
Test(npc_quest_list, init)
{
    npc_quest_list_t *quest_list;
    quest_list = malloc(sizeof(npc_quest_list_t));

    if (!quest_list) {
        fprintf(stderr, "\nCould not allocate memory for NPC quest list!\n");
        return NULL;
    }

    int rc = npc_quest_list_init(quest_list);

    cr_assert_eq(rc, SUCCESS, "npc_quest_list_init() failed to initialize");
    cr_assert_not_null(quest_list, "npc_quest_list_init() failed");
    cr_assert_null(quest_list->head->next, "npc_quest_list_init() failed to make next NULL");
    cr_assert_eq(quest_list->length, 1, "npc_quest_list_init() failed to make length 1");
}*/

/* Checks that npc_task_list_init() properly initializes a npc_task_list struct
Test(npc_task_list, init)
{
    npc_task_list_t *task_list;
    task_list = malloc(sizeof(npc_task_list_t));

    if (!task_list) {
        fprintf(stderr, "\nCould not allocate memory for NPC task list!\n");
        return NULL;
    }

    int rc = npc_task_list_init(task_list);

    cr_assert_eq(rc, SUCCESS, "npc_task_list_init() failed to initialize");
    cr_assert_not_null(task_list, "npc_task_list_init() failed");
    cr_assert_null(task_list->head->next, "npc_task_list_init() failed to make next NULL");
    cr_assert_eq(task_list->length, 1, "npc_task_list_new() failed to make length 1");
}*/

/* Checks that npc_quest_list_add() properly adds a npc_quest struct to a npc_quest_list_t
Test(npc_quest_list, add)
{
    convo_t *c1 = convo_new();
    npc_quest_t *quest1 = npc_quest_new("test1", c1);
    cr_assert_not_null(quest1, "npc_quest_new() failed");

    convo_t *c2 = convo_new();
    npc_quest_t *quest2 = npc_quest_new("test2", c2);
    cr_assert_not_null(quest2, "npc_quest_new() failed");

    npc_quest_list_t *quest_list = npc_quest_list_new();
    cr_assert_not_null(quest_list, "npc_quest_list_new() failed");

    int add1 = npc_quest_list_add(quest_list, quest1);
    cr_assert_eq(add1, SUCCESS, "npc_quest_list_add() failed to add a quest");
    cr_assert_cq(quest_list->head->next, quest1, "npc_quest_list_add() failed to set head->next to quest1");

    int add2 = npc_quest_list_add(quest_list, quest2);
    cr_assert_eq(add2, SUCCESS, "npc_quest_list_add() failed to add a second quest");
    cr_assert_cq(quest_list->head->next->next, quest2, "npc_quest_list_add() failed to set head->next->next to quest2");
}*/

/* Checks that npc_task_list_add() properly adds a npc_task struct to a npc_task_list_t
Test(npc_task_list, add)
{
    convo_t *c1 = convo_new();
    npc_task_t *task1 = npc_task_new("test1", c1);
    cr_assert_not_null(task1, "npc_task_new() failed");

    convo_t *c2 = convo_new();
    npc_task_t *task2 = npc_task_new("test2", c2);
    cr_assert_not_null(task2, "npc_task_new() failed");

    npc_task_list_t *task_list = npc_task_list_new();
    cr_assert_not_null(task_list, "npc_task_list_new() failed");

    int add1 = npc_task_list_add(task_list, task1);
    cr_assert_eq(add1, SUCCESS, "npc_task_list_add() failed to add a task");
    cr_assert_cq(task_list->head->next, task1, "npc_task_list_add() failed to set head->next to task1");

    int add2 = npc_task_list_add(task_list, task2);
    cr_assert_eq(add2, SUCCESS, "npc_task_list_add() failed to add a second task");
    cr_assert_cq(task_list->head->next->next, task2, "npc_task_list_add() failed to set head->next->next to task2");
}*/

/* Checks that npc_task_list_add() properly frees a npc_task_list_t
Test(npc_quest_list, free)
{
    convo_t *c1 = convo_new();
    npc_quest_t *quest1 = npc_quest_new("test1", c1);
    cr_assert_not_null(quest1, "npc_quest_new() failed");

    convo_t *c2 = convo_new();
    npc_quest_t *quest2 = npc_quest_new("test2", c2);
    cr_assert_not_null(quest2, "npc_quest_new() failed");

    npc_quest_list_t *quest_list = npc_quest_list_new();
    cr_assert_not_null(quest_list, "npc_quest_list_new() failed");

    int add1 = npc_quest_list_add(quest_list, quest1);
    cr_assert_eq(add1, SUCCESS, "npc_quest_list_add() failed to add a quest");

    int add2 = npc_quest_list_add(quest_list, quest2);
    cr_assert_eq(add2, SUCCESS, "npc_quest_list_add() failed to add a second quest");

    int free = npc_quest_list_free(quest_list);
    cr_assert_eq(free, SUCCESS, "npc_quest_list_free() failed to free the quest list");
    cr_assert_null(quest_list, "npc_quest_list_free failed to free quest_list");
    cr_assert_null(quest_list->head, "npc_quest_list_free failed to free the head");
    cr_assert_null(quest_list->head->next, "npc_quest_list_free failed to free next");
    cr_assert_null(quest_list->head->next->next, "npc_quest_list_free failed to free next next");
}*/

/* Checks that npc_task_list_free() properly frees a npc_task_list_t
Test(npc_task_list, free)
{
    convo_t *c1 = convo_new();
    npc_task_t *task1 = npc_task_new("test1", c1);
    cr_assert_not_null(task1, "npc_task_new() failed");

    convo_t *c2 = convo_new();
    npc_task_t *task2 = npc_task_new("test2", c2);
    cr_assert_not_null(task2, "npc_task_new() failed");

    npc_task_list_t *task_list = npc_task_list_new();
    cr_assert_not_null(task_list, "npc_task_list_new() failed");

    int rc = npc_task_list_init(task_list);
    cr_assert_eq(rc, SUCCESS, "npc_task_list_init() failed to initialize");

    int add1 = npc_task_list_add(task_list, task1);
    cr_assert_eq(add1, SUCCESS, "npc_task_list_add() failed to add a task");

    int add2 = npc_task_list_add(task_list, task2);
    cr_assert_eq(add2, SUCCESS, "npc_task_list_add() failed to add a second task");

    int free = npc_task_list_free(task_list);
    cr_assert_eq(free, SUCCESS, "npc_task_list_free() failed to free the task list");
    cr_assert_null(task_list, "npc_task_list_free failed to free task_list");
    cr_assert_null(task_list->head, "npc_task_list_free failed to free the head");
    cr_assert_null(task_list->head->next, "npc_task_list_free failed to free next");
    cr_assert_null(task_list->head->next->next, "npc_task_list_free failed to free next next");
}*/

/* Checks that npc_new() properly mallocs and inits a new npc struct */
Test(npc, new)
{
    class_t *c;
    npc_t *npc;
    npc_mov_t *movement = generate_test_npc_mov();

    char *npc_id = "npc_22";

    c = make_new_warrior_class();
    movement = generate_test_npc_mov();

    npc = npc_new(npc_id, "man", "tall man", c, movement, FRIENDLY);

    cr_assert_not_null(npc, "npc_new() failed");

    cr_assert_eq(strncmp(npc->npc_id, "npc_22", MAX_ID_LEN), 0,
                 "npc_new didn't set npc_id");
    cr_assert_eq(strncmp(npc->short_desc, "man", MAX_SDESC_LEN), 0,
                 "npc_new didn't set short_desc");
    cr_assert_eq(strncmp(npc->long_desc, "tall man", MAX_LDESC_LEN), 0,
                 "npc_new didn't set long_desc");
    cr_assert_str_eq(npc->class->shortdesc,
                     c->shortdesc, "npc_new didn't set short description for class");
    cr_assert_str_eq(npc->movement->track, movement->track,
                     "npc_new didn't set current room id");
    cr_assert_str_eq(npc->movement->path->room_id, movement->path->room_id,
                     "npc_new didn't set npc_path");
    cr_assert_eq(npc->hostility_level, FRIENDLY,
                 "npc_new didn't set hostility_level");
}


/* Checks that npc_init() initialized the fields in the new npc struct */
Test(npc, init)
{
    class_t *c;
    npc_t *npc;
    npc_mov_t *movement = generate_test_npc_mov();
    int res;

    char *npc_id2 = "test";

    npc = npc_new(npc_id2, "woman", "short woman", NULL, movement, FRIENDLY);

    c = make_new_warrior_class();
    movement = generate_test_npc_mov();

    char *npc_id = "npc_22";

    res = npc_init(npc, npc_id, "man", "tall man", c, movement, FRIENDLY);

    cr_assert_eq(res, SUCCESS, "npc_init() failed");

    cr_assert_eq(strncmp(npc->npc_id, "npc_22", MAX_ID_LEN), 0,
                 "npc_init didn't set npc_id");
    cr_assert_eq(strncmp(npc->short_desc, "man", MAX_SDESC_LEN), 0,
                 "npc_init didn't set short_desc");
    cr_assert_eq(strncmp(npc->long_desc, "tall man", MAX_LDESC_LEN), 0,
                 "npc_init didn't set long_desc");
    cr_assert_str_eq(npc->class->shortdesc,
                     c->shortdesc, "npc_init didn't set short description for class");
    cr_assert_str_eq(npc->movement->track, movement->track,
                     "npc_new didn't set current room id");
    cr_assert_str_eq(npc->movement->path->room_id,
                     movement->path->room_id,
                     "npc_new didn't set npc_path");
    cr_assert_eq(npc->hostility_level, FRIENDLY,
                 "npc_init didn't set hostility_level");
}


/* Checks that npc_free() frees the given npc struct from memory */
Test(npc, free)
{
    npc_t *npc;
    int res;
    char *npc_id = "test";

    npc = npc_new(npc_id, "woman", "short woman", NULL, NULL, FRIENDLY);

    cr_assert_not_null(npc, "npc_new() failed");

    res = npc_free(npc);

    cr_assert_eq(res, SUCCESS, "npc_free() failed");

}

/* Checks that get_sdesc_npc() returns the short description of the npc */
Test(npc, get_sdesc_npc)
{
    npc_t *npc;
    char *get;

    char *npc_id = "test";

    npc = npc_new(npc_id, "woman", "short woman", NULL, NULL, FRIENDLY);

    cr_assert_not_null(npc, "npc_new() failed");
    cr_assert_eq(strncmp(npc->short_desc, "woman", MAX_SDESC_LEN), 0,
                 "npc_new didn't set short_desc");

    get = get_sdesc_npc(npc);

    cr_assert_not_null(get, "get_sdesc_npc() failed");
    cr_assert_eq(strncmp(get, "woman", MAX_SDESC_LEN), 0,
                 "get_sdesc_npc() didn't get npc's short_desc");
}

/* Checks that get_ldesc_npc() returns the long description of the npc */
Test(npc, get_ldesc_npc)
{
    npc_t *npc;
    char *get;

    char *npc_id = "test";

    npc = npc_new(npc_id, "man", "tall man", NULL, NULL, FRIENDLY);

    cr_assert_not_null(npc, "npc_new() failed");
    cr_assert_eq(strncmp(npc->long_desc, "tall man", MAX_LDESC_LEN), 0,
                 "npc_new didn't set long_desc");

    get = get_ldesc_npc(npc);

    cr_assert_not_null(get, "get_ldesc_npc() failed");
    cr_assert_eq(strncmp(get, "tall man", MAX_LDESC_LEN), 0,
                 "get_ldesc_npc() didn't get npc's long_desc");
}

/* Checks that get_inventory() returns the npc's inventory */
Test(npc, add_to_and_get_inventory)
{
    npc_t *npc1, *npc2;
    item_t *new_item;
    item_hash_t *hash1, *hash2;
    item_list_t *list1, *list2;
    char *npc_id1 = "npc_1";
    char *npc_id2 = "npc_2";

    npc1 = npc_new(npc_id1, "short", "long", NULL, NULL, FRIENDLY);
    npc2 = npc_new(npc_id2, "short", "long", NULL, NULL, FRIENDLY);
    new_item = item_new("test_item", "item for npc testing",
                        "item for testing get_npc_inventory()");
    add_item_to_npc(npc2, new_item);

    hash1 = get_npc_inv_hash(npc1);
    hash2 = get_npc_inv_hash(npc2);

    list1 = get_npc_inv_list(npc1);
    list2 = get_npc_inv_list(npc2);

    // Assert everything was made and malloced
    cr_assert_not_null(npc1, "npc_new() failed on npc1");
    cr_assert_not_null(npc2, "npc_new() failed on npc2");
    cr_assert_not_null(new_item, "item_new() failed");

    // Check that inventory with added item is not NULL
    cr_assert_not_null(npc2->inventory,
                       "add_item_to_npc() failed to add item");

    // Check inventory hashes
    cr_assert_eq(hash1, npc1->inventory, "get_npc_inv_hash() failed to "
                 "return NULL for empty inventory");
    cr_assert_eq(hash2, npc2->inventory,
                 "get_npc_inv_hash() failed to return inventory");

    // Check inventory lists
    cr_assert_eq(list1, NULL, "get_npc_inv_list() failed to "
                 "return NULL for empty inventory");
    cr_assert_not_null(list2, "get_npc_inventory() failed to "
                       "return inventory list");

    // Check that added item has correct fields
    cr_assert_eq(strcmp(new_item->item_id, list2->item->item_id), 0,
                 "add_item_to_npc() failed to add item (id is wrong)");
    cr_assert_eq(strcmp(new_item->short_desc, list2->item->short_desc), 0,
                 "add_item_to_npc() failed to add item (short desc is wrong)");
    cr_assert_eq(strcmp(new_item->long_desc, list2->item->long_desc), 0,
                 "add_item_to_npc() failed to add item (long desc is wrong)");
}

/* Checks that add_item_to_npc adds item to the npc struct's inventory
   by not returning NULL */
Test(npc, add_item_to_npc)
{
    char *npc_id = "1";
    npc_t *npc = npc_new(npc_id, "short", "long", NULL, NULL, FRIENDLY);
    item_t *new_item = item_new("test_item", "item for npc testing",
                                "item for testing add_item_to_npc");
    item_t *dup_item = item_new("test_item", "item for npc testing",
                                "item for testing add_item_to_npc");
    add_item_to_npc(npc, new_item);

    cr_assert_not_null(npc, "npc_new() failed");
    cr_assert_not_null(new_item, "item_new() failed");
    cr_assert_not_null(npc->inventory,
                       "add_item_to_npc() failed to add item");

    int rc = add_item_to_npc(npc, dup_item);
    cr_assert_eq(rc, SUCCESS, "add_item_to_npc failed to add "
                 "item with identical id");
}

/* Checks that remove_item_from_npc properly removes items */
Test(npc, remove_item_from_npc)
{
    char *npc_id = "npc";
    npc_t *npc = npc_new(npc_id, "short", "long", NULL, NULL, FRIENDLY);
    item_t *test_item = item_new("item", "short", "long");
    item_t *dup_item = item_new("item", "short", "long");
    item_list_t *item_list;
    int rc;

    rc = add_item_to_npc(npc, test_item);
    cr_assert_eq(rc, SUCCESS, "add_item_to_npc failed to "
                 "add an item to npc");
    rc = add_item_to_npc(npc, dup_item);
    cr_assert_eq(rc, SUCCESS, "add_item_to_npc failed to "
                 "add an item to npc");

    rc = remove_item_from_npc(npc, test_item);
    cr_assert_eq(rc, SUCCESS, "remove_item_from_npc failed to "
                 "remove an item from npc");

    item_list = get_npc_inv_list(npc);
    cr_assert_not_null(item_list, "remove_item_from_npc removed "
                       "both identical items from npc");
}

/* Checks that add_battle_to_npc adds the correct npc_battle struct to an npc */
Test(npc, add_battle_to_npc)
{
    char *npc_id = "npc";
    npc_t *npc = npc_new(npc_id, "short", "long", NULL, NULL, HOSTILE);
    cr_assert_not_null(npc, "npc_new() failed");

    stat_t *stats = create_enemy_stats_v1();
    move_t *moves = create_enemy_moves_v1();


    stat_changes_t *dagger_changes = stat_changes_new();
    dagger_changes->phys_atk = 20;
    dagger_changes->phys_def = 5;
    dagger_changes->hp = 0;
                        
    battle_item_t *dagger = create_battle_item(1, 1,
                            "A hearty dagger sure to take your breath away... for good",
                            "dagger", true, NULL);

    int res = add_battle_to_npc(npc, stats, moves, BATTLE_AI_GREEDY, 
		                HOSTILE, make_new_warrior_class(), dagger, NULL, NULL, NULL);


    cr_assert_eq(res, SUCCESS, "add_battle_to_npc() failed");
    cr_assert_not_null(npc->npc_battle,
                       "add_battle_to_npc() didn't set npc_battle");

    res = npc_free(npc);
    cr_assert_eq(res, SUCCESS, "npc_free() failed");
}

/* Checks that get_npc_battle returns a pointer to the npc_battle struct
 * associated with the npc or NULL if there is no such struct */
Test(npc, get_npc_battle)
{
    char *npc_id = "npc";
    npc_t *npc = npc_new(npc_id, "short", "long", NULL, NULL, HOSTILE);
    cr_assert_not_null(npc, "npc_new() failed");

    npc_battle_t *null_npc_battle = get_npc_battle(npc);
    cr_assert_null(null_npc_battle,
                   "get_npc_battle() didn't return NULL given npc with NULL"
                   "npc_battle");

    stat_t *stats = create_enemy_stats_v1();
    move_t *moves = create_enemy_moves_v1();


    stat_changes_t *dagger_changes = stat_changes_new();
    dagger_changes->phys_atk = 20;
    dagger_changes->phys_def = 5;
    dagger_changes->hp = 0;                        
    battle_item_t *dagger = create_battle_item(1, 20, "A hearty dagger sure to take your breath away... for good", "Dagger", true, 
		    dagger_changes);

    int res = add_battle_to_npc(npc, stats, moves, BATTLE_AI_GREEDY,
                                HOSTILE, make_new_warrior_class(), dagger,

                                NULL, NULL, NULL);
    cr_assert_eq(res, SUCCESS, "add_battle_to_npc() failed");

    npc_battle_t *npc_battle = get_npc_battle(npc);
    cr_assert_not_null(npc_battle,
                       "get_npc_battle() returned NULL given NPC with non-NULL"
                       "npc_battle");

    res = npc_free(npc);
    cr_assert_eq(res, SUCCESS, "npc_free() failed");
}

/* Checks that an npc's health is changed by change_npc_health()
   both positively and negatively with a set maximum */
Test (npc, change_npc_hp)
{
    char *npc_id = "npc";
    npc_t *npc = npc_new(npc_id, "short", "long", NULL, NULL, HOSTILE);
    cr_assert_not_null(npc, "npc_new() failed");

    stat_t *stats = create_enemy_stats_v1();
    move_t *moves = create_enemy_moves_v1();

    battle_item_t *dagger = create_battle_item(1, 1,
                            "A hearty dagger sure to take your breath away... for good",
                            "dagger", true, NULL);

    int res = add_battle_to_npc(npc, stats, moves, BATTLE_AI_GREEDY,
                                HOSTILE, make_new_warrior_class(), dagger,
                                NULL, NULL, NULL);
    cr_assert_eq(res, SUCCESS, "add_battle_to_npc() failed");

    /* current hp level set in create_enemy_stats() is 200 */
    int hp1 = change_npc_hp(npc, -30);
    cr_assert_eq(hp1, 170,
                 "change_npc_hp() didn't decrease hp correctly");
    cr_assert_eq(npc->npc_battle->stats->hp, 170,
                 "change_npc_hp() didn't change hp in npc_battle struct");

    /* current max_hp level set in create_enemy_stats() is 200 */
    int hp2 = change_npc_hp(npc, 40);
    cr_assert_eq(hp2, 200,
                 "change_npc_hp() increased hp past max_hp");
    cr_assert_eq(npc->npc_battle->stats->hp, 200,
                 "change_npc_hp() didn't change hp in npc_battle struct");

    int hp3 = change_npc_hp(npc, -90);
    cr_assert_eq(hp3, 110,
                 "change_npc_hp() didn't decrease health correctly");
    cr_assert_eq(npc->npc_battle->stats->hp, 110,
                 "change_npc_hp() didn't change hp in npc_battle struct");

    int hp4 = change_npc_hp(npc, 5);
    cr_assert_eq(hp4, 115,
                 "change_npc_hp() didn't increase health correctly");
    cr_assert_eq(npc->npc_battle->stats->hp, 115,
                 "change_npc_hp() didn't change hp in npc_battle struct");

    int hp5 = change_npc_hp(npc, -120);
    cr_assert_eq(hp5, 0,
                 "change_npc_hp() set a negative hp");
    cr_assert_eq(npc->npc_battle->stats->hp, 0,
                 "change_npc_hp() didn't change hp in npc_battle struct");

    res = npc_free(npc);
    cr_assert_eq(res, SUCCESS, "npc_free() failed");
}

/* Checks that get_npc_hp returns an npc's hp if its npc_battle struct
 * is initialized and otherwise returns -1 */
Test(npc, get_npc_hp)
{
    char *npc_id = "npc";
    npc_t *npc = npc_new(npc_id, "short", "long", NULL, NULL, HOSTILE);
    cr_assert_not_null(npc, "npc_new() failed");


    stat_t *stats = create_enemy_stats_v1();
    move_t *moves = create_enemy_moves_v1();

    stat_changes_t *dagger_changes = stat_changes_new();
    dagger_changes->phys_atk = 20;
    dagger_changes->phys_def = 5;
    dagger_changes->hp = 0;                        
    battle_item_t *dagger = create_battle_item(1, 20, "A hearty dagger sure to take your breath away... for good", "Dagger", true,
                                dagger_changes);

    int res = add_battle_to_npc(npc, stats, moves, BATTLE_AI_GREEDY,
                                HOSTILE, make_new_warrior_class(), dagger,

                                NULL, NULL, NULL);
    cr_assert_eq(res, SUCCESS, "add_battle_to_npc() failed");

    int hp = get_npc_hp(npc);
    cr_assert_eq(hp, 200,
                 "get_npc_hp() failed for npc with non-NULL npc_battle");

    res = npc_free(npc);
    cr_assert_eq(res, SUCCESS, "npc_free() failed");
}

/* Checks that get_npc_max_hp returns an npc's max_hp if its npc_battle struct
 * is initialized and otherwise returns -1 */
Test(npc, get_npc_max_hp)
{
    char *npc_id = "npc";
    npc_t *npc = npc_new(npc_id, "short", "long", NULL, NULL, HOSTILE);
    cr_assert_not_null(npc, "npc_new() failed");

    int max_hp = get_npc_max_hp(npc);
    cr_assert_eq(max_hp, -1,
                 "get_npc_max_hp() failed for npc with NULL npc_battle");

    stat_t *stats = create_enemy_stats_v1();
    move_t *moves = create_enemy_moves_v1();


    stat_changes_t *dagger_changes = stat_changes_new();
    dagger_changes->phys_atk = 20;
    dagger_changes->phys_def = 5;
    dagger_changes->hp = 0;                        
    battle_item_t *dagger = create_battle_item(1, 20, "A hearty dagger sure to take your breath away... for good", "Dagger", true,
                                dagger_changes);

    int res = add_battle_to_npc(npc, stats, moves, BATTLE_AI_GREEDY,
                                HOSTILE, make_new_warrior_class(), dagger,

                                NULL, NULL, NULL);
    cr_assert_eq(res, SUCCESS, "add_battle_to_npc() failed");

    max_hp = get_npc_max_hp(npc);
    cr_assert_eq(max_hp, 200,
                 "get_npc_max_hp() failed for npc with non-NULL npc_battle");

    res = npc_free(npc);
    cr_assert_eq(res, SUCCESS, "npc_free() failed");
}

/* Checks that check_npc_battle returns false iff an npc is HOSTILE
 * but has npc_battle = NULL */
Test(npc, check_npc_battle)
{
    char *npc_id = "npc";
    npc_t *npc1 = npc_new(npc_id, "short", "long", NULL, NULL, CONDITIONAL_FRIENDLY);
    cr_assert_not_null(npc1, "npc_new() failed");
    npc_t *npc2 = npc_new(npc_id, "short", "long", NULL, NULL, HOSTILE);
    cr_assert_not_null(npc2, "npc_new() failed");

    cr_assert_eq(check_npc_battle(npc1), true,
                 "check_npc_battle failed; hostility_level=CONDITIONAL_FRIENDLY, npc_battle=NULL");
    cr_assert_eq(check_npc_battle(npc2), false,
                 "check_npc_battle failed; hostility_level=HOSTILE, npc_battle=NULL");

    stat_t *stats1 = create_enemy_stats_v1();
    move_t *moves1 = create_enemy_moves_v1();
    stat_t *stats2 = create_enemy_stats_v2();
    move_t *moves2 = create_enemy_moves_v2();


    stat_changes_t *dagger_changes1 = stat_changes_new();
    dagger_changes1->phys_atk = 20;
    dagger_changes1->phys_def = 5;
    dagger_changes1->hp = 0;                        
    battle_item_t *dagger1 = create_battle_item(1, 20, "A hearty dagger sure to take your breath away... for good", "Dagger", true,
                                dagger_changes1);

    stat_changes_t *dagger_changes2 = stat_changes_new();
    dagger_changes2->phys_atk = 20;
    dagger_changes2->phys_def = 5;
    dagger_changes2->hp = 0;                        
    battle_item_t *dagger2 = create_battle_item(1, 20, "A hearty dagger sure to take your breath away... for good", "Dagger", true,
		    dagger_changes2);

    int res = add_battle_to_npc(npc1, stats1, moves1, BATTLE_AI_GREEDY,
                                HOSTILE, make_new_warrior_class(), dagger1,
                                NULL, NULL, NULL);
    cr_assert_eq(res, SUCCESS, "add_battle_to_npc() failed");
    res = add_battle_to_npc(npc2, stats2, moves2, BATTLE_AI_GREEDY,
                                HOSTILE, make_new_warrior_class(), dagger2,
                                NULL, NULL, NULL);

    cr_assert_eq(res, SUCCESS, "add_battle_to_npc() failed");

    cr_assert_eq(check_npc_battle(npc1), true,
                 "check_npc_battle failed; will_fight=false, npc_battle!=NULL");
    cr_assert_eq(check_npc_battle(npc2), true,
                 "check_npc_battle failed; will_fight=true, npc_battle!=NULL");

    res = npc_free(npc1);
    cr_assert_eq(res, SUCCESS, "npc_free() failed");
    res = npc_free(npc2);
    cr_assert_eq(res, SUCCESS, "npc_free() failed");
}
