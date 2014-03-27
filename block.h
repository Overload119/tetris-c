#ifndef __BLOCK_H__
#define __BLOCK_H__
#include "grid.h"

class Block{
  Cell *cells[4];
  Grid *grid;
  char type;
public:
  void clockwise();
  void counterClockwise();
  bool moveLeft();
  bool moveRight();
  bool moveDown();
  void drop();
  bool update(int x, int y);
  Block(char type, Grid *grid);
};

#endif

