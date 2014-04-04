#include "level0.h"

using namespace std;

Level0::Level0(Grid* grid):Level(grid) {}

Level0::~Level0() {
  delete filePath;
  delete input;
}

void Level0::generateBlock() {
  // Read the next kind of block to produce
  char blockType = ' ';
  while (isspace(blockType)) {
    if (input->eof()) {
      delete input;
      input = new ifstream(filePath);
    }
    input->get( blockType );
  }

  nextBlockType = blockType;
}

Block* Level0::createBlock() {
  Block *b = new Block(nextBlockType, grid);
  generateBlock();
  return b;
}

void Level0::readFromFile(string path) {
  filePath = new char [path.length() + 1];
  strcpy(filePath, path.c_str());

  input = new ifstream(filePath);
  generateBlock();
}

