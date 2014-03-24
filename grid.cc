#include "grid.h"

Grid::Grid() {
  // Cells should already be initialized at this point.
}

Cell* Grid::getCellAt(int x, int y) {
  return cells[x][y];
}

void Grid::clear() {
  for (int i = 0; i < 18; i++) {
    for (int j = 0; j < 15; j++) {
      cells[i][j].turnOff();
    }
  }
}

void Grid::clearLines() {
}
