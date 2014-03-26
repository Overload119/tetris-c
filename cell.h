#ifndef __CELL_H__
#define __CELL_H__

class Cell {
  int x,y;
  bool active;
  char c;
public:
    Cell();
    void draw(); //only needed for graphical interface, not text display
    int getX() const;
    int getY() const;
    char getChar() const;
    void setPosition(int x, int y);
    void turnOff();
    void turnOn();
    bool isActive();
};

#endif
