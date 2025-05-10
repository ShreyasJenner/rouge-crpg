#ifndef PLAYER_H
#define PLAYER_H

typedef struct Player {
  int x;
  int y;
  char display;

} Player;

Player *create_player(int x, int y, char display);

void render_player(Player *player);

void destroy_player(Player *player);

void update_player_coordinates(Player *player, int x, int y);

#endif // !PLAYER_H
