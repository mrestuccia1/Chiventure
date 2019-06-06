#include <criterion/criterion.h>
#include <stdlib.h>
#include <stdbool.h>
#include "load_item.h"

//TEMPORARILY ADDING FUNCTIONS FOR TESTING; WILL REMOVE BEFORE PR
//**********************************************
/* see item.h */
char *get_sdesc_item(item_t *item)
{
  if (item == NULL) {
    return NULL;
  }
  return item->short_desc;
}

/* see item.h */
char *get_ldesc_item(item_t *item)
{
  if (item == NULL) {
    return NULL;
  }
  return item->long_desc;
}
//**********************************************

// Test(items, load_items)
// {
//     obj_t *doc = get_doc_obj(FILE_PATH);
//     game_t *g = game_new("Welcome to UChicago");
   
//     // check and load rooms
//     int rc = add_rooms_to_game(doc, g);
//     cr_assert_eq(rc, SUCCESS, "adding rooms to game failed");

//     // check adding items to game
//     rc = load_items(doc, g);
//     cr_assert_eq(rc, SUCCESS, "loading items failed");
// }


// Test(items, load_items_chair_check)
// {
//     obj_t *doc = get_doc_obj(FILE_PATH);
//     game_t *g = game_new("Welcome to UChicago");

//     // check adding rooms to game
//     int rc = add_rooms_to_game(doc, g);
//     cr_assert_eq(rc, SUCCESS, "adding rooms to game failed");

//     // check adding items to game
//     rc = load_items(doc, g);
//     cr_assert_eq(rc, SUCCESS, "loading items failed");

//     // checking fields were correctly filled
//     room_t *r = find_room_from_game(g, "room A");
//     item_t *i = get_item_in_room(r, "chair");

//     char *s = get_sdesc_item(i);
//     char *scmp = "This is a chair";
//     rc = strncmp(s, scmp, strlen(scmp));
//     cr_assert_eq(rc, SUCCESS, "failed to parse item sdesc");

//     char *l = get_ldesc_item(i);
//     char *lcmp = "This is a chair long";
//     rc = strncmp(l, lcmp, strlen(lcmp));
//     cr_assert_eq(rc, SUCCESS, "failed to parse item ldesc");
// }

void item_check(char *room, char *item, char *index)
{
    obj_t *doc = get_doc_obj(FILE_PATH);
    game_t *g = game_new("Welcome to UChicago");

    // check adding rooms to game
    int rc = add_rooms_to_game(doc, g);
    cr_assert_eq(rc, SUCCESS, "adding rooms to game failed");

    // check adding items to game
    rc = load_items(doc, g);
    cr_assert_eq(rc, SUCCESS, "loading items failed");

    // checking fields were correctly filled
    room_t *r = find_room_from_game(g, room);
    item_t *i = get_item_in_room(r, item);

    char *item_path = malloc(100);
    strcpy(item_path, "ITEMS.");
    strncat(item_path, index, 94);
    obj_t *item_obj = obj_get_attr(doc, item_path, false);

    char *s = get_sdesc_item(i);
    char *scmp = obj_get_str(item_obj, "short_desc");
    rc = strncmp(s, scmp, strlen(scmp));
    cr_assert_eq(rc, SUCCESS, "failed to parse item sdesc");

    char *l = get_ldesc_item(i);
    char *lcmp = obj_get_str(item_obj, "long_desc");
    rc = strncmp(l, lcmp, strlen(lcmp));
    cr_assert_eq(rc, SUCCESS, "failed to parse item sdesc");

    obj_t *actions = obj_get_attr(item_obj, "actions", false);
    attr_list_t *action_ll = obj_list_attr(actions);

    while(action_ll != NULL)
    {
        rc = allowed_action(i, action_ll->obj->id);
        cr_assert_eq(rc, 0, "failed to load item action");
    }    
}

Test(items, load_items_chair_check)
{
    item_check("room A", "chair", "0");
}
