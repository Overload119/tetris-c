#include "block.h"
#include <stdbool.h>
#include <cmath>

#include <iostream>

using namespace std;

Block::Block(char type, Grid *grid):grid(grid), type(type) {
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
  } else if (type == 'T') {
    cells[0] = grid->getCellAt(0,3);
    cells[1] = grid->getCellAt(1,3);
    cells[2] = grid->getCellAt(2,3);
    cells[3] = grid->getCellAt(1,4);
  } else if (type == 'J') {
    cells[0] = grid->getCellAt(0,3);
    cells[1] = grid->getCellAt(0,4);
    cells[2] = grid->getCellAt(1,4);
    cells[3] = grid->getCellAt(2,4);
  }

  // Before turning on the cells we've associated with this block
  // Check if they were already turned on. If they are then this block
  // is in an invalid state.
  validState = true;
  rotationPosition = 0;
  for (int i = 0; i < 4; i++) {
    if (cells[i]->isActive()) {
      validState = false;
      break;
    }
  }

  if (validState) {
    for (int i = 0; i < 4; i++) {
      cells[i]->turnOn( type );
    }
  }
}

bool Block::isValid() {
  return validState;
}

bool Block::isCellValid(int x, int y){
  //checks if cell below is already true
  Cell *tempCell = grid->getCellAt(x, y);
  if (tempCell == NULL) {
    return true;
  }

  bool cellIsActive = tempCell->isActive();
  bool cellIsInSelf = false;
  for (int j = 0; j < 4; j++) {
    if (tempCell == cells[j]) {
      cellIsInSelf = true;
    }
  }

  if (cellIsActive && !cellIsInSelf) {
    return true;
  }

  return false;
}

char Block::getType() {
  return type;
}

// turns off new cell and points current cell to cell with x += 1
bool Block::moveRight(){
  int newX[4];
  int newY[4];
  bool answer;

  for (int i = 0; i < 4; ++i) {
    newX[i] = cells[i]->getX() + 1;
    newY[i] = cells[i]->getY();
    answer = isCellValid(newX[i], newY[i]);
    if (answer){
      return answer;
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

// turns off new cell and points current cell to cell with x -= 1
bool Block::moveLeft(){
  int newX[4];
  int newY[4];
  bool answer;

  for (int i = 0; i < 4; ++i) {

    newX[i] = cells[i]->getX() - 1;
    newY[i] = cells[i]->getY();
    answer = isCellValid(newX[i], newY[i]);
    if (answer){
      return answer;
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

bool Block::moveDown() {
  int newX[4];
  int newY[4];
  bool answer;

  for (int i = 0; i < 4; ++i) {
    newX[i] = cells[i]->getX();
    newY[i] = cells[i]->getY() + 1;
    answer = isCellValid(newX[i], newY[i]);
    if (answer){
      return answer;
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
void Block::drop() {
  while (true){
    if (moveDown()){
      break;
    }
  }
}

int Block::getColor() {
  int color;
  if (type == 'S') {
    color = Xwindow::Blue;
  } else if (type == 'Z') {
    color = Xwindow::Red;
  } else if (type == 'J') {
    color = Xwindow::Yellow;
  } else if (type == 'L') {
    color = Xwindow::Green;
  } else if (type == 'I') {
    color = Xwindow::Brown;
  } else if (type == 'O') {
    color = Xwindow::Cyan;
  } else {
    color = Xwindow::Orange;
  }
  return color;
}

void Block::counterClockwise() {
  int newX[4];
  int newY[4];
  char c = cells[1]->getChar();
    if (c == 'O'){
      return;
    } else if (c == 'I'){
      if ((rotationPosition % 2) == 0){
        newX[0] = cells[0]->getX();
        newY[0] = cells[0]->getY();
        newX[1] = cells[1]->getX() -1;
        newY[1] = cells[1]->getY() -1;
        newX[2] = cells[2]->getX() -2;
        newY[2] = cells[2]->getY() -2;
        newX[3] = cells[3]->getX() -3;
        newY[3] = cells[3]->getY() -3;
      } else {
        newX[0] = cells[0]->getX();
        newY[0] = cells[0]->getY();
        newX[1] = cells[1]->getX() +1;
        newY[1] = cells[1]->getY() +1;
        newX[2] = cells[2]->getX() +2;
        newY[2] = cells[2]->getY() +2;
        newX[3] = cells[3]->getX() +3;
        newY[3] = cells[3]->getY() +3;
      }
    } else if (c == 'Z'){
      if ((rotationPosition % 2) == 0){
        newX[0] = cells[0]->getX();
        newY[0] = cells[0]->getY()+1;
        newX[1] = cells[1]->getX()-1;
        newY[1] = cells[1]->getY();
        newX[2] = cells[2]->getX();
        newY[2] = cells[2]->getY()-1;
        newX[3] = cells[3]->getX()-1;
        newY[3] = cells[3]->getY()-2;
      } else {
        newX[0] = cells[0]->getX();
        newY[0] = cells[0]->getY()-1;
        newX[1] = cells[1]->getX()+1;
        newY[1] = cells[1]->getY();
        newX[2] = cells[2]->getX();
        newY[2] = cells[2]->getY()+1;
        newX[3] = cells[3]->getX()+1;
        newY[3] = cells[3]->getY()+2;
      }
    } else if (c == 'L'){
      if (rotationPosition == 0){
        newX[0] = cells[0]->getX()+1;
        newY[0] = cells[0]->getY();
        newX[1] = cells[1]->getX();
        newY[1] = cells[1]->getY()-1;
        newX[2] = cells[2]->getX()-1;
        newY[2] = cells[2]->getY()-2;
        newX[3] = cells[3]->getX()-2;
        newY[3] = cells[3]->getY()-1;
      } else if (rotationPosition == 1){
        newX[0] = cells[0]->getX()+1;
        newY[0] = cells[0]->getY()-1;
        newX[1] = cells[1]->getX();
        newY[1] = cells[1]->getY();
        newX[2] = cells[2]->getX()-1;
        newY[2] = cells[2]->getY()+1;
        newX[3] = cells[3]->getX();
        newY[3] = cells[3]->getY()+2;
      } else if (rotationPosition == 2){
        newX[0] = cells[0]->getX()-2;
        newY[0] = cells[0]->getY()-1;
        newX[1] = cells[1]->getX()-1;
        newY[1] = cells[1]->getY();
        newX[2] = cells[2]->getX();
        newY[2] = cells[2]->getY()+1;
        newX[3] = cells[3]->getX()+1;
        newY[3] = cells[3]->getY();
      } else if (rotationPosition == 3){
        newX[0] = cells[0]->getX();
        newY[0] = cells[0]->getY()+2;
        newX[1] = cells[1]->getX()+1;
        newY[1] = cells[1]->getY()+1;
        newX[2] = cells[2]->getX()+2;
        newY[2] = cells[2]->getY();
        newX[3] = cells[3]->getX()+1;
        newY[3] = cells[3]->getY()-1;
      }
    } else if (c == 'T'){
      if (rotationPosition == 0){
        newX[0] = cells[0]->getX();
        newY[0] = cells[0]->getY()+1;
        newX[1] = cells[1]->getX()-1;
        newY[1] = cells[1]->getY();
        newX[2] = cells[2]->getX()-2;
        newY[2] = cells[2]->getY()-1;
        newX[3] = cells[3]->getX();
        newY[3] = cells[3]->getY()-1;
      } else if (rotationPosition == 1) {
        newX[0] = cells[0]->getX()+2;
        newY[0] = cells[0]->getY();
        newX[1] = cells[1]->getX()+1;
        newY[1] = cells[1]->getY()+1;
        newX[2] = cells[2]->getX();
        newY[2] = cells[2]->getY()+2;
        newX[3] = cells[3]->getX();
        newY[3] = cells[3]->getY();
      } else if (rotationPosition == 2) {
        newX[0] = cells[0]->getX()-1;
        newY[0] = cells[0]->getY()-2;
        newX[1] = cells[1]->getX();
        newY[1] = cells[1]->getY()-1;
        newX[2] = cells[2]->getX()+1;
        newY[2] = cells[2]->getY();
        newX[3] = cells[3]->getX()-1;
        newY[3] = cells[3]->getY();
      } else if (rotationPosition == 3) {
        newX[0] = cells[0]->getX()-1;
        newY[0] = cells[0]->getY()+1;
        newX[1] = cells[1]->getX();
        newY[1] = cells[1]->getY();
        newX[2] = cells[2]->getX()+1;
        newY[2] = cells[2]->getY()-1;
        newX[3] = cells[3]->getX()+1;
        newY[3] = cells[3]->getY()+1;
      }
    } else if (c == 'J'){
      if (rotationPosition == 0){
        newX[0] = cells[0]->getX();
        newY[0] = cells[0]->getY()+1;
        newX[1] = cells[1]->getX()+1;
        newY[1] = cells[1]->getY();
        newX[2] = cells[2]->getX();
        newY[2] = cells[2]->getY()-1;
        newX[3] = cells[3]->getX()-1;
        newY[3] = cells[3]->getY()-2;
      } else if (rotationPosition == 1) {
        newX[0] = cells[0]->getX()+2;
        newY[0] = cells[0]->getY();
        newX[1] = cells[1]->getX()+1;
        newY[1] = cells[1]->getY()-1;
        newX[2] = cells[2]->getX();
        newY[2] = cells[2]->getY();
        newX[3] = cells[3]->getX()-1;
        newY[3] = cells[3]->getY()+1;
      } else if (rotationPosition == 2) {
        newX[0] = cells[0]->getX()-1;
        newY[0] = cells[0]->getY()-2;
        newX[1] = cells[1]->getX()-2;
        newY[1] = cells[1]->getY()-1;
        newX[2] = cells[2]->getX()-1;
        newY[2] = cells[2]->getY();
        newX[3] = cells[3]->getX();
        newY[3] = cells[3]->getY()+1;
      } else if (rotationPosition == 3) {
        newX[0] = cells[0]->getX()-1;
        newY[0] = cells[0]->getY()+1;
        newX[1] = cells[1]->getX();
        newY[1] = cells[1]->getY()+2;
        newX[2] = cells[2]->getX()+1;
        newY[2] = cells[2]->getY()+1;
        newX[3] = cells[3]->getX()+2;
        newY[3] = cells[3]->getY();
      }
    } else if (c == 'S'){
      if (rotationPosition == 0){
        newX[0] = cells[0]->getX()+1;
        newY[0] = cells[0]->getY();
        newX[1] = cells[1]->getX();
        newY[1] = cells[1]->getY()-1;
        newX[2] = cells[2]->getX()-1;
        newY[2] = cells[2]->getY();
        newX[3] = cells[3]->getX()-2;
        newY[3] = cells[3]->getY()-1;
      } else if (rotationPosition == 1) {
        newX[0] = cells[0]->getX()+1;
        newY[0] = cells[0]->getY()-1;
        newX[1] = cells[1]->getX();
        newY[1] = cells[1]->getY();
        newX[2] = cells[2]->getX()+1;
        newY[2] = cells[2]->getY()+1;
        newX[3] = cells[3]->getX();
        newY[3] = cells[3]->getY()+2;
      } else if (rotationPosition == 2) {
        newX[0] = cells[0]->getX()-2;
        newY[0] = cells[0]->getY()-1;
        newX[1] = cells[1]->getX()-1;
        newY[1] = cells[1]->getY();
        newX[2] = cells[2]->getX();
        newY[2] = cells[2]->getY()-1;
        newX[3] = cells[3]->getX()+1;
        newY[3] = cells[3]->getY();
      } else if (rotationPosition == 3) {
        newX[0] = cells[0]->getX();
        newY[0] = cells[0]->getY()+2;
        newX[1] = cells[1]->getX()+1;
        newY[1] = cells[1]->getY()+1;
        newX[2] = cells[2]->getX();
        newY[2] = cells[2]->getY();
        newX[3] = cells[3]->getX()+1;
        newY[3] = cells[3]->getY()-1;
      }
    }

        rotationPosition += 1;
        rotationPosition = rotationPosition % 4;

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

}

void Block::clockwise() {
  for (int i = 0; i < 3; i++){
      counterClockwise();
  }
}


