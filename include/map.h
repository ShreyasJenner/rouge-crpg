#ifndef MAP_H
#define MAP_H

#include <stdbool.h>

typedef struct Room {
  int ltop_x;
  int ltop_y;
  int length;
  int breadth;
} Room;

typedef struct Path {
  int y;
  int x;
  int length;
  bool horizontal;
} Path;

typedef struct Level {
  int room_count;
  int path_count;

  Room **rooms;
  Path **paths;
} Level;

Room *create_room(int ltop_x, int ltop_y, int length, int breadth);

Path *create_path(int x, int y, int path_length, bool horizontal);

Level *create_level(int room_count, int path_count);

void render_room(Room *room);

void render_path(Path *path);

void render_level(Level *level);

void destroy_room(Room *room);

void destroy_path(Path *path);

void destroy_level(Level *level);

#endif // !MAP_H
