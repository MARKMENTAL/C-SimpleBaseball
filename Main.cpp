#include "CoreGame.cpp"
#include "RecordSave.cpp"

int main() {
  int humanpoints = 0;
  int cpupoints = 0;
  unsigned char any = 0;
  CoreGame Game;
  RecordSave result;

  std::cout << "Welcome to Simple Baseball by MARKMENTAL\nControls:\n(numbers 1 through 6) = hit/throw pitch.\n";
  std::cout << "(keys not 1 thru 6) = skip half inning.\nEnter any key to start...\n";
  std::cin >> any;

  for (double i = 1; i <= 9.5;){
    humanpoints = Game.offense(i,humanpoints, cpupoints);
    i+=0.5;
    cpupoints = Game.defense(i,humanpoints, cpupoints);
    i+=0.5;
  }

   if (humanpoints == cpupoints){
     for (double i = 10; humanpoints == cpupoints;){
       humanpoints = Game.offense(i,humanpoints, cpupoints);
       i+=0.5;

       if (humanpoints == cpupoints){
       cpupoints = Game.defense(i,humanpoints, cpupoints);
       i+=0.5;
       }
     }
   }

  std::cout <<"\nGame Results\n" << result.save(humanpoints, cpupoints);

  return 0;
}