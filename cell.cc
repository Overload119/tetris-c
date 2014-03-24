#include "cell.h"

Cell::Cell(int x, int y): x(x), y(y), active(false){}

int Cell::getX(){
    return x;
}

int Cell::getY(){
    return y;
}

