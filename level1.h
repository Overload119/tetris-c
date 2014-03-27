#ifndef __LEVEL_1_H__
#define __LEVEL_1_H__
#include "level.h"

class Level1 : public Level {
  public:
    Level1(Grid* grid);
    void setSeed(int n);
    Block* createBlock();
};

#endif
