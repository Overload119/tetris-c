#ifndef __LEVEL_H__
#define __LEVEL_H__
#include <cstdlib.h>
#include "block.h"
#include "grid.h"

class Level {
  protected:
    int seed;
    Grid* grid;
  public:
    void setSeed(int n);
    void setGrid(Grid* grid);
    virtual Block* produceBlock() = 0;
};

#endif
