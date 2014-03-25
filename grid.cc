#include "grid.h"

using namespace std;

Grid::Grid() {
  // Cells should already be initialized at this point.
}

Cell* Grid::getCellAt(int x, int y) {
  return cells[x][y];
}

void Grid::clear() {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLUMNS; j++) {
      cells[i][j].turnOff();
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
      if (!cells[i][j]->isActive()) {
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
        cells[i][j]->turnOff();
      }
    }
  }
  return rowsToClear;
}

ostream &operator<<(std::ostream &out, const Grid &g) {
  // The first 3 rows are reserved.
  for (int i = 2; i < ROWS; i++) {
    for (int j = 0; j < COLUMNS; j++) {
      char c = g.cells[i][j]->getChar();
      if (cells[i][j]->isActive()) {
        cout << c;
      } else {
        cout << " "; // A blank spot for spacing
      }
    }
    cout << endl;
  }
  return out;
}
