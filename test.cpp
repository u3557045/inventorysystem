#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>
#include <cmath>
#include <ctime>
using namespace std;
const double e=2.72;
const int MAX_SIZE = 1000;

int main()
{
    ifstream file;
    string line;
    file.open("test_status.txt");
    while(getline(file,line)){
      cout << line << endl;
    }
    while(getline(file,line)){
      cout << line << endl;
    }
    file.close();
    cout << "fk";
    return 0;
}
