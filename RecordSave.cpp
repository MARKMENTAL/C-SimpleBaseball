#include <iostream>
#include <fstream>
#include <string>
#include <time.h>


class RecordSave { 
  public: 
    std::string save(int humanpoints, int cpupoints);
};


std::string RecordSave::save(int humanpoints, int cpupoints) {
  //uses tm struct to display the time for record keeping
  time_t rawtime;
  struct tm * timeinfo;
  time( & rawtime);
  timeinfo = localtime( & rawtime);
  std::string score = asctime(timeinfo);
  score.append("|| Total Player Points: " + std::to_string(humanpoints) + " || \n" 
  + "Total CPU points: " +std::to_string(cpupoints) +" ||\n");
  std::ofstream outfile;
  outfile.open("SimpleBaseballRecords.txt", std::ios_base::app);
  outfile << score;
  outfile.close();
  return score;
}