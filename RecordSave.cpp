#include <iostream>
#include <fstream>
#include <string>
#include <time.h>

class RecordSave { 
  public: 
    void save(int hits);
};
void RecordSave::save(int hits) {
  //uses tm struct to display the time for record keeping
  time_t rawtime;
  struct tm * timeinfo;
  time( & rawtime);
  timeinfo = localtime( & rawtime);
  std::string score = asctime(timeinfo);
  score.append("|| Total Hits: " + std::to_string(hits) + " ||");
  std::ofstream outfile;
  outfile.open("SimpleBaseballRecords.txt", std::ios_base::app);
  outfile << score << "\n";
  outfile.close();
}