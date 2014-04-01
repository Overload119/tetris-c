#ifndef __LEVEL_H__
#define __LEVEL_H__
#include <cstdlib>
#include "block.h"
#include "grid.h"

class Level {
  protected:
    Grid* grid;
    int getRandomNumber(int max);
  public:
    void setSeed(int n);
    Level(Grid* grid);
    virtual ~Level() = 0;
    virtual Block* createBlock() = 0;
};

#endif
