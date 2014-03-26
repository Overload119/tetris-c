#ifndef __LEVEL_0_H__
#define __LEVEL_0_H__
#include <string>
#include <iostream>
#include <fstream>
#include "level.h"

class Level0 : public Level {
  std::istream *input;
  public:
    Level0(Grid* grid);
    ~Level0();
    void setSeed(int n);
    void readFromFile(std::string path);
    Block* createBlock();
};

#endif
