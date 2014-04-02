#ifndef __GRID_H__
#define __GRID_H__
#include <iostream>
#include "window.h"
#include "cell.h"

enum { ROWS = 18, COLUMNS = 10, SCREEN_WIDTH = 320, SCREEN_HEIGHT = 650, FONT_SIZE = 18 };
class Grid {
  Cell** cells;
  public:
    Grid();
    ~Grid();
    void clear();
    void render(Xwindow &w);
    int checkAndClearRows();
    Cell* getCellAt(int x, int y);
    friend std::ostream& operator << (std::ostream &out, const Grid &v);
};

#endif
