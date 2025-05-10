#include <ncurses.h>

#include "map.h"
#include "player.h"

int screenSetup() {
  initscr();
  noecho();
  curs_set(0);
  refresh();

  return 0;
}

int main() {
  screenSetup();

  Level *level = create_level(2, 3);

  level->rooms[0] = create_room(10, 10, 10, 5);
  level->rooms[1] = create_room(20, 20, 20, 4);

  level->paths[0] = create_path(19, 12, 10, true);
  level->paths[1] = create_path(29, 12, 9, false);
  level->paths[2] = create_path(30, 12, 9, false);

  Player *player = create_player(11, 11, '@');

  render_level(level);
  render_player(player);

  getch();

  // NOTE: temporary code to handle player movement
  update_player_coordinates(player, player->x + 1, player->y);
  render_level(level);
  render_player(player);

  getch();

  destroy_level(level);
  destroy_player(player);

  endwin();

  return 0;
}
