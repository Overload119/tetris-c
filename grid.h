#ifndef __GRID_H__
#define __GRID_H__
#include <iostream>

enum { ROWS = 18, COLUMNS = 15 };
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
