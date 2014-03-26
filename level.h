#ifndef __LEVEL_H__
#define __LEVEL_H__
#include <cstdlib>
#include "block.h"
#include "grid.h"

class Level {
  int getRandomNumber(int max);
  protected:
    Grid* grid;
  public:
    void setSeed(int n);
    void setGrid(Grid* grid);
    virtual ~Level();
    virtual Block* createBlock() = 0;
};

#endif
