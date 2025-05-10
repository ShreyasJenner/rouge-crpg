#include <ncurses.h>
#include <stdlib.h>

#include "input.h"

// Function to create input handling module
InputHandling *create_InputHandling() {
  InputHandling *ih = malloc(sizeof(InputHandling));

  ih->key = ' ';

  return ih;
}

// Function to store the current key press
void store_key_press(InputHandling *ih, char key) { ih->key = key; }

// Function to destroy input handling module
void destroy_InputHandling(InputHandling *ih) { free(ih); }
