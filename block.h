#ifndef __BLOCK_H__
#define __BLOCK_H__
#include "grid.h"

class Block{
  Cell *cells[4];
  Grid *grid;
public:
  void clockwise();
  void counterClockwise();
  void moveLeft();
  void moveRight();
  bool moveDown();
  void drop();
  Block(char type, Grid *grid);
};

#endif

