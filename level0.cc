#include "level0.h"

using namespace std;

Level0::Level0(Grid* grid) {
  setGrid(grid);
}

Level0::~Level0() {
  delete input;
}

Block* Level0::createBlock() {
  // Read the next kind of block to produce
  char blockType;
  input >> blockType;

  Block *b = new Block(blockType, grid);
  return b;
}

void Level0::readFromFile(string path) {
  input = new ifstream(path.c_str());
}
