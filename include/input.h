#ifndef INPUT_H
#define INPUT_H

#include "player.h"

typedef struct InputHandling {
  char key;

} InputHandling;

InputHandling *create_InputHandling();

void store_key_press(InputHandling *ih, char key);

void update_player_coordinates(Player *player, int x, int y);

void move_player(Player *player, InputHandling *ih);

void destroy_InputHandling(InputHandling *ih);

#endif // !INPUT_H
