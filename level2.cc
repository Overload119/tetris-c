#include "level2.h"

using namespace std;

Level2::Level2(Grid* grid):Level(grid) { }

Block* Level2::createBlock() {
  int n = getRandomNumber(7); // Returns a number from 0 to 6
  char blockType;

  // There are 7 different kinds of blocks
  // There is an equal chance to get any of the blocks
  if (n == 1) {
    blockType = 'S';
  } else if (n == 2) {
    blockType = 'Z';
  } else if (n == 3) {
    blockType = 'J';
  } else if (n == 4) {
    blockType = 'L';
  } else if (n == 5) {
    blockType = 'I';
  } else if (n == 6) {
    blockType = 'O';
  } else {
    blockType = 'T';
  }

  Block *b = new Block(blockType, grid);
  return b;
}
