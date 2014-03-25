#ifndef __LEVEL_H__
#define __LEVEL_H__
#include <cstdlib.h>
#include "block.h"
#include "grid.h"

class Level {
  int getRandomNumber();
  protected:
    Grid* grid;
  public:
    void setSeed(int n);
    void setGrid(Grid* grid);
    virtual ~Level();
    virtual Block* createBlock() = 0;
};

#endif
