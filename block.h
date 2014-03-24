#ifndef __BLOCK_H__
#define __BLOCK_H__
#include "cell.h"
#include <stdbool.h>

class block{
  cell *cells[4];
public:
  void clockwise();
  void counterClockwise();
  void moveLeft();
  void moveRight();
  bool isStopped();
  void drop();
}
