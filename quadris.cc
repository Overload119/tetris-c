#include <string>
#include <iostream>
#include <sstream>
#include "grid.h"
#include "level0.h"
#include "level1.h"
#include "level2.h"
#include "level3.h"

using namespace std;

// Helper function to read a command
bool isLeft(const string &input) {
  return (input == "left" || input == "lef");
}

bool isRight(const string &input) {
  return (input == "ri" || input == "rig" || input == "righ" || input == "right");
}

bool isDown(const string &input) {
  return (input == "do" || input == "dow" || input == "down");
}

bool isDrop(const string &input) {
  return (input == "dr" || input == "dro" || input == "drop");
}

bool isRestart(const string &input) {
  return (input == "re" || input == "res" || input == "rest" || input == "resta" || input == "restar" || input == "restart");
}

bool isLevelUp(const string &input) {
  return (input == "levelu" || input == "levelup");
}

bool isLevelDown(const string &input) {
  return (input == "leveld" || input == "leveldo" || input == "leveldow" || input == "leveldown");
}

bool isClockwise(const string &input) {
  return (input == "cl" || input == "clo" || input == "cloc" || input == "clock" || input == "clockw" || input == "clockwi" || input == "clockwis" || input == "clockwise");
}

bool isCounterClockwise(const string &input) {
  return (input == "co" || input == "cou" || input == "coun" || input == "count" || input == "counte" || input == "counter" || input == "counterc" || input == "countercl" || input == "counterclo" || input == "countercloc" || input == "counterclock" || input == "counterclockw" || input == "counterclockwi" || input == "counterclockwis" || input == "counterclockwise");
}

void printBlock(char blockType) {
  if (blockType == 'I') {
    cout << endl;
    cout << "IIII" << endl;
  } else if (blockType == 'J') {
    cout << "J" << endl;
    cout << "JJJ" << endl;
  } else if (blockType == 'O') {
    cout << "OO" << endl;
    cout << "OO" << endl;
  } else if (blockType == 'L') {
    cout << "  L" << endl;
    cout << "LLL" << endl;
  } else if (blockType == 'S') {
    cout << " SS" << endl;
    cout << "SS" << endl;
  } else if (blockType == 'Z') {
    cout << "ZZ" << endl;
    cout << " ZZ" << endl;
  } else if (blockType == 'T') {
    cout << "TTT" << endl;
    cout << " T " << endl;
  }
}


void renderBlock(char blockType, Xwindow* w) {
  int color;
  if (blockType == 'S') {
    color = Xwindow::Blue;
  } else if (blockType == 'Z') {
    color = Xwindow::Red;
  } else if (blockType == 'J') {
    color = Xwindow::Yellow;
  } else if (blockType == 'L') {
    color = Xwindow::Green;
  } else if (blockType == 'I') {
    color = Xwindow::Brown;
  } else if (blockType == 'O') {
    color = Xwindow::Cyan;
  } else {
    color = Xwindow::Orange;
  }

  int yOffset = 480 + (FONT_SIZE*5);
  w->drawString(0, 480 + (FONT_SIZE*4), "Next block:", Xwindow::White);

  if (blockType == 'I') {
    w->fillRectangle(0, yOffset, CELL_WIDTH, CELL_HEIGHT, color);
    w->fillRectangle(32, yOffset, CELL_WIDTH, CELL_HEIGHT, color);
    w->fillRectangle(64, yOffset, CELL_WIDTH, CELL_HEIGHT, color);
    w->fillRectangle(96, yOffset, CELL_WIDTH, CELL_HEIGHT, color);
  } else if (blockType == 'J') {
    w->fillRectangle(0, yOffset, CELL_WIDTH, CELL_HEIGHT, color);
    w->fillRectangle(0, yOffset + CELL_HEIGHT, CELL_WIDTH, CELL_HEIGHT, color);
    w->fillRectangle(32, yOffset + CELL_HEIGHT, CELL_WIDTH, CELL_HEIGHT, color);
    w->fillRectangle(64, yOffset + CELL_HEIGHT, CELL_WIDTH, CELL_HEIGHT, color);
  } else if (blockType == 'O') {
    w->fillRectangle(0, yOffset, CELL_WIDTH, CELL_HEIGHT, color);
    w->fillRectangle(32, yOffset, CELL_WIDTH, CELL_HEIGHT, color);
    w->fillRectangle(0, yOffset + CELL_HEIGHT, CELL_WIDTH, CELL_HEIGHT, color);
    w->fillRectangle(32, yOffset + CELL_HEIGHT, CELL_WIDTH, CELL_HEIGHT, color);
  } else if (blockType == 'L') {
    w->fillRectangle(64, yOffset, CELL_WIDTH, CELL_HEIGHT, color);
    w->fillRectangle(0, yOffset + CELL_HEIGHT, CELL_WIDTH, CELL_HEIGHT, color);
    w->fillRectangle(32, yOffset + CELL_HEIGHT, CELL_WIDTH, CELL_HEIGHT, color);
    w->fillRectangle(64, yOffset + CELL_HEIGHT, CELL_WIDTH, CELL_HEIGHT, color);
  } else if (blockType == 'S') {
    w->fillRectangle(32, yOffset, CELL_WIDTH, CELL_HEIGHT, color);
    w->fillRectangle(64, yOffset, CELL_WIDTH, CELL_HEIGHT, color);
    w->fillRectangle(0, yOffset + CELL_HEIGHT, CELL_WIDTH, CELL_HEIGHT, color);
    w->fillRectangle(32, yOffset + CELL_HEIGHT, CELL_WIDTH, CELL_HEIGHT, color);
  } else if (blockType == 'Z') {
    w->fillRectangle(0, yOffset, CELL_WIDTH, CELL_HEIGHT, color);
    w->fillRectangle(32, yOffset, CELL_WIDTH, CELL_HEIGHT, color);
    w->fillRectangle(32, yOffset + CELL_HEIGHT, CELL_WIDTH, CELL_HEIGHT, color);
    w->fillRectangle(64, yOffset + CELL_HEIGHT, CELL_WIDTH, CELL_HEIGHT, color);
  } else if (blockType == 'T') {
    w->fillRectangle(0, yOffset, CELL_WIDTH, CELL_HEIGHT, color);
    w->fillRectangle(32, yOffset, CELL_WIDTH, CELL_HEIGHT, color);
    w->fillRectangle(64, yOffset, CELL_WIDTH, CELL_HEIGHT, color);
    w->fillRectangle(32, yOffset + CELL_HEIGHT, CELL_WIDTH, CELL_HEIGHT, color);
  }
}

int main(int argc, char* argv[]) {
  // Read and parse the commandline arguments
  // Defaults
  bool textOnly         = false; // Set this to false by default
  int seed              = 1337;
  string scriptFilePath = "sequence.txt";
  int startLevel        = 0;

  for (int i = 0; i < argc; i++) {
    string arg( argv[i] );
    istringstream argss(arg);

    if (arg == "-text") {
      textOnly = true;
    } else if (arg == "-seed") {
      // The argument after seed should be an integer
      i++;
      string arg( argv[i] );
      istringstream argss(arg);

      argss >> seed;
    } else if (arg == "-scriptfile") {
      scriptFilePath = "";

      // The next word should be a script file path
      i++;
      string arg( argv[i] );
      istringstream argss(arg);

      argss >> scriptFilePath;
    } else if (arg == "-startlevel") {
      // The argument after startLevel should be an integer
      i++;
      string arg( argv[i] );
      istringstream argss(arg);
      argss >> startLevel;
    }
  }

  // Setup the game based on the defaults or commandline arguments
  Grid grid;

  Xwindow* w;
  if (!textOnly) {
    w = new Xwindow(CELL_WIDTH * COLUMNS, CELL_HEIGHT * (ROWS-3) + 200);
  }

  Level* level = NULL;
  if (startLevel == 0) {
    level = new Level0(&grid);
    // Level0 contains the readFromFile method
    static_cast<Level0*>(level)->readFromFile( scriptFilePath );
  } else if (startLevel == 1) {
    level = new Level1(&grid);
  } else if (startLevel == 2) {
    level = new Level2(&grid);
  } else if (startLevel == 3) {
    level = new Level3(&grid);
  }
  level->setSeed( seed );

  Block* currentBlock = level->createBlock();
  char nextBlockType  = level->getNextBlockType();
  int score = 0;
  int highScore = 0;
  int currentLevel = startLevel;

  bool gameOver = true;

  string s;

  while(gameOver) {
    cout << "Level:    " << currentLevel << endl;
    cout << "Score:    " << score << endl;
    cout << "Hi Score: " << highScore << endl;
    cout << grid;
    cout << "Next:" << endl;
    printBlock( nextBlockType );

    if (!textOnly) {
      // Start rendering the window
      grid.render( w ); // Pass the window over and the grid will render the cells onto it
      // Render the bottom border of the game area
      w->fillRectangle(0, CELL_HEIGHT * (ROWS - 3), CELL_WIDTH * COLUMNS, 2, Xwindow::White);

      ostringstream statStream;
      // Blank out the area below the grid
      w->fillRectangle(0, CELL_WIDTH * (ROWS - 3) + 2, CELL_WIDTH * COLUMNS, 200, Xwindow::Black);

      // Render the different stats about the current state of the game
      statStream << "Level: " << currentLevel;
      w->drawString(0, CELL_WIDTH * (ROWS - 3) + (FONT_SIZE*1), statStream.str(), Xwindow::White);
      statStream.str(""); // Clear the stream
      statStream << "Score: " << score;
      w->drawString(0, CELL_WIDTH * (ROWS - 3) + (FONT_SIZE*2), statStream.str(), Xwindow::White);
      statStream.str(""); // Clear the stream
      statStream << "Hi Score: " << highScore;
      w->drawString(0, CELL_WIDTH * (ROWS - 3) + (FONT_SIZE*3), statStream.str(), Xwindow::White);

      // Render the next block
      renderBlock( nextBlockType, w );
    }

    getline(cin,s);
    if (cin.fail()) break;
    istringstream iss(s);

    // Attempt to read in a multiplier
    // If there is none, this should be empty
    int multiplier = 1;
    if (iss.peek() >= 48 && iss.peek() <= 57) {
      iss >> multiplier;
    }

    string command;
    iss >> command;

    for (int i = 0; i < multiplier; i++) {

      if (isLeft(command)) {
        currentBlock->moveLeft();
      } else if (isRight(command)) {
        currentBlock->moveRight();
      } else if (isDown(command)) {
        currentBlock->moveDown();
      } else if (isClockwise(command)) {
        currentBlock->clockwise();
      } else if (isCounterClockwise(command)) {
        currentBlock->counterClockwise();
      } else if (isLevelUp(command)) {
        // Only allow a level up if we are not at the maximum level
        if (currentLevel < 3) {
          currentLevel++;
          delete level;
          if (currentLevel == 1) {
            level = new Level1(&grid);
          } else if (currentLevel == 2) {
            level = new Level2(&grid);
          } else if (currentLevel == 3) {
            level = new Level3(&grid);
          }
          level->setSeed( seed );
        }
      } else if (isLevelDown(command)) {
        // Only allow a leveldown if we are at least level 1
        if (currentLevel > 0) {
          currentLevel--;
          delete level;
          if (currentLevel == 0) {
            level = new Level0(&grid);
            static_cast<Level0*>(level)->readFromFile( scriptFilePath );
          } else if (currentLevel == 1) {
            level = new Level1(&grid);
          } else if (currentLevel == 2) {
            level = new Level2(&grid);
          }
          level->setSeed( seed );
        }
      } else if (isDrop(command)) {
        currentBlock->drop();

        // Check state of the grid and run scoring code
        int rowsCleared = grid.checkAndClearRows();
        if (rowsCleared > 0) {
          // When row is cleared, score points equal to current level plus number of cleared rows squared
          int points = (rowsCleared + currentLevel) * (rowsCleared + currentLevel);
          score += points;
          if (score > highScore) {
            highScore = score;
          }
        }

        // Since the block was dropped, we generate the next one
        delete currentBlock;


        currentBlock  = level->createBlock();
        nextBlockType = level->getNextBlockType();

        if (!currentBlock->isValid()){
          gameOver = false;
        }

      } else if (isRestart(command)) {
        // Clear all blocks from the grid
        grid.clear();
        // Resets the score and reinitializes the level
        score = 0;
        // We should re-read the sequence file if we're in Level0
        if (currentLevel == 0) {
          delete level;
          level = new Level0(&grid);
          // Level0 contains the readFromFile method
          static_cast<Level0*>(level)->readFromFile( scriptFilePath );
        }

        // The grid was cleared, all blocks were removed so create a new one
        delete currentBlock;
        currentBlock  = level->createBlock();
        nextBlockType = level->getNextBlockType();
      }
    }
}

  delete w;
  cout << "Game is over. Please try again" << endl;
  delete level;
  delete currentBlock;
}
