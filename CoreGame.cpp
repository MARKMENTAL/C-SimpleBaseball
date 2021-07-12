#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "RecordSave.cpp"

class CoreGame {
  public:
    int pitchlocation, pitchguess, strikes;
  int running, outs, hits, cpuhits;
  void offense();
  void defense();
};

void CoreGame::offense() {
  CoreGame Offense;
  //redeclaring potentially problematic variables
  Offense.strikes = 0;
  Offense.pitchlocation = 0;
  Offense.pitchguess = 0;
  Offense.outs = 0;
  Offense.running = 0;
  Offense.hits = 0;

  do {
    srand(time(NULL));
    Offense.pitchlocation = rand() % 6 + 1;

    std::cout << "Get Ready for the pitch! ||" << "Strikes:" << Offense.strikes <<
      "||\nType a location (number from 1 to 6) to guess where the offense will pitch" << "\n";
    std::cin >> (Offense.pitchguess);

    if (Offense.pitchguess == Offense.pitchlocation) {
      std::cout << "Swing and a hit!\n";
      Offense.hits++;
    } else {
      if (Offense.pitchguess > 6 || Offense.pitchguess < 1) {
        std::cout << "Invalid Input. Skipping to next inning.\n";
        //fixing input buffer for reuse
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        Offense.running++;
      } else {
        std::cout << "Swing and a miss\n";
        Offense.strikes = Offense.strikes + 1;
        if (Offense.strikes == 3) {
          Offense.outs++;
          std::cout << "Out #" << Offense.outs << "!\n";
          Offense.strikes = 0;
        }
        if (Offense.outs == 3) {
          std::cout << "Offense Over! The side is retired. || Total Hits: " << Offense.hits << " ||\n";
          Offense.running++;
        }
      }
    }
  }
  while (Offense.running == 0);
}
void CoreGame::defense() {
  CoreGame Defense;
  RecordSave RecordSave;
  Defense.strikes = 0;
  Defense.pitchlocation = 0;
  Defense.outs = 0;
  Defense.running = 0;
  Defense.cpuhits = 0;

  do {
    srand(time(NULL));
    Defense.pitchguess = rand() % 6 + 1;

    std::cout << "Get Ready to pitch! ||" << "Strikes:" << Defense.strikes <<
      "||\nType a location (number from 1 to 6) to choose a location to pitch." << "\n";
    std::cin >> Defense.pitchlocation;

    if (Defense.pitchguess == Defense.pitchlocation) {
      std::cout << "Swing and a hit!\n";
      Defense.cpuhits++;
    } else {
      if (Defense.pitchlocation > 6 || Defense.pitchlocation < 1) {
        std::cout << "Invalid Input. Skipping to next inning.\n";
        //fixing input buffer for reuse
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        Defense.running++;
      } else {
        std::cout << "Swing and a miss\n";
        Defense.strikes = Defense.strikes + 1;
        if (Defense.strikes == 3) {
          Defense.outs++;
          std::cout << "Out #" << Defense.outs << "!\n";
          Defense.strikes = 0;
        }
        if (Defense.outs == 3) {
          std::cout << "Defense Over! The side is retired. || Total Hits: " << Defense.cpuhits << " ||\n";
          RecordSave.save(Defense.hits, Defense.cpuhits);
          Defense.running++;
        }
      }
    }
  }
  while (Defense.running == 0);
}
