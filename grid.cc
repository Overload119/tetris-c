#include "grid.h"

using namespace std;

Grid::~Grid() {
  for (int i = 0; i < COLUMNS; i++) {
    delete [] cells[i];
  }
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
  if ((x < 0) || (x > 9)) {
    return NULL;
  } else if ((y < 0) || (y > 17)) {
    return NULL;
  } else {
    return &cells[x][y];
  }
}

void Grid::clear() {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLUMNS; j++) {
      cells[j][i].turnOff();
    }
  }
}

void Grid::render(Xwindow &w) {
  // Refresh the game screen by painting it all black before filling in individual cells
  w.fillRectangle(0, 0, CELL_WIDTH * COLUMNS, CELL_HEIGHT * ROWS, Xwindow::Black);

  for (int i = 3; i < ROWS; i++) {
    for (int j = 0; j < COLUMNS; j++) {
      int color = cells[j][i].getColor();
      if (cells[j][i].isActive()) {
        w.fillRectangle(j * CELL_WIDTH, (i-3) * CELL_HEIGHT, CELL_WIDTH, CELL_HEIGHT, color);
      } else {
        w.fillRectangle(j * CELL_WIDTH, (i-3) * CELL_HEIGHT, CELL_WIDTH, CELL_HEIGHT, Xwindow::Black);
      }
    }
  }
}

// This method will check and clear any rows that are completely filled
// It returns the number of rows it cleared
int Grid::checkAndClearRows() {
  int rowsToClear = 0;
  int lastRowToClear = 0;
  for (int i = 3; i < ROWS; i++) {
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
      lastRowToClear = i;
    }
  }

  if (rowsToClear > 0) {
    // If we removed rows then shift all cells down until the bottom row has at least 1 active cell
    for (int k = 0; k < rowsToClear; k++) {
      // Start from the row below the last row that was cleared.
      // Check the row above, and bring the values of the cells down
      // Do this `rowsToClear` times
      for (int i = lastRowToClear; i > 2; i--) {
        for (int j = 0; j < COLUMNS; j++) {
          if (i-1 == 2) {
            // Don't look at the value directly above the first "visible" row
            cells[j][i].turnOff();
          } else {
            if (cells[j][i - 1].isActive()) {
              cells[j][i].turnOn( cells[j][i-1].getChar() );
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
  // Print the top border
  for (int i = 0; i < COLUMNS; i++) {
    cout << "-";
  }
  cout << endl;

  // The first 3 rows are reserved.
  for (int i = 3; i < ROWS; i++) {
    for (int j = 0; j < COLUMNS; j++) {
      char c = g.cells[j][i].getChar();
      if (g.cells[j][i].isActive()) {
        cout << c;
      } else {
        cout << " "; // A blank spot for spacing
      }
    }
    cout << endl;
  }

  // Print the bottom border
  for (int i = 0; i < COLUMNS; i++) {
    cout << "-";
  }
  cout << endl;
  return out;
}
