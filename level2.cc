#include "level2.h"

using namespace std;

Level2::Level2(Grid* grid):Level(grid) {
  generateBlock();
}

Block* Level2::createBlock() {
  Block *b = new Block(nextBlockType, grid);
  generateBlock();
  return b;
}

void Level2::generateBlock() {
  int n = getRandomNumber(7); // Returns a number from 0 to 6

  // There are 7 different kinds of blocks
  // There is an equal chance to get any of the blocks
  if (n == 1) {
    nextBlockType = 'S';
  } else if (n == 2) {
    nextBlockType = 'Z';
  } else if (n == 3) {
    nextBlockType = 'J';
  } else if (n == 4) {
    nextBlockType = 'L';
  } else if (n == 5) {
    nextBlockType = 'I';
  } else if (n == 6) {
    nextBlockType = 'O';
  } else {
    nextBlockType = 'T';
  }
}
