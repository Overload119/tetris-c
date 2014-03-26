#include "cell.h"

Cell::Cell() {
  x = -1;
  y = -1;
  active = false;
  c = ' ';
}

void Cell::setPosition(int x, int y) {
  this->x = x;
  this->y = y;
}

char Cell::getChar() const {
  return c;
}

int Cell::getX() const {
  return x;
}

int Cell::getY() const {
  return y;
}

void Cell::turnOff(){
  active = false;
}

void Cell::turnOn(){
  active = true;
}

bool Cell::isActive(){
  if (active == true){
    return true;
  } else {
    return false;
  }
}
