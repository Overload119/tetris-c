#include "level0.h"

Level0::Level0(Grid* grid) {
  setGrid(grid);
}

Level0::~Level0() {
}

Block* Level0::createBlock() {
}

void Level0::readFromFile(string path) {
  istream *input = new ifstream(path.c_str())

}
