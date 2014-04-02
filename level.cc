#include "level.h"

Level::~Level() { }

Level::Level(Grid* g) {
  grid = g;
}

int Level::getRandomNumber(int max) {
  return rand() % max; // 0 to max
}

char Level::getNextBlockType() {
  return nextBlockType;
}

void Level::setSeed(int n) {
  srand(n);
}
