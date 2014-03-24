#include "block.h"
#include <stdbool.h>

using namespace std;

Block::Block(char type){
  if (type == 'I'){
    cells[0] = getCellAt(0,3);
    cells[1] = getCellAt(1,3);
    cells[2] = getCellAt(2,3);
    cells[3] = getCellAt(3,3);
  }
}
