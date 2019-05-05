/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: sample.proto */

#ifndef PROTOBUF_C_sample_2eproto__INCLUDED
#define PROTOBUF_C_sample_2eproto__INCLUDED

#include <protobuf-c/protobuf-c.h>

PROTOBUF_C__BEGIN_DECLS

#if PROTOBUF_C_VERSION_NUMBER < 1000000
# error This file was generated by a newer version of protoc-c which is incompatible with your libprotobuf-c headers. Please update your headers.
#elif 1002001 < PROTOBUF_C_MIN_COMPILER_VERSION
# error This file was generated by an older version of protoc-c which is incompatible with your libprotobuf-c headers. Please regenerate this file with a newer version of protoc-c.
#endif


typedef struct _Player Player;
typedef struct _Room Room;
typedef struct _Game Game;


/* --- enums --- */


/* --- messages --- */

struct  _Player
{
  ProtobufCMessage base;
  char *p_name;
};
#define PLAYER__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&player__descriptor) \
    , NULL }


struct  _Room
{
  ProtobufCMessage base;
  char *r_name;
};
#define ROOM__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&room__descriptor) \
    , NULL }


struct  _Game
{
  ProtobufCMessage base;
  Player *player_info;
  Room *location;
  /*
   * number of rooms found
   */
  protobuf_c_boolean has_discovered;
  int32_t discovered;
};
#define GAME__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&game__descriptor) \
    , NULL, NULL, 0,0 }


/* Player methods */
void   player__init
                     (Player         *message);
size_t player__get_packed_size
                     (const Player   *message);
size_t player__pack
                     (const Player   *message,
                      uint8_t             *out);
size_t player__pack_to_buffer
                     (const Player   *message,
                      ProtobufCBuffer     *buffer);
Player *
       player__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   player__free_unpacked
                     (Player *message,
                      ProtobufCAllocator *allocator);
/* Room methods */
void   room__init
                     (Room         *message);
size_t room__get_packed_size
                     (const Room   *message);
size_t room__pack
                     (const Room   *message,
                      uint8_t             *out);
size_t room__pack_to_buffer
                     (const Room   *message,
                      ProtobufCBuffer     *buffer);
Room *
       room__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   room__free_unpacked
                     (Room *message,
                      ProtobufCAllocator *allocator);
/* Game methods */
void   game__init
                     (Game         *message);
size_t game__get_packed_size
                     (const Game   *message);
size_t game__pack
                     (const Game   *message,
                      uint8_t             *out);
size_t game__pack_to_buffer
                     (const Game   *message,
                      ProtobufCBuffer     *buffer);
Game *
       game__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   game__free_unpacked
                     (Game *message,
                      ProtobufCAllocator *allocator);
/* --- per-message closures --- */

typedef void (*Player_Closure)
                 (const Player *message,
                  void *closure_data);
typedef void (*Room_Closure)
                 (const Room *message,
                  void *closure_data);
typedef void (*Game_Closure)
                 (const Game *message,
                  void *closure_data);

/* --- services --- */


/* --- descriptors --- */

extern const ProtobufCMessageDescriptor player__descriptor;
extern const ProtobufCMessageDescriptor room__descriptor;
extern const ProtobufCMessageDescriptor game__descriptor;

PROTOBUF_C__END_DECLS


#endif  /* PROTOBUF_C_sample_2eproto__INCLUDED */
