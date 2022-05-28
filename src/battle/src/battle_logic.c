#include "battle/battle_logic.h"
#include "common/utlist.h"
#include <ctype.h>


/* check battle_logic.h */
combatant_t* check_target(battle_t *b, char *target)
{
    combatant_t *temp;
    DL_FOREACH(b->enemy, temp)
    {
        if (strncmp(temp->name, target, MAX_NAME_LEN) == 0)
        {
            return temp;
        }
    }
    return NULL;
}

/* check battle_logic.h */
battle_status_t battle_over(battle_t *b)
{
    if(b->player->stats->hp <= 0)
    {
        return BATTLE_VICTOR_ENEMY;
    }

    combatant_t *temp;
    DL_FOREACH(b->enemy, temp)
    {
        if (temp->stats->surrender_level >= temp->stats->hp && (temp->stats->surrender_level > 0))
        {
            return BATTLE_ENEMY_SURRENDER;
        }
        else if (temp->stats->hp > 0)
        {
            return BATTLE_IN_PROGRESS;
        }
    }

    return BATTLE_VICTOR_PLAYER;
}

/* check battle_logic.h */
turn_t goes_first(battle_t *b)
{
    combatant_t *temp;
    DL_FOREACH(b->enemy, temp)
    {
        if (b->player->stats->speed < temp->stats->speed)
        {
            return ENEMY;
        }
    }
    return PLAYER;
}

/* see battle_logic.h */
move_t *find_player_move(battle_ctx_t *ctx, char *move_name)
{
    move_t *temp;
    move_t *player_move = NULL;

    DL_FOREACH(ctx->game->battle->player->moves, temp)
    {
        if (strncmp(temp->info, move_name, MAX_MOVE_INFO_LEN) == 0)
        {
            player_move = temp;
            return player_move;
        }
    }
    return NULL;
}

/* see battle_logic.h */
battle_item_t *find_battle_item(battle_item_t *inventory, char *input)
{
    battle_item_t *temp;

    DL_FOREACH(inventory, temp)
    {        
        if (strncmp(temp->name, input, 100) == 0)
        {
            return temp;
        }
    }

    return NULL;
}

/* see battle_logic.h */
int consume_battle_item(combatant_t *c, battle_item_t *item)
{
    apply_item_stat_changes(c->class_type, c->stats, item);
    return 0;
}

/* see battle_logic.h */
int use_battle_item(combatant_t *c, battle_t *battle, char *name)
{
    if (c->items == NULL)
    {
        return FAILURE;
    }
    
    battle_item_t *item = find_battle_item(c->items, name);
    
    if (item == NULL || item->quantity == 0)
    {
        return FAILURE;
    }

    if (item->attack)
    {
        consume_battle_item(battle->enemy, item);
    }
    else
    {
        consume_battle_item(c, item);
    }
    item->quantity -= 1;
    if (item->quantity == 0)
    {
        remove_battle_item(c, item);
    }
    
    return SUCCESS;
}

/* see battle_logic.h */
int remove_battle_item(combatant_t *c, battle_item_t *item)
{
    if (item == NULL)
    {
        return FAILURE;
    }

    battle_item_t *temp;
    DL_FOREACH(c->items, temp)
    {
        if (temp == item)
        {
            if (temp == c->items) // first item in the list
            {
                c->items = temp->next;
            }
            else
            {
                temp->prev->next = temp->next;
            }

            if (temp->next != NULL)
            {
                temp->next->prev = temp->prev;
            }
            free(item->name);
            free(item->description);
            free(item);
        }
    }
    return SUCCESS;
}

/* see battle_logic.h */
int award_xp(stat_t *stats, double xp)
{
    stats->xp += xp;
    return 0;
}

/* see battle_logic.h */
int apply_movement_stat_changes(stat_t* target_stats, stat_changes_t* changes)  
{
    target_stats->speed += changes->speed;
    target_stats->max_sp += changes->max_sp;
    if ((target_stats->sp + changes->sp) <= target_stats->max_sp)
    {
        target_stats->sp += changes->sp;
    }
    else
    {
        target_stats->sp = target_stats->max_sp;
    }
    target_stats->phys_atk += changes->phys_atk;
    target_stats->mag_atk += changes->mag_atk;
    target_stats->phys_def += changes->phys_def;
    target_stats->mag_def += changes->mag_def;
    target_stats->crit += changes->crit;
    target_stats->accuracy += changes->accuracy;
    target_stats->hp += changes->hp;
    target_stats->max_hp += changes->max_hp;
    if ((target_stats->hp += changes->hp) <= target_stats->max_hp)
    {
        target_stats->hp += changes->hp;
    }else
    {
        target_stats->hp = target_stats->max_hp;
    }
    return SUCCESS;
}

/* see battle_logic.h */
int apply_item_stat_changes(class_t* class, stat_t* target_stats, battle_item_t* item)  
{
    class_item_stat_multipliers_t* mults = class_multipliers(class, item);
    
    target_stats->speed += item->attributes->speed;// * mults->speed;
    target_stats->max_sp += item->attributes->max_sp;// * mults->max_sp;
    if ((target_stats->sp + (item->attributes->sp/* * mults->sp*/)) <= target_stats->max_sp)
    {
        target_stats->sp += item->attributes->sp;// * mults->sp;
    } else {
        target_stats->sp = target_stats->max_sp;
    }
    target_stats->phys_atk += item->attributes->phys_atk;// * mults->phys_atk;
    target_stats->mag_atk += item->attributes->mag_atk;// * mults->mag_atk;
    target_stats->phys_def += item->attributes->phys_def;// * mults->phys_def;
    target_stats->mag_def += item->attributes->mag_def;// * mults->mag_def;
    target_stats->crit += item->attributes->crit;// * mults->crit;
    target_stats->accuracy += item->attributes->accuracy;// * mults->accuracy;
    target_stats->hp += item->attributes->hp;// * mults->hp;
    target_stats->max_hp += item->attributes->max_hp;// * mults->max_hp;
    if ((target_stats->hp += (item->attributes->hp/* * mults->hp*/)) <= target_stats->max_hp)
    {
        target_stats->hp += item->attributes->hp;// * mults->hp;
    } else {
        target_stats->hp = target_stats->max_hp;
    }
    return SUCCESS;
}

/*
 * Initializes a new class_item_stat_multipliers_t struct with all
 * parameters as 1
 * Parameters: None
 * Returns:
 *  A new class_item_stat_multipliers_t
 */
class_item_stat_multipliers_t* class_item_stat_multipliers_new()
{
    class_item_stat_multipliers_t* mults = (class_item_stat_multipliers_t*)malloc(sizeof(class_item_stat_multipliers_t));
    mults->speed = 1;
    mults->max_sp = 1;
    mults->sp = 1;
    mults->phys_atk = 1;
    mults->mag_atk = 1;
    mults->phys_def = 1;
    mults->mag_def = 1;
    mults->speed = 1;
    mults->crit = 1;
    mults->accuracy = 1;
    mults->hp = 1;
    mults->max_hp = 1;

    return mults;
}

/* see battle_logic.h */
class_item_stat_multipliers_t* class_multipliers(class_t* class, battle_item_t* item)
{
    class_item_stat_multipliers_t* mults = class_item_stat_multipliers_new();

    if (strcmp(class->name, "warrior") == 0) {
        if /*(strcmp(item->name, "Strength Up") == 0)*/ (1) {
            mults->phys_atk = 1.5; //1.5
        }/*
        if (strcmp(item->name, "Defense Up") == 0) {
            mults->phys_def = 1; //1.2
        }*/
    }/*
    if (strcmp(class->name, "wizard") == 0) {
        if (strcmp(item->name, "Strength Up") == 0) {
            mults->phys_atk = 1; //0.8
        }
        if (strcmp(item->name, "Defense Up") == 0) {
            mults->phys_def = 1; //1.2
        }
        if (strcmp(item->name, "Healing Potion") == 0) {
            mults->hp = 1; // 1.5
        }
    } 
    if (strcmp(class->name, "bard") == 0) {
        if (strcmp(item->name, "Elixir of Life") == 0) {
            mults->hp = 1; //1.2
        }
    }
    if (strcmp(class->name, "rogue") == 0) {
        if (strcmp(item->name, "Elixir of Life") == 0) {
            mults->hp = 1; //0.8
        }
        if (strcmp(item->name, "Healing Potion") == 0) {
            mults->hp = 1; //1.2
        }
    }*/

    return mults;
}

/* see battle_logic.h */
int stat_changes_add_item_node(stat_changes_t *sc, battle_item_t *item)
{
    stat_changes_add_node(sc);

    stat_changes_t *current = sc;

    while (sc->next != NULL) {
        sc = sc->next;
    }
    stat_changes_t *changes = item->attributes;
    sc->max_hp += changes->max_hp;
    sc->hp += changes->hp;    
    sc->phys_atk += changes->phys_atk;
    sc->phys_def += changes->phys_def; 
    sc->mag_atk += changes->mag_atk;
    sc->mag_def += changes->mag_def;
    sc->speed += changes->speed;
    sc->crit += changes->crit;
    sc->accuracy += changes->accuracy;
    sc->max_sp += changes->max_sp;
    sc->sp += changes->sp;

    return SUCCESS;
}

/* see battle_logic.h */
void get_legal_actions(battle_item_t *items, 
                       move_t *moves, 
                       turn_component_t comp, 
                       battle_t *battle) {
  // this is the combatant who's turn it is (player or enemy)
  combatant_t *current_actor = (battle->turn == PLAYER) ? battle->player : battle->enemy;

  // if the current turn component allows the combatant to use an item,
  // add the combatant's items to the return value for possible items
  if(comp.item) {
    items = current_actor->items;
  }
  // if the current turn component allows the combatant to make a move,
  // add the combatant's moves to the return value for possible moves
  if(comp.move) {
    moves = current_actor->moves;
  }
  
  return;
}

/* see battle_logic.h */
int num_moves(move_t *moves) {
  int count = 0;
  while(moves) {
    moves = moves->next;
    count++;
  }
  return count;
}

/* see battle_logic.h */
int num_items(battle_item_t *items) {
  int count = 0;
  while(items) {
    items = items->next;
    count++;
  }
  return count;
}