#include <ncurses.h>
#include <stdlib.h>

#include "player.h"

// Function to create a player
Player *create_player(int x, int y, char display) {

  Player *player = malloc(sizeof(Player));

  player->x = x;
  player->y = y;
  player->display = display;

  return player;
}

// Function to render a player
void render_player(Player *player) {

  mvprintw(player->y, player->x, "%c", player->display);

  refresh();
}

// Function to update player co-ordinates
void update_player_coordinates(Player *player, int x, int y) {

  player->x = x;
  player->y = y;
}

// Function to destroy player
void destroy_player(Player *player) { free(player); }
