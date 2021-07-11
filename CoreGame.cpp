#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "RecordSave.cpp"

class CoreGame { 
  public: 
    int pitchlocation, pitchguess, strikes;
  int running, outs, hits;
  void offense();
};

void CoreGame::offense() {
  CoreGame Game;
  RecordSave RecordSave;
  //redeclaring potentially problematic variables
  Game.strikes = 0;
  Game.pitchlocation = 0;
  Game.outs = 0;
  Game.running = 0;

  do {
    srand(time(NULL));
    Game.pitchlocation = rand() % 6 + 1;

    std::cout << "Get Ready for the pitch! ||" << "Strikes:" << Game.strikes 
    << "||\nType a location (number from 1 to 6) to guess where the offense will pitch" << "\n";
    std::cin >> Game.pitchguess;

    if (Game.pitchguess == Game.pitchlocation) {
      std::cout << "Swing and a hit!\n";
      Game.hits++;
    } 
    else {
      std::cout << "Swing and a miss\n";
      Game.strikes = Game.strikes + 1;
      if (Game.strikes == 3) {
        Game.outs++;
        std::cout << "Out #" << Game.outs << "!\n";
        Game.strikes = 0;
      }
      if (Game.outs == 3) {
        std::cout << "Game Over! The side is retired. || Total Hits: " << Game.hits << " ||\n";
        RecordSave.save(Game.hits);
        //changes running value to 1 to signify 
        //exiting the while loop that was keeping the game running
        Game.running++;
      }

    }
  }
  while (Game.running == 0);
}