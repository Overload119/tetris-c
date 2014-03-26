#include "block.h"
#include <stdbool.h>

using namespace std;

Block::Block(char type, Grid *grid):grid(grid), type(type) {
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
    cells[2] = grid->getCellAt(0,4);
    cells[1] = grid->getCellAt(1,3);
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

  for (int i = 0; i < 4; i++) {
    cells[i]->turnOn( type );
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

bool Block::moveDown() {
  int newX[4];
  int newY[4];
  Cell *tempCell;
  for (int i = 0; i < 4; ++i) { //checks if cell below is already true
    newX[i] = cells[i]->getX();
    newY[i] = cells[i]->getY() + 1;
    tempCell = grid->getCellAt(newX[i], newY[i]);

    bool cellBelowIsActive = tempCell->isActive();
    bool cellBelowIsInSelf = false;
    for (int j = 0; j < 4; j++) {
      if (tempCell == cells[j]) {
        cellBelowIsInSelf = true;
      }
    }

    if (cellBelowIsActive && !cellBelowIsInSelf) {
      return true;
    }
  }

  // Turn of the cells for the block since
  // the cells are about to be updated
  for (int i = 0; i < 4; i++) {
    cells[i]->turnOff();
  }

  // Update and turn on all the new cell positions
  for (int i = 0; i < 4; ++i) {
    cells[i] = grid->getCellAt(newX[i], newY[i]);
    cells[i]->turnOn(type);
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


