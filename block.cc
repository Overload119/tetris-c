#include "block.h"
#include <stdbool.h>

using namespace std;

Block::Block(char type, Grid *grid):grid(grid){
  cout << "creating block of type: " << type << endl;
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
  for (int i = 0; i < 4; ++i){
    cells[i]->turnOff();
    newX[i] = cells[i]->getX() + 1;
    newY[i] = cells[i]->getY();
    cells[i] = grid->getCellAt(newX[i], newY[i]);
    cells[i]->turnOn();
  }
}

// turns off new cell and points current cell to cell with x -= 1
void Block::moveLeft(){
  int newX[4];
  int newY[4];
  for (int i = 0; i < 4; ++i){
    cells[i]->turnOff();
    newX[i] = cells[i]->getX() - 1;
    newY[i] = cells[i]->getY();
    cells[i] = grid->getCellAt(newX[i], newY[i]);
    cells[i]->turnOn();
  }
}

//turns off current cells and points new cells with y -= 1
bool Block::moveDown(){
  int newY[4];
  int newX[4];
  Cell *tempCell;
  for (int i = 0; i < 4; ++i){ //checks if cell below is already true
    newX[i] = cells[i]->getX();
    newY[i] = cells[i]->getY() + 1;
    tempCell = grid->getCellAt(newX[i], newY[i]);
    for (int j = 0; j < 4; ++j){
      if (tempCell != cells[j]){
        if (tempCell->isActive()){
            return true;
        }
      }
    }
  }
  //if it makes it through above loop, sets cell to new (x,y);
  for (int i = 0; i < 4; ++i){
    cells[i]->turnOff();
    cells[i] = grid->getCellAt(newX[i], newY[i]);
    cout << "turn on a cell" << endl;
    cells[i]->turnOn();
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


