#ifndef __GRID_H__
#define __GRID_H__
#define ROWS 18
#define COLUMNS 15
#include <iostream>

class Grid {
  Cell cells[18][10];
  public:
    Grid();
    void clear();
    int checkAndClearRows();
    Cell* getCellAt(int x, int y);
    friend std::ostream*operator << (std::ostream &out, const Vec &v);
};

#endif
