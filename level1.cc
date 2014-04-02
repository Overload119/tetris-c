#include "level1.h"

using namespace std;

Level1::Level1(Grid* grid):Level(grid) {}

Block* Level1::createBlock() {
  int n = getRandomNumber(12); // Returns a number from 0 to 11
  char blockType;

  // There are 7 different kinds of blocks
  // 1 / 12 chance for S or Z
  // 2 / 12 chance for other blocks
  if (n == 0) {
    blockType = 'S';
  } else if (n == 1) {
    blockType = 'Z';
  } else if (n == 2 || n == 3) {
    blockType = 'J';
  } else if (n == 4 || n == 5) {
    blockType = 'L';
  } else if (n == 6 || n == 7) {
    blockType = 'I';
  } else if (n == 8 || n == 9) {
    blockType = 'O';
  } else {
    blockType = 'T';
  }

  Block *b = new Block(blockType, grid);
  return b;
}
