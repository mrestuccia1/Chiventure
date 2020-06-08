#include <criterion/criterion.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "game-state/stats.h"

/* Checks that add_stat_player correctly adds a new stat 
   to a hash table*/
Test (stats, add_stat_player)
{
    stats_hash_t *sh = NULL;
    stats_global_t g;
    g.name = "health";
    g.max = 100;

    stats_t s;
    s.key = "health";
    s.global = &g;
    s.val = 50;
    s.max = 75;
    s.modifier = 1.1;

    int rc = add_stat_player(&sh, &s);

    cr_assert_eq(rc, SUCCESS, "add_stat_player failed");

    cr_assert_not_null(sh, "add_stat_player did not add the stat");
}

/* Checks that display_stat returns the correct list of stats */
Test(stats, display_stat)
{
    stats_hash_t *sh = NULL;

    stats_global_t health;
    health.name = "health";
    health.max = 100;

    stats_t s1;
    s1.key = "health";
    s1.global = &health;
    s1.val = 50;
    s1.max = 75;
    s1.modifier = 1.1;

    int rc = add_stat_player(&sh, &s1);

    cr_assert_eq(rc, SUCCESS, "add_stat_player failed");


    stats_global_t speed;
    speed.name = "speed";
    speed.max = 100;

    stats_t s2;
    s2.key = "speed";
    s2.global = &speed;
    s2.val = 25;
    s2.max = 50;
    s2.modifier = 0.9;

    rc = add_stat_player(&sh, &s2);

    cr_assert_eq(rc, SUCCESS, "add_stat_player failed");

    char *list = display_stats(sh);

    cr_assert_str_eq(list, "health, speed",
                     "expected: health, speed, but display_stat returned %s",
                     list);

    free(list);
}

/* Checks that global_effect_init correctly initializes a global effect struct */
Test (stats, effect_global_init)
{
    effects_global_t effect;

    int rc = global_effect_init(&effect, "health");

    cr_assert_eq(rc, SUCCESS, "global_effect_init failed");
    cr_assert_not_null(effect.name, "global_effect_init did not set effect name");
    cr_assert_str_eq(effect.name, "health", "global_effect_init did not set name");
}

/* Checks that global_effect_new correctly creates a new global effect struct */
Test (stats, effect_global_new)
{
    effects_global_t *effect = global_effect_new("health");

    cr_assert_not_null(effect, "global_effect_new failed");
    cr_assert_str_eq(effect->name, "health", "global_effect_new did not set name");
}

/* Checks that effect_init correctly initializes an effect struct */
Test (stats, stat_effect_init)
{
    effects_global_t *global = global_effect_new("speed");
    cr_assert_not_null(global, "global_effect_new failed");

    stat_effect_t effect;

    int rc = stat_effect_init(&effect, global);

    cr_assert_eq(rc, SUCCESS, "stat_effect_init failed");
    cr_assert_str_eq(effect.key, global->name, "stat_effect_init did not set key");
    cr_assert_eq(effect.global, global, "stat_effect_init did not set global pointer");
}

/* Checks that stat_effect_new correctly creates a new player effect */
Test (stats, stat_effect_new)
{
    effects_global_t *global = global_effect_new("health");
    cr_assert_not_null(global, "global_effect_new failed");

    stat_effect_t *effect = stat_effect_new(global);

    cr_assert_not_null(effect, "stat_effect_new failed");
    cr_assert_str_eq(effect->key, global->name, "stat_effect_new did not set key");
    cr_assert_eq(effect->global, global, "stat_effect_new did not set global pointer");
}


stats_hash_t *add_stats(int type) {

   stats_hash_t *sh = NULL;

   stats_global_t g1;
   g1.name = "health";
   g1.max = 100;

   stats_global_t g2;
   g2.name = "charisma";
   g2.max = 200;

   stats_global_t g3;
   g3.name = "charisma";
   g3.max = 200;

   stats_t s1;
   s1.key = "health";
   s1.global = &g1;
   s1.val = 50;
   s1.max = 75;
   s1.modifier = 1.1;

   stats_t s2;
   s2.key = "charisma";
   s2.global = &g2;
   s2.val = 75;
   s2.max = 130;
   s2.modifier = 1;

   stats_t s3;
   s3.key = "strength";
   s3.global = &g3;
   s3.val = 20;
   s3.max = 92;
   s3.modifier = 2;

   int rc1, rc2, rc3;

   if (type == 1) {
        rc1 = add_stat_player(&sh, &s1);
    } else if  (type == 2) {
        rc1 = add_stat_player(&sh, &s1);
        rc2 = add_stat_player(&sh, &s2);
    } else if  (type == 3) {
        rc1 = add_stat_player(&sh, &s1);
        rc2 = add_stat_player(&sh, &s2);
        rc3 = add_stat_player(&sh, &s3);
    }

   return sh;
}



Test(stats, change_stat) {
    stats_hash_t *sh = NULL;
    stats_global_t g1;
    g1.name = "health";
    g1.max = 100;
    stats_t s1;
    s1.key = "health";
    s1.global = &g1;
    s1.val = 50;
    s1.max = 75;
    s1.modifier = 1.1;

    stats_global_t g2;
    g2.name = "charisma";
    g2.max = 200;
    stats_t s2;
    s2.key = "charisma";
    s2.global = &g2;
    s2.val = 75;
    s2.max = 130;
    s2.modifier = 1;

    int rc1 = add_stat_player(&sh, &s1);
    cr_assert_eq(rc1, SUCCESS, "add_stat_player_failed");
    int rc2 = add_stat_player(&sh, &s2);
    stats_t* curr; 
    HASH_FIND(hh, sh, "health", strlen("health"), curr);
    cr_assert_eq(curr->val, 50,
        "change_stat base value not equal initially");


    change_stat(sh, "health", 10);
    cr_assert_eq(curr->val, 60,
       "change_stat failed to return success");
    change_stat(sh, "health", 20);
    cr_assert_eq(curr->val, 75,
        "change_stat local max failed");
    rc1 = change_stat(sh, "health", 30);
    cr_assert_eq(rc1, FAILURE, 
        "change_stat global max failed");
    

    HASH_FIND(hh, sh, "charisma", strlen("charisma"), curr);
    cr_assert_eq(curr->val, 75,
        "change_stat base value not equal initially");


    change_stat(sh, "charisma", 10);
    cr_assert_eq(curr->val, 85,
       "change_stat failed to return success");
    change_stat(sh, "charisma", 60);
    cr_assert_eq(curr->val, 130,
        "change_stat local max failed");
    rc2 = change_stat(sh, "charisma", 80);
    cr_assert_eq(rc2, FAILURE, 
        "change_stat global max failed");
}

Test(stats, get_stat_current){
    stats_hash_t *sh = NULL;
    stats_global_t g1;
    g1.name = "health";
    g1.max = 100;
    stats_t s1;
    s1.key = "health";
    s1.global = &g1;
    s1.val = 50;
    s1.max = 75;
    s1.modifier = 1.1;
    int rc1 = add_stat_player(&sh, &s1);
    cr_assert_eq(rc1, SUCCESS, "add_stat_player_failed");
    int s1_value = get_stat_current(sh, s1.key);
    cr_assert_eq(s1_value, 55, "get_stat_current failed");

    s1.val = 99;
    s1_value = get_stat_current(sh, s1.key);
    cr_assert_eq(s1_value, 100, "get_stat_current global max failed");
    
}

/*Test(stats, get_stat_max) {}


Test(stats, get_stat_mod) {}*/
