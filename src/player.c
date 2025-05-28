#include <ncurses.h>
#include <stdlib.h>

#include "input.h"
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

// Function to check if the move to be made by the player is legal
int legal_move(int x, int y) {
  char map_char;

  map_char = mvinch(y, x);

  if (map_char == '+' || map_char == '#') {
    return 1;
  } else {
    return 0;
  }
}

// Function to move player
void move_player(Player *player, InputHandling *ih) {

  // player moves right
  if (ih->key == 'd') {

    if (legal_move(player->x + 1, player->y)) {
      update_player_coordinates(player, player->x + 1, player->y);
    }

  } else if (ih->key == 'a') {

    // player moves left
    if (legal_move(player->x - 1, player->y)) {
      update_player_coordinates(player, player->x - 1, player->y);
    }

  } else if (ih->key == 'w') {

    // player moves up
    if (legal_move(player->x, player->y - 1)) {
      update_player_coordinates(player, player->x, player->y - 1);
    }

  } else if (ih->key == 's') {

    // player moves down
    if (legal_move(player->x, player->y + 1)) {
      update_player_coordinates(player, player->x, player->y + 1);
    }
  }

  render_player(player);
}

// Function to destroy player
void destroy_player(Player *player) { free(player); }
