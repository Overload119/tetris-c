#ifndef __GRID_H__
#define __GRID_H__

class Grid {
  Cell cells[18][10];
  public:
    Grid();
    void clear();
    int clearLines();
    Cell* getCellAt(int x, int y);
};

#endif
