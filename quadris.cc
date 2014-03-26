#include <string>
#include <iostream>
#include <sstream>
#include "grid.h"
#include "level0.h"

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

int main(int argc, char* argv[]) {
  // Read and parse the commandline arguments
  // Defaults
  bool textOnly         = true; // Set this to false by default
  int seed              = 1337;
  string scriptFilePath = "sequence.txt";
  int startLevel        = 0;

  for (int i = 0; i < argc; i++) {
    string arg( argv[i] );
    istringstream argss(arg);

    if (arg == "-text") {
      textOnly = true;
    } else if (arg == "-seed") {
      argss >> seed;
    } else if (arg == "-scriptfile") {
      scriptFilePath = "";
      argss >> scriptFilePath;
    } else if (arg == "-startlevel") {
      argss >> startLevel;
    }
  }

  // Setup the game based on the defaults or commandline arguments
  Grid grid;
  Level* level = NULL;
  if (startLevel == 0) {
    level = new Level0(&grid);
    level->setSeed( seed );

    // Level0 contains the readFromFile method
    static_cast<Level0*>(level)->readFromFile( scriptFilePath );
  } else if (startLevel == 1) {
    level = new Level0(&grid);
  } else if (startLevel == 2) {
    level = new Level0(&grid);
  } else if (startLevel == 3) {
    level = new Level0(&grid);
  }

  Block* currentBlock = level->createBlock();
  int score = 0;
  int highScore = 0;
  int currentLevel = startLevel;

  string s;

  while(1) {
    cout << "Level:    " << currentLevel << endl;
    cout << "Score:    " << score << endl;
    cout << "Hi Score: " << highScore << endl;
    cout << grid;

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

    cout << "Multiplier: " << multiplier << endl;
    cout << "Reading command: " << command << endl;

    for (int i = 0; i < multiplier; i++) {

      if (isLeft(command)) {
        currentBlock->moveLeft();
      } else if (isRight(command)) {
        currentBlock->moveRight();
      } else if (isDown(command)) {
        currentBlock->moveDown();
      } else if (isDrop(command)) {
        currentBlock->drop();

        // The block is now dropped, generate the next one
        delete currentBlock;
        currentBlock = level->createBlock();

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
      }
    }

  }

  delete level;
  delete currentBlock;
}
