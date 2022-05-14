/*
 * Header file for loading NPC objects into game struct
 */

#ifndef INCLUDE_LOAD_OPENWORLD_H
#define INCLUDE_LOAD_OPENWORLD_H

#include "wdl_common.h"
#include "validate.h"
#include "load_condition.h"
#include "openworld/gen_structs.h"

/* load_itemspecs
 * takes in wdl object and load loads itemspecs into itemspec struct to be used by openworld 
*module
 *
 * parameters:
 * - dialogue_obj: the itemspec object
 * - itemspecs: the itemspec struct it is being loaded into
 *
 * returns;
 * - SUCCESS for successful parse
 * - FAILURE for unsuccessful parse
 */
int load_itemspecs( obj_t  *doc,  itemspec_t* itemspec);


/* load_itemspecs
 * takes in wdl object and load loads itemspecs into itemspec struct to be used by openworld 
*module
 *
 * parameters:
 * - dialogue_obj: the itemspec object
 * - itemspecs: the itemspec struct it is being loaded into
 *
 * returns;
 * - SUCCESS for successful parse
 * - FAILURE for unsuccessful parse
 */
int load_roomspec( obj_t  *doc,  roomspec_t* roomspec );


/* load_itemspecs
 * takes in wdl object and load loads itemspecs into itemspec struct to be used by openworld 
*module
 *
 * parameters:
 * - dialogue_obj: the itemspec object
 * - itemspecs: the itemspec struct it is being loaded into
 *
 * returns;
 * - SUCCESS for successful parse
 * - FAILURE for unsuccessful parse
 */
int load_gen_context( obj_t  *doc,  gencontext_t* gencontext );


/* load_itemspecs
 * takes in wdl object and load loads itemspecs into itemspec struct to be used by openworld 
*module
 *
 * parameters:
 * - dialogue_obj: the itemspec object
 * - itemspecs: the itemspec struct it is being loaded into
 *
 * returns;
 * - SUCCESS for successful parse
 * - FAILURE for unsuccessful parse
 */
int load_roomlevel ( obj_t  *doc,  roomlevel_t* roomlevel );


/* load_itemspecs
 * takes in wdl object and load loads itemspecs into itemspec struct to be used by openworld 
*module
 *
 * parameters:
 * - dialogue_obj: the itemspec object
 * - itemspecs: the itemspec struct it is being loaded into
 *
 * returns;
 * - SUCCESS for successful parse
 * - FAILURE for unsuccessful parse
 */
int load_levelspecs( obj_t  *doc,  levelspec_t* levelspec);

#endif /* INCLUDE_LOAD_OPENWORLD_H */