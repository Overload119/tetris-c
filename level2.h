#ifndef __LEVEL_2_H__
#define __LEVEL_2_H__
#include "level.h"

class Level2 : public Level {
  void generateBlock();
  public:
    Level2(Grid* grid);
    Block* createBlock();
};

#endif
