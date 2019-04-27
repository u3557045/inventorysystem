#include "datastructure.h"
#include <iostream>
#include <fstream>
#include <string>
void alert(string id,int threshold){
  if(id!="0"){
    string filename,line,amountstr,productid,productname;
    int count=1,amount;
    filename=id+"_status.txt";
    ifstream file;
    file.open(filename.c_str());
    while(getline(file,line)){

      count=1;
      amount=0;
      amountstr.clear();
      productid.clear();
      productname.clear();
      for(int i=0;i<line.length();++i){
        if(line[i]=='|')
          count++;
        if(count==1)
          productid+=line[i];
        else if(count==2 && line[i]!='|')
          productname+=line[i];
        else if(count==6 && line[i]!='|')
          amountstr+=line[i];

      }
      amount=stoi(amountstr);

      //check the volume of item left at the shop in order to give alert to the user/staff
      if(amount<=threshold && amount!=0)
        cout<<"Product " <<productid <<'|'<<productname<<" is running out of stock with " << amount <<" left!" <<endl;  // output is the volume left of item which is below the threshold
      else if (amount==0)
        cout<<"Product " <<productid <<'|'<<productname<<" ran out of stock !!"  <<endl; //output is item which is out of stock
    }
    file.close();
  }
}
