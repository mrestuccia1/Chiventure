#include <criterion/criterion.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "skilltrees/skilltree.h"
#include "skilltrees/skill.h"
#include "skilltrees/skilltrees_common.h"
#include "skilltrees/inventory.h"
#include "skilltrees/effect.h"
#include "test_init.h"

// TO DO : Five tests on lines 15, 18, 21, 101, 104, check test line 108 for passability 

/* Test reader_effect_new */
Test(reader_test, reader_effect_new_test)

/* Test reader_effect_init */
Test(reader_test, reader_effect_init_test)

/* Test reader_effect_free */
Test(reader_test, reader_effect_free_test)

/* Test stat_reader_effect_new */
Test(reader_test, stat_reader_effect_new_test){
    stat_reader_effect_t *sr = stat_reader_effect_new(50, SPEED, GREATER, READ_PLAYER);

    cr_assert_eq(sr->value,50,
        "Error: failed test stat_reader_effect_new_test on sr->value\n");
    cr_assert_eq(sr->stat_type,SPEED,
        "Error: failed test stat_reader_effect_new_test on sr->stat_type\n");
    cr_assert_eq(sr->comparison,GREATER,
        "Error: failed test stat_reader_effect_new_test on sr->comparison\n");
    cr_assert_eq(sr->location,READ_PLAYER,
        "Error: failed test stat_reader_effect_new_test on sr->location\n");
}

/* Test stat_reader_effect_init */
Test(reader_test, stat_reader_effect_init_test){
    stat_reader_effect_t* sr = (stat_reader_effect_t*)malloc(sizeof(stat_reader_effect_t));
    int rc = stat_reader_effect_init(sr, 50, SPEED, GREATER, READ_PLAYER)

    cr_assert_eq(rc,1,
        "Error: failed test stat_reader_effect_init_test, initialization failed\n");
    cr_assert_eq(sr->value,50,
        "Error: failed test stat_reader_effect_init_test on sr->value\n");
    cr_assert_eq(sr->stat_type,SPEED,
        "Error: failed test stat_reader_effect_init_test on sr->stat_type\n");
    cr_assert_eq(sr->comparison,GREATER,
        "Error: failed test stat_reader_effect_init_test on sr->comparison\n");
    cr_assert_eq(sr->location,READ_PLAYER,
        "Error: failed test stat_reader_effect_init_test on sr->location\n");
}

/* Test stat_reader_effect_free */
Test(reader_test, stat_reader_effect_free_test){
    stat_reader_effect_t *sr = stat_reader_effect_new(50, SPEED, GREATER, READ_PLAYER);

    int rc = stat_reader_effect_free(sr);

    cr_assert_eq(rc, 1, "Error: failed test stat_reader_effect_free_test\n");
}

/* Test attr_reader_effect_new */
Test(reader_test, attr_reader_effect_new_test){
    attr_reader_effect_t *ar = attr_reader_effect_new("undead", 6, READ_PLAYER);

    cr_assert_eq(sr->value,"undead",
        "Error: failed test attr_reader_effect_new_test on ar->value\n");
    cr_assert_eq(sr->str_len,6,
        "Error: failed test attr_reader_effect_new_test on ar->str_len\n");
    cr_assert_eq(sr->location,READ_PLAYER,
        "Error: failed test attr_reader_effect_new_test on ar->location\n");
}

/* Test attr_reader_effect_init */
Test(reader_test, attr_reader_effect_init_test){
    attr_reader_effect_t *ar = (attr_reader_effect_t*)malloc(sizeof(attr_reader_effect_t));
    int rc = attr_reader_effect_new("undead", 6, READ_PLAYER);
    
    cr_assert_eq(rc,1,
        "Error: failed test attr_reader_effect_init_test, initialization failed\n");
    cr_assert_eq(sr->value,"undead",
        "Error: failed test attr_reader_effect_init_test on ar->value\n");
    cr_assert_eq(sr->str_len,6,
        "Error: failed test attr_reader_effect_init_test on ar->str_len\n");
    cr_assert_eq(sr->location,READ_PLAYER,
        "Error: failed test attr_reader_effect_init_test on ar->location\n");
}

/* Test attr_reader_effect_free */
Test(reader_test, attr_reader_effect_free_test){
    attr_reader_effect_t *ar = attr_reader_effect_new("undead", 6, READ_PLAYER);

    int rc = attr_reader_effect_free(ar);

    cr_assert_eq(rc, 1, "Error: failed test stat_reader_effect_free_test\n");
}


/* Test execute_reader_effect for true */
Test(reader_test, execute_reader_effect_test_true)

/* Test execute_reader_effect for false */
Test(reader_test, execute_reader_effect_test_false)

// Not sure this will work because of the case coverage in reader.c -- come back to this!
/* Test execute_attr_reader_effect for true*/
Test(reader_test, execute_attr_reader_effect_test_true){
    chiventure_ctx_t* ctx = create_player_and_stats();
    attr_reader_effect_t *ar = attr_reader_effect_new("undead", 6, READ_PLAYER);
    int rc = execute_reader_effect(reader, ctx);
    cr_assert_eq(rc, 1, "Error: failed test execute_attr_reader_effect_test for true\n");
}

/* Test execute_attr_reader_effect for false*/
Test(reader_test, execute_attr_reader_effect_test_false){
    chiventure_ctx_t* ctx = create_player_and_stats();
    attr_reader_effect_t *ar = attr_reader_effect_new("undead", 6, READ_PLAYER);
    int rc = execute_reader_effect(reader, ctx);
    cr_assert_eq(rc, 0, "Error: failed test execute_attr_reader_effect_test for false\n");
}

/* Test execute_stat_reader_effect for true*/
Test(reader_test, execute_stat_reader_effect_test_false){
    chiventure_ctx_t* ctx = create_player_and_stats();
    stat_reader_effect_t *sr = stat_reader_effect_new(50, HP, EQUALS, READ_PLAYER);
    int rc = execute_stat_reader_effect(sr, ctx);
    cr_assert_eq(rc, 1, "Error: failed test execute_stat_reader_effect_test for true\n");
}

/* Test execute_stat_reader_effect for false*/
Test(reader_test, execute_stat_reader_effect_test_false){
    chiventure_ctx_t* ctx = create_player_and_stats();
    stat_reader_effect_t *sr = stat_reader_effect_new(50, HP, NOT, READ_PLAYER);
    int rc = execute_stat_reader_effect(sr, ctx);
    cr_assert_eq(rc, 0, "Error: failed test execute_stat_reader_effect_test for false\n");
}
