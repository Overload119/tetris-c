#ifndef __LEVEL_1_H__
#define __LEVEL_1_H__
#include "level.h"

class Level1 : public Level {
  void generateBlock();
  public:
    Level1(Grid* grid);
    Block* createBlock();
};

#endif
