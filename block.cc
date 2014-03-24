#include "block.h"
#include <stdbool.h>

using namespace std;

Block::Block(char type){
  if (type == 'I'){
    cells[0] = getCellAt(0,3);
    cells[1] = getCellAt(1,3);
    cells[2] = getCellAt(2,3);
    cells[3] = getCellAt(3,3);
  } else if (type == 'L'){
    cells[0] = getCellAt(0,4);
    cells[1] = getCellAt(1,4);
    cells[2] = getCellAt(2,4);
    cells[3] = getCellAt(2,3);
  } else if (type == 'O'){
    cells[0] = getCellAt(0,3);
    cells[1] = getCellAt(1,3);
    cells[2] = getCellAt(0,4);
    cells[3] = getCellAt(1,4);
  } else if (type == 'S'){
    cells[0] = getCellAt(0,4);
    cells[1] = getCellAt(1,4);
    cells[2] = getCellAt(1,3);
    cells[3] = getCellAt(2,3);
  } else if (type == 'Z'){
    cells[0] = getCellAt(0,3);
    cells[1] = getCellAt(1,3);
    cells[2] = getCellAt(1,4);
    cells[3] = getCellAt(2,4);
  }
}

void Block::moveRight(){ //what prints the cell?
  int newX[4];
  int newY[4];
  for (int i = 0; i < 3; ++i){
    newX[i] = cell[i]->getX() + 1;
    newY[i] = cell[i]->getY();
    cell[i] = getCellAt(newX, newY);
  }
}

void Block::moveLeft(){
  int newX[4];
  int newY[4];
  for (int i = 0; i < 3,)
}
