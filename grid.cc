#include "grid.h"

using namespace std;

Grid::~Grid() {
  // TODO
}

Grid::Grid() {
  cells = new Cell*[COLUMNS];
  for (int i = 0; i < COLUMNS; i++) {
    cells[i] = new Cell[ROWS];
    for (int j = 0; j < ROWS; j++) {
      cells[i][j].setPosition(i, j);
    }
  }
}

Cell* Grid::getCellAt(int x, int y) {
  return &cells[x][y];
}

void Grid::clear() {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLUMNS; j++) {
      cells[j][i].turnOff();
    }
  }
}

// This method will check and clear any rows that are completely filled
// It returns the number of rows it cleared
int Grid::checkAndClearRows() {
  int rowsToClear = 0;
  for (int i = 0; i < ROWS; i++) {
    // Start off with assumption that the row is filled
    bool isRowFilled = true;
    for (int j = 0; j < COLUMNS; j++) {
      if (!cells[j][i].isActive()) {
        // Discovered a cell that is not filled
        // so this row is not filled
        isRowFilled = false;
        break;
      }
    }
    // If the row we just iterated across is filled, then clear it
    if (isRowFilled) {
      rowsToClear++;
      // Go through each cell in this row and turn it off
      for (int j = 0; j < COLUMNS; j++) {
        cells[j][i].turnOff();
      }
    }
  }

  if (rowsToClear > 0) {
    // If we removed rows then shift all cells down until the bottom row has at least 1 active cell
    for (int k = 0; k < rowsToClear; k++) {
      // Start from the bottom row, check the row above, and bring the values of the cells down
      // Do this `rowsToClear` times
      for (int i = ROWS - 1; i > 2; i--) {
        for (int j = 0; j < COLUMNS; j++) {
          if (i-1 == 2) {
            // Don't look at the value directly above the first "visible" row
            cells[j][i].turnOff();
          } else {
            if (cells[j][i - 1].isActive()) {
              cells[j][i].turnOn();
            } else {
              cells[j][i].turnOff();
            }
          }
        }
      }
    }
  }

  return rowsToClear;
}

ostream& operator<<(ostream &out, const Grid &g) {
  // The first 3 rows are reserved.
  for (int i = 2; i < ROWS; i++) {
    for (int j = 0; j < COLUMNS; j++) {
      char c = g.cells[i][j].getChar();
      if (g.cells[i][j].isActive()) {
        cout << c;
      } else {
        cout << " "; // A blank spot for spacing
      }
    }
    cout << endl;
  }
  return out;
}
