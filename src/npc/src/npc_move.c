#include "npc/npc_move.h"

// STRUCT FUNCTIONS -----------------------------------------------------------
/* See npc_move.h */
int time_ray_init(time_ray_t *time_ray, double assigned_time)
{
    if (time_ray == NULL)
    {
        return FAILURE;
    }
    time_t start;
    time_ray->start = time(&start);
    time_ray->assigned_time = assigned_time;
    return SUCCESS;
}

/* See npc_move.h */
time_ray_t *time_ray_new(double assigned_time)
{
    time_ray_t *time_ray;
    time_ray = malloc(sizeof(time_ray_t));
    memset(time_ray, 0, sizeof(time_ray_t));
    assert(time_ray_init(time_ray, assigned_time) == SUCCESS);
    return time_ray;
}

/* See npc_move.h */
int time_ray_free(time_ray_t *time_ray)
{
    if (time_ray != NULL)
    {
        free(time_ray);
    }
    return SUCCESS;
}

/* See npc_move.h */
int npc_path_dll_init(npc_path_dll_t *head, npc_mov_enum_t mov_type,
                      char *room_id, double room_time)
{
    if (head == NULL)
    {
        return FAILURE;
    }
    strncpy(head->room_id, room_id, MAX_ID_LEN);
    if (mov_type == NPC_MOV_INDEFINITE)
    {
        head->room_time = time_ray_new(room_time);
    }
    else if (mov_type == NPC_MOV_DEFINITE)
    {
        head->room_time = NULL;
    }
    else
    {
        return FAILURE;
    }
    head->prev = NULL;
    head->next = NULL;

    return SUCCESS;
}

/* See npc_move.h */
npc_path_dll_t *npc_path_dll_new(npc_mov_enum_t mov_type, char *room_id,
                                 double room_time)
{
    npc_path_dll_t *path = malloc(sizeof(npc_path_dll_t));
    memset(path, 0, sizeof(npc_path_dll_t));
    path->room_id = malloc(MAX_ID_LEN);
    assert(npc_path_dll_init(path, mov_type, room_id, room_time) == SUCCESS);
    return path;
}

/* See npc_move.h */
int npc_path_dll_free(npc_path_dll_t *head)
{
    while (head->prev != NULL)
    {
        head = head->prev;
    }
    npc_path_dll_t *elt, *tmp;
    DL_FOREACH_SAFE(head, elt, tmp)
    {
        DL_DELETE(head, elt);
        free(elt->room_id);
        assert(time_ray_free(elt->room_time) == SUCCESS);
        free(elt);
    }
    return SUCCESS;
}

/* See npc_move.h */
int npc_mov_init(npc_mov_t *npc_mov, npc_mov_enum_t mov_type, char *room_id,
                 double room_time)
{
    assert(npc_mov != NULL);
    npc_mov->mov_type = mov_type;
    strncpy(npc_mov->track, room_id, MAX_ID_LEN);
    npc_mov->npc_path_pos = 0;
    npc_mov->npc_path_direction = NPC_MOV_ORIGINAL;
    npc_mov->path = npc_path_dll_new(mov_type, room_id, room_time);
    if (npc_mov->path == NULL)
    {
        return FAILURE;
    }
    return SUCCESS;
}


/* See npc_move.h */
npc_mov_t *npc_mov_new(npc_mov_enum_t mov_type, char *room_id, double room_time)
{
    npc_mov_t *npc_mov;
    npc_mov = malloc(sizeof(npc_mov_t));
    memset(npc_mov, 0, sizeof(npc_mov_t));
    npc_mov->track = malloc(MAX_ID_LEN);

    int check = npc_mov_init(npc_mov, mov_type, room_id, room_time);

    if (npc_mov == NULL || check != SUCCESS)
    {
        return NULL;
    }

    return npc_mov;
}

/* See npc_move.h */
int npc_mov_free(npc_mov_t *npc_mov)
{
    assert(npc_mov != NULL);
    npc_path_dll_free(npc_mov->path);
    free(npc_mov->track);
    free(npc_mov);
    return SUCCESS;
}

// FUNCTIONS TO EXTEND PATHS --------------------------------------------------
/* See npc_move.h */
int extend_path_definite(npc_mov_t *npc_mov, char *room_id)
{
    assert(room_id != NULL);
    assert(npc_mov != NULL);

    npc_path_dll_t *new = npc_path_dll_new(NPC_MOV_DEFINITE, room_id, 0);
    DL_APPEND(npc_mov->path, new);

    return SUCCESS;
}


/* See npc_move.h */
int extend_path_indefinite(npc_mov_t *npc_mov, char *room_id, double room_time)
{
    assert(room_id != NULL);

    npc_path_dll_t *new;
    new = npc_path_dll_new(NPC_MOV_INDEFINITE, room_id, room_time);
    DL_APPEND(npc_mov->path, new);
    
    return SUCCESS;
}

// "GET" FUNCTIONS ------------------------------------------------------------
/* See npc_move.h */
char* get_npc_curr_room_id(npc_mov_t *npc_mov)
{
    return npc_mov->track;
}

/* See npc_move.h */
char *get_next_npc_room_id(npc_mov_t *npc_mov)
{
    npc_path_dll_t *current_room = npc_mov->path;

    npc_path_direction_t direction = npc_mov->npc_path_direction;
    unsigned int path_pos = npc_mov->npc_path_pos;

    if (path_pos != 0)
    {
        for (int i = 0; i < path_pos; i++)
        {
            current_room = current_room->next;
        }
    }
    else
    {
        if ((direction == NPC_MOV_ORIGINAL) && (current_room->next != NULL))
        {
            return current_room->next->room_id;
        }
        else
        {
            return NULL;
        }
    }

    if (direction == NPC_MOV_ORIGINAL)
    {
        if (current_room->next == NULL)
        {
            return NULL;
        }
        else
        {
            return current_room->next->room_id;
        }
    }
    else
    {
        return current_room->prev->room_id;
    }
}

/* See npc_move.h */
unsigned int get_npc_path_pos(npc_mov_t *npc_mov)
{
    return npc_mov->npc_path_pos;
}

/* See npc_move.h */
unsigned int get_npc_path_direction(npc_mov_t *npc_mov)
{
    return npc_mov->npc_path_direction;
}

/* See npc_move.h */
int get_npc_num_rooms(npc_mov_t *npc_mov)
{
    npc_path_dll_t *elt;
    int count = 0;
    DL_COUNT(npc_mov->path, elt, count);
    return count;
}

// COMPARISON FUNCTIONS -------------------------------------------------------
/* See npc_move.h */
int room_id_cmp(npc_path_dll_t *room1, npc_path_dll_t *room2)
{
    return strcmp(room1->room_id, room2->room_id);
}

// DO SOMETHING FUNCTIONS -----------------------------------------------------
/* See npc_move.h */
int flip_npc_path_direction(npc_mov_t *npc_mov)
{
    if (npc_mov->npc_path_direction == NPC_MOV_ORIGINAL)
    {
        npc_mov->npc_path_direction = NPC_MOV_REVERSED;
    }
    else if (npc_mov->npc_path_direction == NPC_MOV_REVERSED)
    {
        npc_mov->npc_path_direction = NPC_MOV_ORIGINAL;
    }
    else
    {
        return FAILURE;
    }

    return SUCCESS;
}

/* See npc_move.h */
int move_npc_mov(npc_mov_t *npc_mov)
{
    npc_path_dll_t *current_room = npc_mov->path;
    npc_path_direction_t direction = npc_mov->npc_path_direction;
    unsigned int path_pos = npc_mov->npc_path_pos;

    if ((current_room->next == NULL) && (current_room->prev == NULL))
    {
        return 3; // NPC has nowhere to move
    }

    if (path_pos != 0)
    {
        for (int i = 0; i < path_pos; i++)
        {
            current_room = current_room->next;
        }
    }

    if(((direction == NPC_MOV_ORIGINAL) && (current_room->next == NULL))
            || ((direction == NPC_MOV_REVERSED) && (current_room->prev == NULL)))
    {
        if (npc_mov->mov_type == NPC_MOV_INDEFINITE)
        {
            assert(flip_npc_path_direction(npc_mov) == SUCCESS);
        }
        return 1;
    }

    if((strcmp(current_room->room_id, npc_mov->track)) == 0)
    {
        if (direction == NPC_MOV_ORIGINAL)
        {
            npc_mov->track = current_room->next->room_id;
            npc_mov->npc_path_pos++;
        }
        else if (direction == NPC_MOV_REVERSED)
        {
            npc_mov->track = current_room->prev->room_id;
            npc_mov->npc_path_pos--;
        }
        else
        {
            return 0;
        }

        return 2;
    }
    else
    {
        return 0;
    }
}