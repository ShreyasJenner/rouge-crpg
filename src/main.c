#include <ncurses.h>

#include "map.h"

int screenSetup() {
  initscr();
  noecho();
  refresh();

  return 0;
}

int main() {
  screenSetup();

  Level *level = create_level(2);
  level->rooms[0] = create_room(10, 10, 10, 5);
  level->rooms[1] = create_room(20, 20, 20, 4);

  render_level(level);

  getch();

  destroy_level(level);

  endwin();

  return 0;
}
