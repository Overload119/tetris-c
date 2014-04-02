#include "cell.h"

Cell::Cell() {
  x = -1;
  y = -1;
  active = false;
  c = ' ';
}

int Cell::getColor() {
  int color;
  if (c == 'S') {
    color = Xwindow::Blue;
  } else if (c == 'Z') {
    color = Xwindow::Red;
  } else if (c == 'J') {
    color = Xwindow::Yellow;
  } else if (c == 'L') {
    color = Xwindow::Green;
  } else if (c == 'I') {
    color = Xwindow::Brown;
  } else if (c == 'O') {
    color = Xwindow::Cyan;
  } else {
    color = Xwindow::Orange;
  }
  return color;
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
  c = ' ';
}

void Cell::turnOn(){
  active = true;
}

void Cell::turnOn(char c) {
  this->c = c;
  active = true;
}

bool Cell::isActive(){
  return active;
}
