#include <iostream>
#include <fstream>      /* ofstream */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using namespace std;

int main () {
  ofstream myfile;
  myfile.open ("testCase.txt");
  myfile << "[";
  int i;
  srand(time(NULL));
  for (i = 1; i < 4095; i++) {
      myfile << (rand()%2000 - 1000) << ", ";
  }
  myfile << (rand()%2000 - 1000) << "]";
  myfile.close();
  return 0;
}
