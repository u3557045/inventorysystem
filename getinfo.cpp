#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "datastructure.h"
using namespace std;
string checkprice(string filename,string productid){
  string price,line;
  int count;
  ifstream file;
  file.open(filename.c_str());
  while(getline(file,line)){
    count=1;
    if(line.find(productid)!=string::npos){
      for(int i=0;i<line.length();++i){
        if(line[i]=='|')
          count++;
        if(count==5 && line[i]!='|')
          price+=line[i];
      }
      break;
    }
  }
  file.close();
  return price;
}
string checkamount(string filename, string productid){
  string amountstr,line;
  int count;
  ifstream file;
  file.open(filename.c_str());
  while(getline(file,line)){
    count=1;
    if(line.find(productid)!=string::npos){
      for(int i=0;i<line.length();++i){
        if(line[i]=='|')
          count++;
        if(count==6 && line[i]!='|')
          amountstr+=line[i];
      }
      break;
    }
  }
  file.close();
  return amountstr;
}
string checkid(string line){
  string id;
  for(int i=0;i<line.length();++i){
    if(line[i]!='|')
      id+=line[i];
    else
      break;
  }
  return id;
}
