#include "level1.h"

using namespace std;

Level1::Level1(Grid* grid):Level(grid) {
  generateBlock();
}

Block* Level1::createBlock() {
  Block *b = new Block(nextBlockType, grid);
  generateBlock();
  return b;
}

void Level1::generateBlock() {
  int n = getRandomNumber(12); // Returns a number from 0 to 11

  // There are 7 different kinds of blocks
  // 1 / 12 chance for S or Z
  // 2 / 12 chance for other blocks
  if (n == 0) {
    nextBlockType = 'S';
  } else if (n == 1) {
    nextBlockType = 'Z';
  } else if (n == 2 || n == 3) {
    nextBlockType = 'J';
  } else if (n == 4 || n == 5) {
    nextBlockType = 'L';
  } else if (n == 6 || n == 7) {
    nextBlockType = 'I';
  } else if (n == 8 || n == 9) {
    nextBlockType = 'O';
  } else {
    nextBlockType = 'T';
  }
}
