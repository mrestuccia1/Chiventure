#include <criterion/criterion.h>
#include <stdlib.h>
#include <stdbool.h>
#include "npc/npc.h"
#include "game-state/item.h"
#include "playerclass/class.h"


/* Creates a sample class. Taken from test_class.c */
class_t *generate_test_class()
{
    class_t *c;
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

/* Creates a sample npc_mov struct. Taken from test_npc_move.c */
npc_mov_t *generate_test_npc_mov()
{
    npc_mov_t *npc_mov;
    room_t *test_room;
    test_room = room_new("test_room", "test", "test test");
    npc_mov = npc_mov_new(NPC_MOV_DEFINITE, test_room);
}

/* Creates example stats. Taken from test_battle_ai.c */
stat_t *create_enemy_stats()
{
    stat_t *test_stats = calloc(1, sizeof(stat_t));

    test_stats->speed = 50;
    test_stats->phys_def = 20;
    test_stats->phys_atk = 150;
    test_stats->hp = 200;
    test_stats->max_hp = 200;
    test_stats->xp = 0;
    test_stats->level = 5;

    return test_stats;
}

/* Creates + initializes a move. Taken from test_battle_ai.c */
move_t *create_move_(int id, battle_item_t* item, bool attack, int damage,
                     int defense)
{
    move_t *move = (move_t*) calloc(1, sizeof(move_t));

    move->id = id;

    move->item = item;

    move->attack = attack;
    move->damage = damage;
    move->defense = defense;

    return move;
}

/* Creates example moves. Taken from test_battle_ai.c */
move_t *create_enemy_moves()
{
    move_t *head, *earthquake, *poke, *rock_throw;
    head = NULL;
    earthquake = create_move_(1, NULL, true, 100, 0);
    poke = create_move_(2, NULL, true, 40, 0);
    rock_throw = create_move_(3, NULL, true, 90, 0);
    DL_APPEND(head, earthquake);
    DL_APPEND(head, poke);
    DL_APPEND(head, rock_throw);
    return head;
}

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
    cr_assert_str_eq(npc->movement->npc_mov_type.npc_mov_definite->npc_path->room->room_id,
                     movement->npc_mov_type.npc_mov_definite->npc_path->room->room_id,
                     "npc_new didn't set npc_path");
    cr_assert_eq(npc->will_fight, false,
                 "npc_new didn't set will_fight");
}


/* Checks that npc_init() initialized the fields in the new npc struct */
Test(npc, init)
{
    class_t *c;
    npc_t *npc;
    npc_mov_t *movement = generate_test_npc_mov();
    int res;

    char *npc_id2 = "test";

    npc = npc_new(npc_id2, "woman", "short woman", NULL, movement, false);

    c = generate_test_class();
    movement = generate_test_npc_mov();

    char *npc_id = "npc_22";

    res = npc_init(npc, npc_id, "man", "tall man", c, movement, false);

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
    cr_assert_str_eq(npc->movement->npc_mov_type.npc_mov_definite->npc_path->room->room_id,
                     movement->npc_mov_type.npc_mov_definite->npc_path->room->room_id,
                     "npc_new didn't set npc_path");
    cr_assert_eq(npc->will_fight, false,
                 "npc_init didn't set will_fight");
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
    cr_assert_eq(rc, FAILURE, "add_item_to_npc added duplicate item");
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
    cr_assert_null(item_list, "npc's inventory isn't empty");
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


    int res = add_battle_to_npc(npc, 100, stats, moves, BATTLE_AI_GREEDY,
                                HOSTILE, 25);
    cr_assert_eq(res, SUCCESS, "add_battle_to_npc() failed");
    cr_assert_not_null(npc->npc_battle,
                       "add_battle_to_npc() didn't set npc_battle");
    cr_assert_eq(npc->npc_battle->health, 100,
                 "add_battle_to_npc() didn't set health in npc_battle");

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

    int res = add_battle_to_npc(npc, stats, moves, BATTLE_AI_GREEDY,
                                HOSTILE, make_new_warrior_class(), dagger,

                                NULL, NULL, NULL);
    cr_assert_eq(res, SUCCESS, "add_battle_to_npc() failed");

    npc_battle_t *npc_battle = get_npc_battle(npc);
    cr_assert_not_null(npc_battle,
                       "get_npc_battle() returned NULL given NPC with non-NULL"
                       "npc_battle");
    cr_assert_eq(npc_battle->health, 100,
                 "get_npc_battle() returned a struct with the wrong health");

    res = npc_free(npc);
    cr_assert_eq(res, SUCCESS, "npc_free() failed");
}

/* Checks that an npc's health is changed by change_npc_health()
   both positively and negatively with a set maximum */
Test (npc, change_npc_health)
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

    int health1 = change_npc_health(npc, 30, 100);
    cr_assert_eq(health1, 100,
                 "change_npc_health() increased health past max");
    cr_assert_eq(npc->npc_battle->health, 100,
                 "change_npc_health didn't change health in npc_battle struct");

    int health2 = change_npc_health(npc, -20, 100);
    cr_assert_eq(health2, 80,
                 "change_npc_health() didn't decrease health correctly");
    cr_assert_eq(npc->npc_battle->health, 80,
                 "change_npc_health didn't change health in npc_battle struct");

    int health3 = change_npc_health(npc, 3, 100);
    cr_assert_eq(health3, 83,
                 "change_npc_health() didn't increase health correctly");
    cr_assert_eq(npc->npc_battle->health, 83,
                 "change_npc_health didn't change health in npc_battle struct");

    int health4 = change_npc_health(npc, -90, 100);
    cr_assert_eq(health4, 0,
                 "change_npc_health() set a negative health");
    cr_assert_eq(npc->npc_battle->health, 0,
                 "change_npc_health didn't change health in npc_battle struct");

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

    int health = get_npc_health(npc);
    cr_assert_eq(health, -1,
                 "get_npc_health() failed for npc with NULL npc_battle");

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

    health = get_npc_health(npc);
    cr_assert_eq(health, 80,
                 "get_npc_health() failed for npc with non-NULL npc_battle");

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
                 "check_npc_battle failed; will_fight=false, npc_battle=NULL");
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
    res = add_battle_to_npc(npc2, 80, stats2, moves2, BATTLE_AI_GREEDY,
                            HOSTILE, 25);
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

/* Create an NPC and change it's hostility level from conditional friendly
 * to hostile. */
Test(dialogue, make_npc_hostile)
{
    npc_t *npc = npc_new("npc", "short", "long", NULL, NULL, CONDITIONAL_FRIENDLY);

    make_npc_hostile(npc);

    cr_assert_eq(npc->hostility_level, HOSTILE, 
    "The hostility level is %d (0=friendly, 1=cond_friendly, 2=hostile)"
    "when it should be 2 (hostile).", npc->hostility_level);
}

/* Create an NPC and change it's hostility level from hostile
* to conditional_friendly. */
Test(dialogue, make_npc_cond_friendly_from_hostile)
{
    npc_t *npc = npc_new("npc", "short", "long", NULL, NULL, HOSTILE);

    make_npc_cond_friendly(npc);

    cr_assert_eq(npc->hostility_level, CONDITIONAL_FRIENDLY, 
    "The hostility level is %d (0=friendly, 1=cond_friendly, 2=hostile)"
    "when it should be 1 (cond_friendly).", npc->hostility_level);
}

/* Create an NPC and change it's hostility level from hostile
* to conditional_friendly. */
Test(dialogue, make_npc_cond_friendly_from_friendly)
{
    npc_t *npc = npc_new("npc", "short", "long", NULL, NULL, FRIENDLY);

    make_npc_cond_friendly(npc);

    cr_assert_eq(npc->hostility_level, CONDITIONAL_FRIENDLY, 
    "The hostility level is %d (0=friendly, 1=cond_friendly, 2=hostile)"
    "when it should be 1 (cond_friendly).", npc->hostility_level);
}

/* Create an NPC and change its hostility to hostile based on edge tone */
Test(dialogue, change_npc_hostility_hostile)
{
    npc_t *npc = npc_new("npc", "short", "long", NULL, NULL, NEUTRAL);

    convo_t *convo = convo_new();
    cr_assert_eq(convo_init(convo), SUCCESS, "convo was not initialized properly");

    cr_assert_eq(add_node(convo, "1",
                          "NPC: How do I look today?", NEUTRAL), SUCCESS,
                          "node was not added properly");

    cr_assert_eq(add_node(convo, "1A",
                          "Ugh, so rude.", NEGATIVE), SUCCESS,
                          "node was not added properly");

    cr_assert_eq(add_edge(convo, "Player: Your hair looks ugly today", "1",
                          "1A", NULL, NEGATIVE), SUCCESS, 
                          "edge was not added properly");

    cr_assert_eq(change_npc_hostility(npc, convo->all_edges->edge), SUCCESS, 
                 "NPC hostility was not changed to hostile");
}

/* Create an NPC and change its hostility to hostile based on edge tone */
Test(dialogue, change_npc_hostility_friendly)
{
    npc_t *npc = npc_new("npc", "short", "long", NULL, NULL, NEUTRAL);

    convo_t *convo = convo_new();
    cr_assert_eq(convo_init(convo), SUCCESS, "convo was not initialized properly");

    cr_assert_eq(add_node(convo, "1",
                          "NPC: How do I look today?", NEUTRAL), SUCCESS,
                          "node was not added properly");

    cr_assert_eq(add_node(convo, "1B",
                          "Thank you!", POSITIVE), SUCCESS,
                          "node was not added properly");

    cr_assert_eq(add_edge(convo, "Player: Your hair looks nice today", "1",
                          "1B", NULL, POSITIVE), SUCCESS, 
                          "edge was not added properly");

    cr_assert_eq(change_npc_hostility(npc, convo->all_edges->edge), SUCCESS, 
                 "NPC hostility was not changed to friendly");
}
