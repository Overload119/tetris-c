#ifndef __CELL_H__
#define __CELL_H__

class Cell {
  int x,y;
  bool active;
  char c;
public:
    Cell(int x, int y);
    void draw(); //only needed for graphical interface, not text display
    int getX();
    int getY();
};

#endif