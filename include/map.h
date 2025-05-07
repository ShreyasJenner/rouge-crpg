#ifndef MAP_H
#define MAP_H

typedef struct Room {
  int ltop_x;
  int ltop_y;
  int length;
  int breadth;
} Room;

typedef struct Level {
  int room_count;
  Room **rooms;
} Level;

Room *create_room(int ltop_x, int ltop_y, int length, int breadth);

Level *create_level(int room_count);

void render_room(Room *room);

void render_level(Level *level);

void destroy_room(Room *room);

void destroy_level(Level *level);

#endif // !MAP_H
