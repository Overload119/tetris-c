#ifndef __BLOCK_H__
#define __BLOCK_H__
#include "grid.h"

class Block{
  Cell *cells[4];
  Grid *grid;
  char type;
  int rotationPosition;
  bool validState;
public:
  void clockwise();
  bool counterClockwise();
  bool moveLeft();
  bool moveRight();
  bool moveDown();
  void drop();
  bool isCellValid(int x, int y);
  bool isValid();
  char getType();
  int getColor();
  Block(char type, Grid *grid);
};

#endif

