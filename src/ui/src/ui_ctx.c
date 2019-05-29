#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>
#include <ctype.h>
#include <stdbool.h>
#include <signal.h>
#include <assert.h>
#include "ui_ctx.h"
#include "game.h"
#include "coordinate.h"
#include "window.h"
#include "print_functions.h"
#include "map.h"

// see ui_ctx.h
ui_ctx_t *ui_ctx_new(game_t *game)
{
    assert(game != NULL);
    int init;
    ui_ctx_t *ui_ctx = (ui_ctx_t *) malloc(sizeof(ui_ctx_t));

    init = ui_ctx_init(ui_ctx, game);

    if (init == FAILURE) {
        return NULL;
    }

    return ui_ctx;
}

// see ui_ctx.h
int ui_ctx_init(ui_ctx_t *ui_ctx, game_t *game)
{
    assert(ui_ctx != NULL);
    assert(game != NULL);

    int height = LINES / 2;
    int width = COLS;

    window_t *map_win = window_new(height, width, 0, 0, print_map, true);
    window_t *main_win = window_new(height, width, 0, 0, print_info, true);
    window_t *displayed_win = main_win;

    window_t *cli_win = window_new(height, width, height, 0, print_cli, false);

    ui_ctx->map_win = map_win;
    ui_ctx->main_win = main_win;
    ui_ctx->displayed_win = displayed_win;
    ui_ctx->cli_win = cli_win;

    /* TO-DO: create_valid_map will take arguments:
     * either:
     * 1. a pointer to a game struct
     * 2. a pointer to the game ctx
     * 3. perhaps just the ui_ctx->player_loc
     *    field--this may be all the function needs
     */
    ui_ctx->coord_hash = create_valid_map(game);
    fprintf(stderr,"Completed creation of valid map\n");

    // Initial room coordinates set to 0, 0
    coord_t *initial_coord = coord_new(0, 0);

    ui_ctx->player_loc = initial_coord;

    /* Valid maps cannot be created for illogical map directions or for maps
    * with logical distances of more than unit one
    */
    if (ui_ctx->coord_hash == NULL) {
        return FAILURE;
    }

    ui_ctx->map = map_init();

    return SUCCESS;
}

// see ui_ctx.h
int ui_ctx_free(ui_ctx_t *ui_ctx)
{
    assert(ui_ctx != NULL);

    window_free(ui_ctx->map_win);
    window_free(ui_ctx->main_win);
    window_free(ui_ctx->cli_win);
    free(ui_ctx->player_loc);

    coord_record_t *coord_hash, *item, *temp;
    coord_hash = ui_ctx->coord_hash;
    HASH_ITER(hh, coord_hash, item, temp) {
        HASH_DEL(coord_hash, item);
        free(item);
    }

    free(ui_ctx);

    return 0;
}
