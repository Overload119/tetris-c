#include "level.h"

void Level::setGrid(Grid* g) {
  grid = g;
}

int Level::getRandomNumber(int max) {
  return rand() % 100; // 0 to 99
}

void Level::setSeed(int n) {
  srand(n);
}
