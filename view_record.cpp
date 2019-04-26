#include <iostream>
#include "datastructure.h"
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

void view_record(string shopid){
  //open transection file
  ifstream tranfin;
  tranfin.open((shopid+".txt").c_str());
  if (tranfin.fail()){
    cout<<"Unable to open transaction file\n";
    exit(1);
  }
  int grosssales=0,grossprofit=0;
  string month;
  cout<<"Which monthly report would you like to view?\n";
  cout<<"(Jan/Feb/Mar/Apr/May/Jun/Jul/Aug/Sep/Oct/Nov/Dec)\n"
  cin>>month;
  cout<<"************************************************MONTHLY REPORT*************************************************\n";

  int pos,lastpos,amount,price,idpos,itemsales,largestsale=0;
  While (getline(tranfin,line)){
    if (line.find(month)!=string::npos){
      lastpos=line.rfind("|");
      pos=line.rfind("|",lastpos-1);
      amount=atoi((line.substr(pos+1,lastpos)).c_str());
      if (amount<0){
        //calculate gross sales
        lastpos=(line.rfind("|",pos-1));
        price=atoi((line.substr(lastpos+1,pos)).c_str());

        grosssales+=amount*(-1)*price;
        idpos=line.find("|");
        
      }

    }
      cout<<"Gross sales: "<<grosssales<<'\n';

  }


  //calculate gross profit

}
