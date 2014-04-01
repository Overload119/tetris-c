#include "level3.h"

using namespace std;

Level3::Level3(Grid* grid):Level(grid) { }

Block* Level3::createBlock() {
  int n = getRandomNumber(9); // Returns a number from 0 to 8
  char blockType;

  // There are 7 different kinds of blocks
  // There is an equal chance to get any of the blocks
  if (n == 1 || n == 2) {
    blockType = 'S';
  } else if (n == 3 || n == 4) {
    blockType = 'Z';
  } else if (n == 5) {
    blockType = 'J';
  } else if (n == 6) {
    blockType = 'L';
  } else if (n == 7) {
    blockType = 'I';
  } else if (n == 8) {
    blockType = 'O';
  } else {
    blockType = 'T';
  }

  Block *b = new Block(blockType, grid);
  return b;
}
