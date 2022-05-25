/*
 * A file containing the 2022 demo for the playerclass component.
 */

#include <stdio.h>

#include "playerclass/class_structs.h"
#include "playerclass/class_prefabs.h"
#include "playerclass/class_item.h"
#include "playerclass/multiclass.h"
//We are aiming to make multiclass skilltrees and multiclass prefabs that go here


#include "skilltrees/skilltree.h"
#include "zip.h"
#include "libobj/load.h"
#include "wdl/load_game.h"


/* A helper function for printing a class. */
void print_class(class_t* class) {
    printf("------------------------------------------------------------\n");

    if (class == NULL) {
        printf("Class is NULL.\n");
        printf("------------------------------------------------------------\n");
        return;
    }

    /* Name */
    if (class->name != NULL) {
        printf("Name: %s\n", class->name);
    }
    else {
        printf("Name: NULL.\n");
    }

    /* Multiclass info */
    if (class->num_parent_class > 0) {
        printf("Multiclass with parents: \n");
        for (int i = 0; i < class->num_parent_class; i++) {
            printf("Parent Class %d: %s\n", i+1, class->parent_class_names[i]);
        }
    }
    else {
        printf("Single Class\n");
    }

    /* Short Description */
    if (class->shortdesc != NULL) {
        printf("Short Description: %s\n", class->shortdesc);
    }
    else {
        printf("Short Description: NULL\n");
    }

    /* Long Description */
    if (class->longdesc != NULL) {
        printf("Long Description: %s\n", class->longdesc);
    }
    else {
        printf("Long Description: NULL\n");
    }

    /* Attributes */
    if (class->attributes != NULL) {
        printf("Attributes:\n");
        dump_obj(class->attributes);
    }
    else {
        printf("Attributes: NULL\n");
    }

    /* Stats */
    if (class->base_stats != NULL) {
        printf("Base Stats: \n");
        stats_t *stat, *tmp;
        HASH_ITER(hh, class->base_stats, stat, tmp) {
            printf("    %s: %.2f / %.2f\n", stat->key, stat->val, stat->global->max);
        }
    }
    else {
        printf("Base Stats: NULL\n");
    }

    /* Effects */
    if (class->effects != NULL) {
        printf("Effects: \n");
        stat_effect_t *effect, *tmp;
        HASH_ITER(hh, class->effects, effect, tmp) {
            /* This could be improved to print more info, but this should suffice for now */
            printf("    %s", effect->key);
        }
    }
    else {
        printf("Effects: NULL\n");
    }

    /* Skill Tree */
    if (class->skilltree != NULL) {
        printf("Skill Tree: \n");
        for (int i = 0; i < class->skilltree->num_nodes; i++) {
            /* This could also be improved */
            printf("    %s\n", class->skilltree->nodes[i]->skill->name);
        }
    }
    else {
        printf("Skill Tree: NULL\n");
    }
    
    /* Starting Skills */
    if (class->starting_skills != NULL) {
        printf("Starting Skills: \n");
        for (int i = 0; i < class->starting_skills->num_active; i++) {
            printf("    %s\n", class->starting_skills->active[i]->name);
        }
        for (int i = 0; i < class->starting_skills->num_passive; i++) {
            printf("    %s\n", class->starting_skills->passive[i]->name);
        }
    }
    else {
        printf("Starting Skills: NULL\n");
    }

    printf("------------------------------------------------------------\n");
}


#define BUFFER_SIZE 100

/* A helper function for pausing execution and asking for input. 
 * 
 * Parameters:
 *  - message: The message that will be printed out as a prompt (newline is added).
 *  - input: Pointer to memory to store the input, or NULL (in which case input is ignored).
 * 
 * Returns:
 *  - Nothing.
 */
void prompt(char* message, char* input) {
    printf("%s\n>>> ", message);

    if (input != NULL) {
        fgets(input, BUFFER_SIZE, stdin);

        /* Delete trailing newline */
        char* ch_ptr = input;
        while (*ch_ptr != '\n') {
            ch_ptr += sizeof(char);
        }
        *ch_ptr = '\0'; 
    }
    else {
        char ignore[BUFFER_SIZE];
        fgets(ignore, BUFFER_SIZE, stdin);
    }
}

/* This path expects that we are at the root of the build directory */
#define CLASSES_WDL_PATH "../tests/wdl/examples/wdl/classes.wdl"

/* Helper function appropriated from WDL tests to load in a file */
static obj_t *get_doc_obj()
{
    char zip_name[10 * (MAXLEN_ID + 1)] = {0};
    strcat(zip_name, "./");
    strcat(zip_name, "zip_default.zip");

    // Create the zip
    int error = 0;
    zip_t *zip = zip_open(zip_name, ZIP_CREATE | ZIP_TRUNCATE, &error);

    // Add DEFAULT.json to the zip
    char *data_name = "DEFAULT.json";
    char *data_path = CLASSES_WDL_PATH; // Edited to load the example file with classes

    zip_error_t err = {0};
    zip_source_t *zip_src = zip_source_file_create(data_path, 0, 0, &err);

    zip_int64_t idx = zip_file_add(zip, data_name, zip_src, ZIP_FL_ENC_UTF_8);

    // Write and save to disk
    int rc = zip_close(zip);
    zip_error_t *close = zip_get_error(zip);

    int open_status;
    zip = zip_open(zip_name, 0, &open_status);

    // Read the zip into an obj
    obj_t *obj = obj_new("doc");
    rc = load_obj_store_from_zip(obj, zip);

    return obj;
}

/* The following functions are demo functions.  Feel free to loop and prompt for 
 * input, just remember to make it possible to escape these functions. */

void demo_prefab_classes() {
    game_t* game = game_new("The playerclass demo game!");

    /* Runs until you input nothing. */
    char class_name[BUFFER_SIZE];
    while (true) {
        prompt("Pick a prefab class:", class_name);
        if (class_name[0] == '\0') {
            break;
        }
        class_t* class = class_prefab_new(game, class_name);
        if (class != NULL) {
            class_prefab_add_skills(class);
        }
        print_class(class);
    }
}

void demo_multiclasses() {
    game_t* game = game_new("The playerclass demo game!");

    prompt("Loading Wizard class, a prefab class...", NULL);
    class_t* wizard_class = class_prefab_new(game, "Wizard");
    class_prefab_add_skills(wizard_class);
    print_class(wizard_class);

    prompt("Loading Warrior class, a prefab class...", NULL);
    class_t* warrior_class = class_prefab_new(game, "Warrior");
    class_prefab_add_skills(warrior_class);
    print_class(warrior_class);

    prompt("Creating a new multiclass called Hexblade from Wizard and Warrior...", NULL);
    class_t* hexblade_class = multiclass(wizard_class, warrior_class, "Hexblade");
    print_class(hexblade_class);
}


/* Due to having to locate the example WDL file, it is critical that this executable 
 * is run from from a specific location: the root of the build/ directory. Running it anywhere else will cause 
 * it to fail to find the WDL file, leading to segfaults. 
 * 
 * I prefer to use the command: 
 * $ make examples && src/playerclass/examples/2022-demo */

/* main function for the 2022-demo executable. */
int main() {
    /* We broke up the demo into two mini demos */
    printf("***Entering prefab mini-demo***\n");
    demo_prefab_classes();

    printf("***Entering multiclass mini-demo***\n");
    demo_multiclasses();
}
