#include "level3.h"

using namespace std;

Level3::Level3(Grid* grid):Level(grid) {
  generateBlock();
}

Block* Level3::createBlock() {
  Block *b = new Block(nextBlockType, grid);
  generateBlock();
  return b;
}

void Level3::generateBlock() {
  int n = getRandomNumber(9); // Returns a number from 0 to 8

  // There are 7 different kinds of blocks
  // There is an equal chance to get any of the blocks
  if (n == 1 || n == 2) {
    nextBlockType = 'S';
  } else if (n == 3 || n == 4) {
    nextBlockType = 'Z';
  } else if (n == 5) {
    nextBlockType = 'J';
  } else if (n == 6) {
    nextBlockType = 'L';
  } else if (n == 7) {
    nextBlockType = 'I';
  } else if (n == 8) {
    nextBlockType = 'O';
  } else {
    nextBlockType = 'T';
  }
}
