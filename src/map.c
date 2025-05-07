#include <ncurses.h>
#include <stdbool.h>
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

// Function to create a path pointer
Path *create_path(int x, int y, int path_length, bool horizontal) {
  Path *path = malloc(sizeof(Path));
  path->x = x;
  path->y = y;
  path->length = path_length;
  path->horizontal = horizontal;

  return path;
}

// Function to create a level pointer with a given number of room pointers
Level *create_level(int room_count, int path_count) {
  Level *level = malloc(sizeof(Level));
  Room **rooms = (Room **)calloc(room_count, sizeof(Room *));
  Path **paths = (Path **)calloc(path_count, sizeof(Path *));

  // assign room pointers to null
  for (int i = 0; i < room_count; i++) {
    rooms[i] = NULL;
  }

  // assign path pointers to null
  for (int i = 0; i < path_count; i++) {
    paths[i] = NULL;
  }

  level->room_count = room_count;
  level->path_count = path_count;
  level->rooms = rooms;
  level->paths = paths;

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

// Function to render a path in ncurses
// By default: paths are horizontal
void render_path(Path *path) {

  for (int i = 0; i < path->length; i++) {

    // render horizontal path
    if (path->horizontal) {
      mvprintw(path->y, path->x + i, "#");
    } else {
      // render vertical path
      mvprintw(path->y + i, path->x, "#");
    }
  }

  refresh();
}

// Function to render a level in ncurses
void render_level(Level *level) {

  // render rooms
  for (int i = 0; i < level->room_count; i++) {

    // render room if it exists
    if (level->rooms[i] != NULL) {
      render_room(level->rooms[i]);
    }
  }

  // render paths
  for (int i = 0; i < level->path_count; i++) {

    // render path if it exists
    if (level->paths[i] != NULL) {
      render_path(level->paths[i]);
    }
  }
}
// Function to destroy a room
void destroy_room(Room *room) { free(room); }

// Function to destroy a path
void destroy_path(Path *path) { free(path); }

// Function to destroy a level
void destroy_level(Level *level) {

  // destroy rooms
  for (int i = 0; i < level->room_count; i++) {

    // destroy room if it exists
    if (level->rooms[i] != NULL) {
      destroy_room(level->rooms[i]);
    }
  }

  // destroy paths
  for (int i = 0; i < level->path_count; i++) {

    // destroy path if it exists
    if (level->paths[i] != NULL) {
      destroy_path(level->paths[i]);
    }
  }

  free(level);
}
