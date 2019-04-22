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
void updatestatus(string filename,int field,string content,string id){
  fstream file,temp;
  string line,copy;
  int i,count=1;
  bool next=true;
  file.open(filename.c_str());
  temp.open("temp_update.txt");
  while(getline(file,line)){
    cout << line << endl;
    count=1;
    if(line.find(id)!=string::npos){
      for(i=0;i<line.length();++i){
        if(next)
          temp << line[i];
        if(line[i]=='|'){
          count++;
          next=true;
        }
        if(count==field && next){
          temp << content << "|";
          next=false;
        }
      }
      temp << endl;
    }
    else{
      temp << line <<endl;
    }
  }
  temp.close();
  file.close();
  temp.open("temp_update.txt");
  file.open(filename);
  while(getline(temp,line)){
    cout<< line <<endl;
    file << line <<endl;
  }
  file.close();
  temp.close();

}
int main()
{
    string id,filename="test.txt";
    cout << "ID: ";
    cin >> id;
    updatestatus(filename,4,"JM2",id);
    return 0;
}
