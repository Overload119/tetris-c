#ifndef __GRID_H__
#define __GRID_H__
#include <iostream>
#include "cell.h"

enum { ROWS = 18, COLUMNS = 15 };
class Grid {
  Cell** cells;
  public:
    Grid();
    void clear();
    int checkAndClearRows();
    Cell* getCellAt(int x, int y);
    friend std::ostream &operator << (std::ostream &out, const Grid &v);
};

#endif
