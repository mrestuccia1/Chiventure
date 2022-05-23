#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>

#include "cli/operations.h"
#include "npc/npc.h"
#include "npc/dialogue.h"
#include "ui/print_functions.h"
#include "cli/shell.h"
#include "wdl/load_game.h"
#include "libobj/load.h"
#include "cli/cmdlist.h"
#include "cli/util.h"
#include <ctype.h>

#define NUM_ACTIONS 29
#define BUFFER_SIZE (100)
#define min(x,y) (((x) <= (y)) ? (x) : (y))

char* actions_for_sug[NUM_ACTIONS] = {"OPEN", "CLOSE", "PUSH", "PULL", "TURNON", "TURNOFF", 
                        "TAKE", "PICKUP", "DROP","CONSUME","USE","DRINK",
                        "EAT", "GO", "WALK", "USE_ON", "PUT", "QUIT","HIST", "HELP",
                        "CREDITS", "LOOK", "INV", "MAP", "SWITCH", "LOAD_WDL", "NAME", 
                        "PALETTE", "ITEMS"};


/* 
 * This function returns a integer 
 * which is the number of matching letters 
 * between the user input and action
 * 
 */
int compare(char* word, char* action)
{

    int current = 0;
    for (int i = 0; i < min(strlen(word), strlen(action)); i++)
    {
        if (&action[i] != NULL && &word[i] != NULL) 
        {
            if (tolower(word[i]) == tolower(action[i]))
            {
                current++;
            }
        }

    }

    return current;
}

/* Calculates the minimum between three values, 
   helper to levenshtein function*/
int mini (int a, int b, int c) {
    if (a < b && a < c) {
        return a;
    }else if (b < a && b < c) {
        return b;
    }else{
        return c;
    }
}

/*Calculates the Levenshtein Distance, given two strings.
  The Levenshtein distance measures the amount of changes needed
  for the two words to be equal, so the lower the score,
  the more similar the words are. My source for this formula, also
  linked below is here:
  https://en.wikipedia.org/wiki/Levenshtein_distance
  Helper funtion to suggestions function.*/
int levenshtein(char *action_input, char* action) 
{
    int input_len = strlen(action_input);
    int action_len = strlen(action);
    char* tail_inp = action_input+1;
    char* tail_act = action+1;
    if (action_len == 0) {
        return input_len;
    }else if (input_len == 0) {
        return action_len;
    // NOTE: tolower converts all uppercase letters to lowercase letters,
    // and keeps lowercase letters the same.
    }else if (tolower(action_input[0]) == tolower(action[0])) {
        int both_tails = levenshtein(tail_inp, tail_act);
        return both_tails;
    }else{
        int tail_one = levenshtein(tail_inp, action);
        int tail_two = levenshtein(action_input, tail_act);
        int tail_both = levenshtein(tail_inp, tail_act);
        return 1 + mini(tail_one,tail_two,tail_both);
    }

}

/* 
 * This function returns a string which is a suggestion 
 * obtained from comparing the input command with a list
 * of actual commands. This is found by using the Levenshtein's Distance formula, 
 * a fuzzy search mechanism to evaluate word similarity. More details linked here:
 * https://en.wikipedia.org/wiki/Levenshtein_distance
 *
 * Parameters:
 *  - action_input: parsed input command (a string)
 *  - actions: the actions_for_sug array that is globally defined 
 *    here is what the suggestions function is called with currently
 *    but any array of words to suggest would do.
 *
 * Returns:
 *  - a string suggestion, which is a word from the actions array
 */
char* suggestions(char *action_input, char** actions)
{

    int min = levenshtein(action_input, actions[0]);
    int index = 0;
    // Loops over all possible commands, and finds closest word
    // to input, which it suggests
    for (int i = 1; i < NUM_ACTIONS; i++) 
    {
        int temp = levenshtein(action_input, actions[i]);
        if (temp < min) 
        {
            min = temp;
            index = i;
        }
    }
    return actions[index];

}



char *credits_operation(char *tokens[TOKEN_LIST_SIZE], chiventure_ctx_t *ctx)
{
    return "Class of CMSC 22000 Spring 2019\n   Class of CMSC 22000 Spring 2020\n   Class of CMSC 22000 Spring 2021";
}

char *quit_operation(char *tokens[TOKEN_LIST_SIZE], chiventure_ctx_t *ctx)
{
    return NULL;
}

char *help_operation(char *tokens[TOKEN_LIST_SIZE], chiventure_ctx_t *ctx)
{
    help_text(ctx);
    return NULL;
}

char *hist_operation(char *tokens[TOKEN_LIST_SIZE], chiventure_ctx_t *ctx)
{
    command_list_t *temp = new_command_list(NULL);

    print_to_cli(ctx, "Start of command history: \n");
    LL_FOREACH(ctx->cli_ctx->command_history, temp)
    {
        if (temp->command != NULL) 
        {
            print_to_cli(ctx, temp->command);
        }
    } 
    return "End of command history.\n";
}


bool validate_wdl_filename(char *filename)
{
    int len = strlen(filename);
    int min_filename_length = 4;
    int file_extension_length = 4;
    if (len < min_filename_length)
    {
        return false;
    }
    const char *ending = &filename[len - file_extension_length];
    int cmp = strcmp(ending, ".wdl");
    if (cmp == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}


char *load_wdl_operation(char *tokens[TOKEN_LIST_SIZE], chiventure_ctx_t *ctx)
{
    int valid_path;

    valid_path = access(tokens[1], F_OK);

    if (valid_path == -1) //Triggers if file does not exist
    {
        return "Loading WDL file failed: Invalid Input for file path\n";
    }
    if ((validate_wdl_filename(tokens[1])) == false) //Triggers if file is not wdl
    {
        return "Loading WDL file failed: Invalid Input, please only use wdl file types\n";
    }

    obj_t *obj_store = load_obj_store(tokens[1]);

    game_t *game = load_game(obj_store);

    if (game == NULL)
    {
        return "Load WDL failed!";
    }
    else
    {
        ctx->game = game;
        return "Load WDL succeeded!";
    }
}

/* See operation.h */
cmd *assign_action(char **ts, lookup_t ** table)
{
    cmd *output = cmd_new(ts);
    output->func_of_cmd = find_operation(ts[0], table);
    if(output->func_of_cmd == NULL)
    {
        output->func_of_cmd = action_error_operation;
    }
    return output;
}

char *look_operation(char *tokens[TOKEN_LIST_SIZE], chiventure_ctx_t *ctx)
{
    game_t *game = ctx->game;
    if(game == NULL || game->curr_room == NULL)
    {
        return "Room not found! Error! We need a room to be loaded to LOOK!\n";
    }
    if(tokens[1] == NULL)
    {
        if(game != NULL)
        {
            return game->curr_room->long_desc;
        }
        else
        {
            return "Error !";
        }
    }
    item_t *curr_item = NULL;
    curr_item = get_item_in_room(game->curr_room, tokens[1]);
    if(curr_item != NULL)
    {
        char *string = malloc(BUFFER_SIZE);
        sprintf(string, "%s", curr_item->long_desc);
        if (curr_item->next != NULL)
        {
            int count = 0;
            item_t *iter;
            LL_FOREACH(curr_item, iter)
            {
                count++;
            }
            char *count_str = malloc(BUFFER_SIZE);
            sprintf(count_str, " There are %d of these in this room.", count);
            string = strcat(string, count_str);
        }
        return string;
    }
    return "specified item not found\n";
}

//KIND 1:   ACTION <item>
char *kind1_action_operation(char *tokens[TOKEN_LIST_SIZE], chiventure_ctx_t *ctx)
{
    game_t *game = ctx->game;
    if(game == NULL || game->curr_room == NULL)
    {
        print_to_cli(ctx, tokens[0]);
        return ( "Error! We need a loaded room to do the above action. \n");
    }
    lookup_t **table = ctx->cli_ctx->table;

    if(tokens[1] == NULL)
    {
        return "You must identify an object to act on\n";
    }
    if(tokens[2] != NULL)
    {
        return "Sorry, act upon one item \n";
    }
    item_t *curr_item;
    curr_item = get_item_in_room(game->curr_room, tokens[1]);
    if(curr_item != NULL)
    {
        action_type_t *action = find_action(tokens[0], table);
        char *str;
        bool action_success = false;
        
        /* Loops through items with identical ids 
         * until action success or all items fail */
        while (!action_success && curr_item != NULL)
        {
            int rc = do_item_action(ctx, action, curr_item, &str);
            if (rc == SUCCESS)
            {
                action_success = true;
                if(strcmp(tokens[0], "take") == 0 || strcmp(tokens[0], "pickup") == 0)
                {
                    remove_item_from_room(game->curr_room, curr_item);
                    add_item_to_player(game->curr_player, curr_item);
                }
            }
            curr_item = curr_item->next;
        }
        return str;
    }
    return "The object could not be found\n";
}

//KIND 2:   ACTION <direction>
char *kind2_action_operation(char *tokens[TOKEN_LIST_SIZE], chiventure_ctx_t *ctx)
{
    game_t *game = ctx->game;
    if(game == NULL || game->curr_room == NULL)
    {
        print_to_cli(ctx, tokens[0]);
        return "Error! We need a loaded room to do the above action. \n";
    }
    lookup_t **table = ctx->cli_ctx->table;

    if(tokens[1] == NULL)
    {
        return "You must specify a direction to go \n";
    }
    if(tokens[2] != NULL)
    {
        return "Sorry, you can only go one direction \n";
    }

    path_t *curr_path;
    ITER_ALL_PATHS(game->curr_room, curr_path)
    {
        if(strcmp(curr_path->direction,tokens[1]) == 0)
        {
            action_type_t *action = find_action(tokens[0], table);

            char *str;
            do_path_action(ctx, action, curr_path, &str);
            return str;
        }
    }
    return "You cannot go in this direction\n";
}

//KIND 3:   ACTION <item> <item>
char *kind3_action_operation(char *tokens[TOKEN_LIST_SIZE], chiventure_ctx_t *ctx)
{
    game_t *game = ctx->game;
    if(game == NULL || game->curr_room == NULL)
    {
        print_to_cli(ctx, tokens[0]);
        return "Error! We need a loaded room to do the above action. \n";
    }
    lookup_t **table = ctx->cli_ctx->table;

    if(tokens[1] == NULL || tokens[3] == NULL)
    {
        return "You must identify two objects to act on";
    }

    item_t *item1, *item2;
    item1 = get_item_in_room(game->curr_room, tokens[1]);
    item2 = get_item_in_room(game->curr_room, tokens[3]);

    if(item1 == NULL || item2 == NULL)
    {
        return "The object(s) could not be found";
    }
    
    action_type_t *action = find_action(tokens[0], table);
    char *str;
    bool action_success = false;
    
    /* Loops through items with identical ids 
     * until action succeeds or all items fail */
    while (!action_success && item1 != NULL)
    {
        item_t *item2_iter = item2;
        while (!action_success && item2_iter != NULL)
        {
            int rc = do_item_item_action(ctx, action, item1, item2_iter, &str);
            if (rc == SUCCESS)
            {
                action_success = true;
            }
            item2_iter = item2_iter->next;
        }
        item1 = item1->next;
    }
    
    return str;
}



char *action_error_operation(char *tokens[TOKEN_LIST_SIZE], chiventure_ctx_t *ctx)
{

    if (tokens[0] == NULL) 
    {
        return "This input returned as NULL";
    }

    char* suggestion = NULL;
    suggestion = suggestions(strdup(tokens[0]), actions_for_sug);

    if (suggestion != NULL) 
    {
        int str1 = strlen(suggestion);
        int str2 = strlen("This action is not supported. Did you mean: ");
        int len = str1 + str2;
        char msg[] =  "This action is not supported. Did you mean: ";
        print_to_cli(ctx, strncat(msg, suggestion, len));
        return "";
    }
    return "This action is not supported. No suggestions could be found";
}

char *inventory_operation(char *tokens[TOKEN_LIST_SIZE], chiventure_ctx_t *ctx)
{
    game_t *game = ctx->game;
    if(game == NULL || game->curr_player == NULL)
    {
        print_to_cli(ctx, tokens[0]);
        return "Error! We need a loaded player to check inventory.\n";
    }
    item_list_t *t;
    int i = 0;
    ITER_ALL_ITEMS_IN_INVENTORY(game->curr_player, t)
    {
        i++;

        //To print an integer with print_to_cli, int i must be cast to a string
        //10 was chosen as a buffer, i should not need all 10 bytes

        //Commenting the code that prints what item number the loop is on for now, if this functionality
        //is useful in the future it can be uncommented

        // int strbuff = 10;
        // char str[strbuff];
        // sprintf(str, "%d", i);
        // print_to_cli(ctx, str);

        print_to_cli(ctx, t->item->item_id);
    }
    return "This was your inventory";
}


char *items_in_room_operation(char *tokens[TOKEN_LIST_SIZE], chiventure_ctx_t *ctx)
{
    game_t *game = ctx->game;
    if(game == NULL || game->curr_room == NULL)
    {
        print_to_cli(ctx, tokens[0]);
        return "Error! We need a loaded room to check items.\n";
    }
    item_list_t *t;
    int i = 0;
    ITER_ALL_ITEMS_IN_ROOM(game->curr_room, t)
    {
        i++;
        print_to_cli(ctx, t->item->item_id);
    }
    return "These are the items in the room";
}


char *npcs_in_room_operation(char *tokens[TOKEN_LIST_SIZE], chiventure_ctx_t *ctx)
{
    game_t *game = ctx->game;
    if(game == NULL || game->curr_room == NULL)
    {
        print_to_cli(ctx, tokens[0]);
        return "Error! We need a loaded room to check NPCs.\n";
    }

    npc_t *npc_tmp, *npc_elt;
    int i = 0;
    HASH_ITER(hh, game->curr_room->npcs->npc_list, npc_elt, npc_tmp) 
    {   
        i++;
        if (npc_elt->npc_battle->health > 0) 
        {
            print_to_cli(ctx, npc_elt->npc_id);
        }
    }

    if (i >= 1) 
    {
        return "These are the NPCs in the room";
    } 
    else 
    {
        return "There is no NPC in the room";
    }
}


char *map_operation(char *tokens[TOKEN_LIST_SIZE], chiventure_ctx_t *ctx)
{
    toggle_map(ctx);
    return "Map toggled.";
}

char *switch_operation(char *tokens[TOKEN_LIST_SIZE], chiventure_ctx_t *ctx)
{
    layout_switch(ctx);
    return "Layout switched.";
}


char *name_operation(char *tokens[TOKEN_LIST_SIZE], chiventure_ctx_t *ctx)
{
    case_insensitize(tokens[1]);
    case_insensitize(tokens[2]);
    if(find_entry(tokens[1], (ctx->cli_ctx->table)) == NULL)
    {
        return "New words must be defined using only words that are already defined!";
    }
    if(find_entry(tokens[2],(ctx->cli_ctx->table)) != NULL)
    {
        return "You can't change the meaning of a word that's already defined!";
    }
    add_entry(tokens[2],(find_operation(tokens[1],(ctx->cli_ctx->table))), (find_action(tokens[1],(ctx->cli_ctx->table))), (ctx->cli_ctx->table));
    return "The two words are now synonyms!";
}

char *palette_operation(char *tokens[TOKEN_LIST_SIZE], chiventure_ctx_t *ctx)
{
    int n = 0;
    if (tokens[1] == NULL)
    {
        return "Please input a theme";
    }
    case_insensitize(tokens[1]);
    if(strcmp(tokens[1], "default") == 0)
    {
        n = 1;
    }
    if(strcmp(tokens[1], "night") == 0)
    {
        n = 2;
    }
    if(strcmp(tokens[1], "bright") == 0)
    {
        n = 3;
    }
    if(strcmp(tokens[1], "pain") == 0)
    {
        n = 4;
    }
    if(n != 0)
    {
        wbkgd(ctx->ui_ctx->cli_win->w, COLOR_PAIR(n));
        wbkgd(ctx->ui_ctx->displayed_win->w, COLOR_PAIR(n));
        wbkgd(ctx->ui_ctx->map->pad, COLOR_PAIR(n));
        return "The color palette has been changed";
    }
    return "I don't have that palette yet. You must make do with the current style.";
}

/* See cmd.h */
char *talk_operation(char *tokens[TOKEN_LIST_SIZE], chiventure_ctx_t *ctx)
{
    if (tokens[1] == NULL || tokens[2] == NULL)
    {
        return "You must identify an NPC to talk to.";
    }

    int rc;

    npc_t *npc = get_npc_in_room(ctx->game->curr_room, tokens[2]);

    if (npc == NULL)
    {
        return "No one by that name wants to talk.";
    }

    if (npc->dialogue == NULL)
    {
        return "This person has nothing to say.";
    }

    char *str = start_conversation(npc->dialogue, &rc, ctx->game);

    assert(rc != -1); //checking for conversation error

    if (rc == 0)
    {
        set_game_mode(ctx->game, CONVERSATION, npc->npc_id);
    }

    return str;
}
