#include <ncurses.h>

#include "map.h"

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

  render_level(level);

  getch();

  destroy_level(level);

  endwin();

  return 0;
}
