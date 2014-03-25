#include <string>
#include <iostream>
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

int main(int argc, char* argv[]) {
  // Read and parse the commandline arguments
  // Defaults
  bool textOnly         = true; // Set this to false by default
  int seed              = 1337;
  string scriptFilePath = "sequence.txt"
  int startLevel        = 0

  for (int i = 0; i < argc; i++) {
    string arg( argv[i] );
    istringstream argss(arg);

    if (arg == "-text") {
      textOnly = true;
    } else if (arg == "-seed") {
      seed = NULL;
      argss >> seed;
    } else if (arg == "-scriptfile") {
      scriptFilePath = "";
      argss >> scriptFilePath;
    } else if (arg == "-startlevel") {
      startLevel = NULL;
      argss >> startLevel;
    }
  }

  // Setup the game based on the defaults or commandline arguments
  Grid grid;
  Level* level;
  if (startLevel == 0) {
    level = new Level0(grid);
    level->setSeed( seed );

    // Level0 contains the readFromFile method
    static_cast<Level0*>(level)->readFromFile( scriptFilePath );
  } else if (startLevel == 1) {
  } else if (startLevel == 2) {
  } else if (startLevel == 3) {
  }

  Block* currentBlock = level->createBlock();
  int score = 0;
  int highScore = 0;
  int currentLevel = startLevel;

  string s;

  while(1) {
    getline(cin,s);
    if (cin.fail()) break;
    istringstream iss(s);

    // Attempt to read in a multiplier
    // If there is none, this should be empty
    int multiplier;
    if (!(iss >> multiplier)) {
      multiplier = 1;
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
      }

      if (currentBlock->isStopped()) {
        delete currentBlock;
        currentBlock = level->createBlock();

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
  delete grid;
}
