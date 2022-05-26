#include <stdlib.h>
#include <stdio.h>
#include <criterion/criterion.h>
#include <stdbool.h>
#include <string.h>
#include "../../include/battle/battle_test_utility.h"

/* Tests print_start_battle() */
Test(battle_print, print_start_battle)
{
    // Setting up a battle with set_battle
    stat_t *player_stats = calloc(1,sizeof(stat_t));
    stat_t *enemy_stats = calloc(1,sizeof(stat_t));
    battle_player_t *ctx_player = new_ctx_player("player_name", NULL, player_stats, NULL, NULL
                                                , NULL, NULL, NULL);
    move_t *move = move_new(0, "TEST", "TEST INFO", PHYS, NO_TARGET, NO_TARGET, 
                            SINGLE, 0, NULL, 80, 100, NULL, NULL, NULL, NULL);
    npc_t *npc_enemy = npc_new("Bob", "Enemy!", "Enemy!", NULL, NULL, HOSTILE);
    class_t* test_class = class_new("Bard", "Music boi",
                                    "Charismatic, always has a joke or song ready",
                                    NULL, NULL, NULL);
    stat_changes_t *dagger_changes = stat_changes_new();
    dagger_changes->phys_atk = 20;
    dagger_changes->phys_def = 5;

    dagger_changes->hp = 0;                        
    battle_item_t *dagger = create_battle_item(1, 20, "A hearty dagger sure to take your breath away... for good", "Dagger",
                                true, dagger_changes);
    npc_battle_t *npc_b = npc_battle_new(enemy_stats, move,
            BATTLE_AI_GREEDY, HOSTILE, test_class, dagger, NULL, NULL, NULL);

    npc_enemy->npc_battle = npc_b;
    environment_t env = ENV_DESERT;
    battle_t *b = set_battle(ctx_player, npc_enemy, env);
    cr_assert_not_null(b, "set_battle() failed");
    b->player->stats->hp = 100;
    b->enemy->stats->hp = 100;
    char* string = print_start_battle(b);
    cr_assert_not_null(string, "print_start_battle() failed");

    char *expected_string = "You have encountered bob!\n\n"
                            "Let the battle begin!\n";
    cr_expect_str_eq(string, expected_string, 
                    "print_start_battle() failed to set string %s", string);

    free(string);
}

/* Tests print_hp() for battle against one enemy */
Test(battle_print, print_hp_one_enemy)
{
    /* Setting up a battle with set_battle */
    stat_t *player_stats = calloc(1,sizeof(stat_t));
    stat_t *enemy_stats = calloc(1,sizeof(stat_t));
    battle_player_t *ctx_player = new_ctx_player("player_name", NULL, player_stats, NULL, NULL,
                                                NULL, NULL, NULL);
    move_t *move = move_new(0, "TEST", "TEST INFO", PHYS, NO_TARGET, NO_TARGET, 
                            SINGLE, 0, NULL, 80, 100, NULL, NULL, NULL, NULL);
    npc_t *npc_enemy = npc_new("Bob", "Enemy!", "Enemy!", NULL, NULL, HOSTILE);
    class_t* test_class = class_new("Bard", "Music boi",
                                    "Charismatic, always has a joke or song ready",
                                    NULL, NULL, NULL);
    stat_changes_t *dagger_changes = stat_changes_new();
    dagger_changes->phys_atk = 20;
    dagger_changes->phys_def = 5;

    dagger_changes->hp = 0;                        
    battle_item_t *dagger = create_battle_item(1, 20, "A hearty dagger sure to take your breath away... for good", "Dagger",
                                true, dagger_changes);
    npc_battle_t *npc_b = npc_battle_new(enemy_stats, move,
            BATTLE_AI_GREEDY, HOSTILE, test_class, dagger, NULL, NULL, NULL);

    npc_enemy->npc_battle = npc_b;
    environment_t env = ENV_DESERT;
    battle_t *b = set_battle(ctx_player, npc_enemy, env);
    cr_assert_not_null(b, "set_battle() failed");
    b->player->stats->hp = 89;
    b->enemy->stats->hp = 64;

    /* Set up string to store message in */
    char* string = calloc(BATTLE_BUFFER_SIZE + 1, sizeof(char));

    /* Test print_hp() */
    int rc = print_hp(b, string);
    cr_assert_eq(rc, SUCCESS, "print_hp() failed");

    char *expected_string = "-- Your HP: 89\n"
                            "-- bob's HP: 64\n";

    cr_expect_str_eq(string, expected_string, 
                    "print_hp() failed to set string %s", string);

    free(string);
}

/* Tests print_battle_move() on a player move for crit */
Test(battle_print, print_player_move_crit)
{
    // Setting up a battle with set_battle
    stat_t *player_stats = calloc(1,sizeof(stat_t));
    player_stats->hp = 50;
    player_stats->phys_atk = 20;
    player_stats->phys_def = 12;
    player_stats->crit = 100;
    player_stats->accuracy = 100;
    player_stats->xp = 100;
    player_stats->level = 5;
    player_stats->speed = 10;
    stat_t *enemy_stats = calloc(1,sizeof(stat_t));
    enemy_stats->hp = 30;
    enemy_stats->phys_atk = 14;
    enemy_stats->phys_def = 9;
    enemy_stats->crit = 100;
    enemy_stats->accuracy = 100;
    enemy_stats->xp = 100;
    enemy_stats->level = 5;
    enemy_stats->speed = 9;

    battle_player_t *ctx_player = new_ctx_player("player_name", NULL, player_stats, NULL, NULL,
                                                NULL, NULL, NULL);
    move_t *e_move = move_new(0, "TEST", "TEST INFO", PHYS, NO_TARGET, NO_TARGET, 
                              SINGLE, 0, NULL, 80, 100, NULL, NULL, NULL, NULL);
    npc_t *npc_enemy = npc_new("Bob", "Enemy!", "Enemy!", NULL, NULL, HOSTILE);
    class_t* test_class = class_new("Bard", "Music boi",
                                    "Charismatic, always has a joke or song ready",
                                    NULL, NULL, NULL);
    stat_changes_t *dagger_changes = stat_changes_new();
    dagger_changes->phys_atk = 20;
    dagger_changes->phys_def = 5;

    dagger_changes->hp = 0;                        
    battle_item_t *dagger = create_battle_item(1, 20, "A hearty dagger sure to take your breath away... for good", "Dagger",
                                true, dagger_changes);
    npc_battle_t *npc_b = npc_battle_new(enemy_stats, e_move,
                     BATTLE_AI_GREEDY, HOSTILE, test_class, dagger, NULL, NULL, NULL);

    npc_enemy->npc_battle = npc_b;
    environment_t env = ENV_DESERT;
    battle_t *b = set_battle(ctx_player, npc_enemy, env);
    cr_assert_not_null(b, "set_battle() failed");
    // Set up a move
    move_t *move = calloc(1,sizeof(move_t));
    move->damage = 60;
    move->dmg_type = PHYS;
    move->stat_mods = NO_TARGET;
    move->effects = NO_TARGET;
    move->accuracy = 100;
    move->name = "Punch";
    b->player->moves = move;
    b->enemy->stats->hp = 16;

    char* string = print_battle_move(b, PLAYER, move);
    cr_assert_not_null(string, "print_start_battle() failed");
    
    char *expected_string = "You used Punch! ";

    cr_expect_str_eq(string, expected_string, 
                     "print_player_move_crit() failed to set string %s\n. We got %s", 
                     string, expected_string);

    free(string);
}

/* Tests print_battle_move_miss() on a player move for crit */

Test(battle_print, print_player_move_miss)
{
    // Setting up a battle with set_battle
    stat_t *player_stats = calloc(1,sizeof(stat_t));
    player_stats->hp = 50;
    player_stats->phys_atk = 20;
    player_stats->phys_def = 12;
    player_stats->crit = 0;
    player_stats->accuracy = 0;
    player_stats->xp = 100;
    player_stats->level = 5;
    player_stats->speed = 10;
    stat_t *enemy_stats = calloc(1,sizeof(stat_t));
    enemy_stats->hp = 30;
    enemy_stats->phys_atk = 14;
    enemy_stats->phys_def = 9;
    enemy_stats->crit = 0;
    enemy_stats->accuracy = 0;
    enemy_stats->xp = 100;
    enemy_stats->level = 5;
    enemy_stats->speed = 9;

    battle_player_t *ctx_player = new_ctx_player("player_name", NULL, player_stats, NULL, NULL,
                                                NULL, NULL, NULL);
    move_t *e_move = move_new(0, "TEST", "TEST INFO", PHYS, NO_TARGET, NO_TARGET, 
                              SINGLE, 0, NULL, 80, 100, NULL, NULL, NULL, NULL);
    npc_t *npc_enemy = npc_new("Bob", "Enemy!", "Enemy!", NULL, NULL, HOSTILE);
    class_t* test_class = class_new("Bard", "Music boi",
                                    "Charismatic, always has a joke or song ready",
                                    NULL, NULL, NULL);
    stat_changes_t *dagger_changes = stat_changes_new();
    dagger_changes->phys_atk = 20;
    dagger_changes->phys_def = 5;

    dagger_changes->hp = 0;                        
    battle_item_t *dagger = create_battle_item(1, 20, "A hearty dagger sure to take your breath away... for good", "Dagger",
                                true, dagger_changes);
    npc_battle_t *npc_b = npc_battle_new(enemy_stats, e_move,
                     BATTLE_AI_GREEDY, HOSTILE, test_class, dagger, NULL, NULL, NULL);

    npc_enemy->npc_battle = npc_b;
    environment_t env = ENV_DESERT;
    battle_t *b = set_battle(ctx_player, npc_enemy, env);
    cr_assert_not_null(b, "set_battle() failed");
    // Set up a move
    move_t *move = calloc(1,sizeof(move_t));
    move->damage = 60;
    move->dmg_type = PHYS;
    move->stat_mods = NO_TARGET;
    move->effects = NO_TARGET;
    move->accuracy = 100;
    move->name = "Punch";
    b->player->moves = move;
    b->enemy->stats->hp = 30;

    char* string = print_battle_miss(b, PLAYER, move);
    cr_assert_not_null(string, "print_start_battle() failed");
    
    char *expected_string = "You used Punch, but it missed!\n"
                            "-- Your HP: 50\n"
                            "-- bob's HP: 30\n";

    cr_expect_str_eq(string, expected_string, "print_player_move_miss() failed to set string %s", string);

    free(string);
}

/* Tests to make sure print battle damage is correct */
Test(battle_print, print_battle_damage)
{
    // Setting up a battle with set_battle
    stat_t *player_stats = calloc(1,sizeof(stat_t));
    player_stats->hp = 50;
    player_stats->phys_atk = 20;
    player_stats->phys_def = 12;
    player_stats->crit = 0;
    player_stats->accuracy = 100;
    player_stats->xp = 100;
    player_stats->level = 5;
    player_stats->speed = 10;
    stat_t *enemy_stats = calloc(1,sizeof(stat_t));
    enemy_stats->hp = 30;
    enemy_stats->phys_atk = 14;
    enemy_stats->phys_def = 9;
    enemy_stats->crit = 0;
    enemy_stats->accuracy = 0;
    enemy_stats->xp = 100;
    enemy_stats->level = 5;
    enemy_stats->speed = 9;

    battle_player_t *ctx_player = new_ctx_player("player_name", NULL, player_stats, NULL, NULL,
                                                NULL, NULL, NULL);
    move_t *e_move = move_new(0, "TEST", "TEST INFO", PHYS, NO_TARGET, NO_TARGET, 
                              SINGLE, 0, NULL, 80, 100, NULL, NULL, NULL, NULL);
    npc_t *npc_enemy = npc_new("Bob", "Enemy!", "Enemy!", NULL, NULL, HOSTILE);
    class_t* test_class = class_new("Bard", "Music boi",
                                    "Charismatic, always has a joke or song ready",
                                    NULL, NULL, NULL);
    stat_changes_t *dagger_changes = stat_changes_new();
    dagger_changes->phys_atk = 20;
    dagger_changes->phys_def = 5;

    dagger_changes->hp = 0;                        
    battle_item_t *dagger = create_battle_item(1, 20, "A hearty dagger sure to take your breath away... for good", "Dagger",
                                true, dagger_changes);
    npc_battle_t *npc_b = npc_battle_new(enemy_stats, e_move,
                     BATTLE_AI_GREEDY, HOSTILE, test_class, dagger, NULL, NULL, NULL);

    npc_enemy->npc_battle = npc_b;
    environment_t env = ENV_DESERT;
    battle_t *b = set_battle(ctx_player, npc_enemy, env);
    cr_assert_not_null(b, "set_battle() failed");
    // Set up a move
    move_t *move = calloc(1,sizeof(move_t));
    move->damage = 60;
    move->dmg_type = PHYS;
    move->stat_mods = NO_TARGET;
    move->effects = NO_TARGET;
    move->accuracy = 100;
    move->name = "Punch";
    b->player->moves = move;

    char *string = calloc(BATTLE_BUFFER_SIZE + 1, sizeof(char));
    print_battle_damage(b, PLAYER, move, 1, string);
    cr_assert_not_null(string, "print_start_battle() failed");
    
    char *expected_string = "It did 9 damage.\n";

    
    cr_expect_str_eq(string, expected_string, "print_battle_damage() failed to set string %s", string);

    char *string_crit = calloc(BATTLE_BUFFER_SIZE + 1, sizeof(char));
    print_battle_damage(b, PLAYER, move, 1.5, string_crit);
    char *expected_string_crit = "It did 14 damage.\n";
    cr_expect_str_eq(string_crit, expected_string_crit, "print_battle_damage() failed to set string %s", string);

    free(string);
}

Test(battle_print, print_stat_changes)
{
    stat_t *player_stats = calloc(1,sizeof(stat_t));
    player_stats->hp = 50;
    player_stats->phys_atk = 20;
    player_stats->phys_def = 12;
    player_stats->crit = 0;
    player_stats->accuracy = 100;
    player_stats->xp = 100;
    player_stats->level = 5;
    player_stats->speed = 10;

    stat_t *enemy_stats = calloc(1,sizeof(stat_t));
    enemy_stats->hp = 30;
    enemy_stats->phys_atk = 14;
    enemy_stats->phys_def = 9;
    enemy_stats->crit = 0;
    enemy_stats->accuracy = 0;
    enemy_stats->xp = 100;
    enemy_stats->level = 5;
    enemy_stats->speed = 9;

    battle_player_t *ctx_player = new_ctx_player("player_name", NULL, player_stats, NULL, NULL,
                                                NULL, NULL, NULL);
    move_t *e_move = move_new(0, "TEST", "TEST INFO", PHYS, NO_TARGET, NO_TARGET, 
                              SINGLE, 0, NULL, 80, 100, NULL, NULL, NULL, NULL);
    npc_t *npc_enemy = npc_new("Bob", "Enemy!", "Enemy!", NULL, NULL, HOSTILE);
    class_t* test_class = class_new("Bard", "Music boi",
                                    "Charismatic, always has a joke or song ready",
                                    NULL, NULL, NULL);
    stat_changes_t *dagger_changes = stat_changes_new();
    dagger_changes->phys_atk = 20;
    dagger_changes->phys_def = 5;

    dagger_changes->hp = 0;                        
    battle_item_t *dagger = create_battle_item(1, 20, "A hearty dagger sure to take your breath away... for good", "Dagger",
                                true, dagger_changes);
    npc_battle_t *npc_b = npc_battle_new(enemy_stats, e_move,
                     BATTLE_AI_GREEDY, HOSTILE, test_class, dagger, NULL, NULL, NULL);

    npc_enemy->npc_battle = npc_b;

    environment_t env = ENV_DESERT;
    battle_t *b = set_battle(ctx_player, npc_enemy, env);
    stat_changes_t *user_stat_changes = stat_changes_new();
    user_stat_changes->phys_atk = 10;
    char *string = calloc(BATTLE_BUFFER_SIZE + 1, sizeof(char));
    print_stat_changes(b, PLAYER, user_stat_changes, string);
    char *expected_string = "Your physical attack changed by 10\n";

    cr_expect_str_eq(string, expected_string, "print_stat_changes() failed to set string %s", string);
    free(string);

}

Test(battle_print, print_stat_changes_enemy)
{
    stat_t *player_stats = calloc(1,sizeof(stat_t));
    player_stats->hp = 50;
    player_stats->phys_atk = 20;
    player_stats->phys_def = 12;
    player_stats->crit = 0;
    player_stats->accuracy = 100;
    player_stats->xp = 100;
    player_stats->level = 5;
    player_stats->speed = 10;

    stat_t *enemy_stats = calloc(1,sizeof(stat_t));
    enemy_stats->hp = 30;
    enemy_stats->phys_atk = 14;
    enemy_stats->phys_def = 9;
    enemy_stats->crit = 0;
    enemy_stats->accuracy = 0;
    enemy_stats->xp = 100;
    enemy_stats->level = 5;
    enemy_stats->speed = 9;

    battle_player_t *ctx_player = new_ctx_player("player_name", NULL, player_stats, NULL, NULL,
                                                NULL, NULL, NULL);
    move_t *e_move = move_new(0, "TEST", "TEST INFO", PHYS, NO_TARGET, NO_TARGET, 
                              SINGLE, 0, NULL, 80, 100, NULL, NULL, NULL, NULL);
    npc_t *npc_enemy = npc_new("Bob", "Enemy!", "Enemy!", NULL, NULL, HOSTILE);
    class_t* test_class = class_new("Bard", "Music boi",
                                    "Charismatic, always has a joke or song ready",
                                    NULL, NULL, NULL);
    stat_changes_t *dagger_changes = stat_changes_new();
    dagger_changes->phys_atk = 20;
    dagger_changes->phys_def = 5;

    dagger_changes->hp = 0;                        
    battle_item_t *dagger = create_battle_item(1, 20, "A hearty dagger sure to take your breath away... for good", "Dagger",
                                true, dagger_changes);
    npc_battle_t *npc_b = npc_battle_new(enemy_stats, e_move,
                     BATTLE_AI_GREEDY, HOSTILE, test_class, dagger, NULL, NULL, NULL);

    npc_enemy->npc_battle = npc_b;

    environment_t env = ENV_DESERT;
    battle_t *b = set_battle(ctx_player, npc_enemy, env);
    stat_changes_t *enemy_stat_changes = stat_changes_new();
    enemy_stat_changes->phys_atk = 10;
    char *string = calloc(BATTLE_BUFFER_SIZE + 1, sizeof(char));
    print_stat_changes(b, PLAYER, enemy_stat_changes, string);
    char *expected_string = "Bob's physical attack changed by 10\n";

    cr_expect_str_eq(string, expected_string, "print_stat_changes() failed to set string %s", string);
    free(string);

}
/* Tests print_battle_winner() when player wins */
Test(battle_print, print_player_winner)
{
    battle_status_t status = BATTLE_VICTOR_PLAYER;
    int xp = 2;

    char* string = print_battle_winner(status, xp);
    cr_assert_not_null(string, "print_start_battle() failed");

    char *expected_string = "You've won! You gain 2 XP!\n";
    cr_expect_str_eq(string, expected_string, 
                    "print_player_winner() failed to set string");

    free(string);
}

/* Tests print_battle_winner() when enemy wins */
Test(battle_print, print_enemy_winner)
{
    battle_status_t status = BATTLE_VICTOR_ENEMY;
    int xp = 2;

    char* string = print_battle_winner(status, xp);
    cr_assert_not_null(string, "print_start_battle() failed");

    char *expected_string = "You have been defeated!\n";
    cr_expect_str_eq(string, expected_string, 
                    "print_enemy_winner() failed to set string");

    free(string);
}

/* Tests print_battle_winner() when enemy surrenders */
Test(battle_print, print_enemy_surrender)
{
    battle_status_t status = BATTLE_ENEMY_SURRENDER;
    int xp = 2;

    char* string = print_battle_winner(status, xp);
    cr_assert_not_null(string, "print_start_battle() failed");

    char* expected_string = "Your opponent has surrendered!\n";
    cr_expect_str_eq(string, expected_string, 
		    "print_enemy_surrender() failed to set string");
}
