#ifndef __LEVEL_3_H__
#define __LEVEL_3_H__
#include "level.h"

class Level3 : public Level {
  void generateBlock();
  public:
    Level3(Grid* grid);
    Block* createBlock();
};

#endif
