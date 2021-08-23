#include "CoreGame.cpp"
#include "RecordSave.cpp"
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

char simmenu(){
  char sim;
  std::cout << "Would you like to sim the game or play it? (s/p)\n";
  std::cin >> sim;
  return sim;
}

int main() {
  int humanpoints = 0;
  int cpupoints = 0;
  unsigned char any = 0;
  char simorplay;
  std::string humanteam;
  std::string cputeam;
  CoreGame Game;
  RecordSave result;

  std::cout << "Welcome to Simple Baseball(Version 2) by MARKMENTAL\nControls:\n(numbers 1 through 6) = hit/throw pitch.\n";
  std::cout << "(keys not 1 thru 6) = skip half inning.\n";
  std::cout << "Type the name of the Human team. (No spaces)\nExample:'Boston_Red_Sox'\n";
  std::cin >> humanteam;
  std::cout << "Type the name of the CPU team. (No spaces)\nExample:'New_York_Yankees'\n";
  std::cin >> cputeam;
  std::replace( humanteam.begin(), humanteam.end(), '_', ' ');
  std::replace( cputeam.begin(), cputeam.end(), '_', ' ');
  simorplay = simmenu();

if (simorplay == 's'){
    for (double i = 1; i <= 9.5;){
    humanpoints = Game.simoffense(i,humanpoints, cpupoints,humanteam,cputeam);
    i+=0.5;
    cpupoints = Game.simdefense(i,humanpoints, cpupoints,humanteam,cputeam);
    i+=0.5;
  }

  if (humanpoints == cpupoints){
     for (double i = 10; humanpoints == cpupoints;){
       humanpoints = Game.simoffense(i,humanpoints, cpupoints, humanteam, cputeam);
       i+=0.5;

       if (humanpoints == cpupoints){
       cpupoints = Game.simdefense(i,humanpoints, cpupoints, humanteam, cputeam);
       i+=0.5;
       }
     }
   }
}
else{
  for (double i = 1; i <= 9.5;){
    humanpoints = Game.offense(i,humanpoints, cpupoints,humanteam,cputeam);
    i+=0.5;
    cpupoints = Game.defense(i,humanpoints, cpupoints,humanteam,cputeam);
    i+=0.5;
  }

   if (humanpoints == cpupoints){
     for (double i = 10; humanpoints == cpupoints;){
       humanpoints = Game.offense(i,humanpoints, cpupoints, humanteam, cputeam);
       i+=0.5;

       if (humanpoints == cpupoints){
       cpupoints = Game.defense(i,humanpoints, cpupoints, humanteam, cputeam);
       i+=0.5;
       }
     }
   }
}
   std::cout <<"\nGame Results\n" << result.save(humanpoints, cpupoints, humanteam, cputeam);
   return 0;
}
