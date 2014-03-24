#include "cell.h"

Cell::Cell(int x, int y): x(x), y(y), active(false){}

int Cell::getX(Cell *current){
    return x;
}

int Cell::getY(Cell *current){
    return y;
}

