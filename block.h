#ifndef __BLOCK_H__
#define __BLOCK_H__
#include "cell.h"
#include <stdbool.h>

class block{
  Cell *cells[4];
  Grid *grid;
public:
  void clockwise();
  void counterClockwise();
  void moveLeft();
  void moveRight();
  void moveDown();
  bool isStopped();
  void drop();
  Block(char type, Grid *grid);
};

#endif

