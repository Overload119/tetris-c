#include "block.h"
#include <stdbool.h>

using namespace std;

Block::Block(char type, Grid *grid):grid(grid){
  if (type == 'I'){
    cells[0] = grid->getCellAt(0,3);
    cells[1] = grid->getCellAt(1,3);
    cells[2] = grid->getCellAt(2,3);
    cells[3] = grid->getCellAt(3,3);
  } else if (type == 'L'){
    cells[0] = grid->getCellAt(0,4);
    cells[1] = grid->getCellAt(1,4);
    cells[2] = grid->getCellAt(2,4);
    cells[3] = grid->getCellAt(2,3);
  } else if (type == 'O'){
    cells[0] = grid->getCellAt(0,3);
    cells[1] = grid->getCellAt(1,3);
    cells[2] = grid->getCellAt(0,4);
    cells[3] = grid->getCellAt(1,4);
  } else if (type == 'S'){
    cells[0] = grid->getCellAt(0,4);
    cells[1] = grid->getCellAt(1,4);
    cells[2] = grid->getCellAt(1,3);
    cells[3] = grid->getCellAt(2,3);
  } else if (type == 'Z'){
    cells[0] = grid->getCellAt(0,3);
    cells[1] = grid->getCellAt(1,3);
    cells[2] = grid->getCellAt(1,4);
    cells[3] = grid->getCellAt(2,4);
  }
}

// turns off new cell and points current cell to cell with x += 1
void Block::moveRight(){
  int newX[4];
  int newY[4];
  for (int i = 0; i < 3; ++i){
    cell[i]->turnOff();
    newX[i] = cell[i]->getX() + 1;
    newY[i] = cell[i]->getY();
    cell[i] = grid->getCellAt(newX, newY);
    cell[i]->turnOn();
  }
}

// turns off new cell and points current cell to cell with x -= 1
void Block::moveLeft(){
  int newX[4];
  int newY[4];
  for (int i = 0; i < 3; ++i){
    cell[i]->turnOff();
    newX[i] = cell[i]->getX() - 1;
    newY[i] = cell[i]->getY();
    cell[i] = grid->getCellAt(newX, newY);
    cell[i]->turnOn();
  }
}

//turns off current cells and points new cells with y -= 1
bool Block::moveDown(){
  int newY[4];
  int newX[4];
  Cell *tempCell;
  for (int i = 0; i < 3; ++i){ //checks if cell below is already true
    newX[i] = cell[i]->getX();
    newY[i] = cell[i]->getY() - 1;
    tempCell = grid->getCellAt(newX, newY);
    for (int j = 0; j < 3; ++j){
      if (tempCell != cell[j]){
        if (tempCell->isActive()){
            return true;
        }
      }
    }
  }
  //if it makes it through above loop, sets cell to new (x,y);
  for (int i = 0; i < 3; ++i){
    cell[i]->turnOff();
    cell[i] = grid->getCellAt(newX, newY);
    cell[i]->turnOn;
  }
  return false;
}

// calls moveDown() until it returns false,
//which indicates it can't move further
void Block::drop(){
  while (true){
    if (moveDown()){
      break;
    }
  }
}


