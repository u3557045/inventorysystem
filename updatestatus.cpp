#include <iostream>
#include <string>
#include <fstream>
#include "datastructure.h"
using namespace std;

void updatestatus(string filename,int field,string content,string id){
  fstream file,temp;
  string line,copy,amountstr;
  int i,count=1,amount=0;
  bool next=true;
  file.open(filename.c_str(),ios::in);
  temp.open("temp_update.txt",ios::out); // use temp file to store the data after change

  // if the file is the status file
  if(filename.find("status")!=string::npos){
    while(getline(file,line)){
      //cout << line << endl;
      count=1;
      amountstr.clear();
      if(line.find(id)!=string::npos){
        for(i=0;i<line.length();++i){
          if(next){
            temp << line[i];
          }
          if(line[i]=='|'){  // search for the correct field to change
            count++;
            next=true;
          }
          if(count==field && next){ //change the content of the field once the specific field is reached
            temp << content << "|";
            next=false;
          }
          if(field==6){
            amountstr=content;
          }
          else if(count==6 && line[i]!='|')
            amountstr+=line[i];
        //chaneg the status of the item according to volume left
          if(count==7){
            if(amountstr=="0")
              temp << "OUT-OF_STOCK";
            else
              temp << "IN-STOCK";
            break;
          }
        }
        temp << endl;
      }
      else{
        for(i=0;i<line.length();++i){
          if(count!=7 )
            temp<< line[i];
          if(line[i]=='|')
            count++;
          if(count==6 && line[i]!='|')
            amountstr+=line[i];
          else if(count==7){
            if(amountstr=="0")
              temp << "OUT-OF-STOCK";
            else
              temp << "IN-STOCK";
            break;
          }
        }
        temp << endl;
      }
    }
  }

  // if the file is the transaction file
  else if (filename.find("transaction")!=string::npos){
    while(getline(file,line)){
      //cout << line << endl;
      count=1;
      if(line.find(id)!=string::npos){
        for(i=0;i<line.length();++i){
          if(next){
            temp << line[i];
          }
          if(line[i]=='|'){  // search for the correct field to change
            count++;
            next=true;
          }
          if(count==field && next){ //change the content of the field once the specific field is reached
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
  }
  temp.close();
  file.close();
  temp.open("temp_update.txt",ios::in);
  file.open(filename,ios::out);
  while(getline(temp,line)){
    //cout<< line <<endl;
    file << line <<endl;
  }
  file.close();
  temp.close();
  remove("temp_update.txt");
}
