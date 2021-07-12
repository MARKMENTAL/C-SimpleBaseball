#include <iostream>
#include <fstream>
#include <string>
#include <time.h>

class RecordSave { 
  public: 
    void save(int hits, int cpuhits);
};
void RecordSave::save(int hits, int cpuhits) {
  //uses tm struct to display the time for record keeping
  time_t rawtime;
  struct tm * timeinfo;
  time( & rawtime);
  timeinfo = localtime( & rawtime);
  std::string score = asctime(timeinfo);
  score.append("|| Total Player Hits: " + std::to_string(hits) + " || \n" 
  + "Total CPU hits: " +std::to_string(cpuhits) +" ||\n");
  std::ofstream outfile;
  outfile.open("SimpleBaseballRecords.txt", std::ios_base::app);
  outfile << score;
  outfile.close();
}
