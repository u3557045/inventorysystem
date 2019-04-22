#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

void updatestatus(string filename,int field,string content,string id){
  fstream file,temp,amountstr;
  string line,copy;
  int i,count=1,amount=0;
  bool next=true,status=false;
  if(file.find("status")!=string::npos){
    status=true;
  }
  file.open(filename.c_str(),ios::in);
  temp.open("temp_update.txt",ios::out);
  while(getline(file,line)){
    cout << line << endl;
    count=1;
    if(line.find(id)!=string::npos){
      for(i=0;i<line.length();++i){
        if(next){
          temp << line[i];
        }
        if(line[i]=='|'){
          count++;
          next=true;
        }
        if(count==field && next){
          temp << content << "|";
          next=false;
        }
        else if(count==6)
          amountstr+=line[i];
        else if(count==7){
          
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
  temp.open("temp_update.txt",ios::in);
  file.open(filename,ios::out);
  while(getline(temp,line)){
    cout<< line <<endl;
    file << line <<endl;
  }
  file.close();
  temp.close();

}
