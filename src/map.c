#include <ncurses.h>
#include <stdlib.h>

#include "map.h"

// Function to create a room pointer of given coordinates
Room *create_room(int ltop_x, int ltop_y, int length, int breadth) {
  Room *room = malloc(sizeof(Room));
  room->ltop_x = ltop_x;
  room->ltop_y = ltop_y;
  room->length = length;
  room->breadth = breadth;

  return room;
}

// Function to create a level pointer with a given number of room pointers
Level *create_level(int room_count) {
  Level *level = malloc(sizeof(Level));
  Room **rooms = (Room **)calloc(room_count, sizeof(Room *));

  // assign all room pointers to null
  for (int i = 0; i < room_count; i++) {
    rooms[i] = NULL;
  }

  level->room_count = room_count;
  level->rooms = rooms;

  return level;
}

// Function to render a room in ncurses
void render_room(Room *room) {

  // loops to render the room
  for (int i = 0; i < room->breadth; i++) {
    for (int j = 0; j < room->length; j++) {

      // render side boundaries of room
      if (j == 0 || j == room->length - 1) {
        mvprintw(room->ltop_y + i, room->ltop_x + j, "|");
      } else if (i == 0 || i == room->breadth - 1) {
        // render upper boundaries of room
        mvprintw(room->ltop_y + i, room->ltop_x + j, "-");
      } else {
        // else render inside of room
        mvprintw(room->ltop_y + i, room->ltop_x + j, "+");
      }
    }
  }

  refresh();
}

// Function to render a level in ncurses
void render_level(Level *level) {
  for (int i = 0; i < level->room_count; i++) {

    // render room if it exists
    if (level->rooms[i] != NULL) {
      render_room(level->rooms[i]);
    }
  }
}

// Function to destroy a room
void destroy_room(Room *room) { free(room); }

// Function to clean up a level
void destroy_level(Level *level) {
  for (int i = 0; i < level->room_count; i++) {

    // destroy room if it exists
    if (level->rooms[i] != NULL) {
      destroy_room(level->rooms[i]);
    }
  }

  free(level);
}
