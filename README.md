# rouge-crpg

A rouge-like game creator written in C
The eventual goal is to be able to build a simple rouge like game using this project

## Screenshots

[Sample Photo](./assets/sample.png)

## Setup

- Run ```make``` command to compile the project
- Run ```bin/rouge``` to run the program
- Run ```make clean``` to remove all object and compiled files

## Directory structure

- src: contains code files
- include: contains header files
- obj: object files that are created
- bin: compiled program is stored here

## To-Do

- [x] Create player
- [x] Player movement
  - [x] Input Handling
  - [x] Legal movements only
- [ ] scrollable maps (maps that are larger than the screen and necessary parts are rendered as needed)
- [ ] Obstacles
- [ ] Levels
- [ ] Resources
