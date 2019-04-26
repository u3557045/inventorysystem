#include <iostream>
#include "datastructure.h"
#include <string>
#include <fstream>
#include <cstdlib>
#include <cstdio>
using namespace std;

void view_record(string shopid){
  //open transection file
  ifstream tranfin;
  fstream temp,_temp;
  string month[12];
  month[0]="Jan";
  month[1]="Feb";
  month[2]="Mar";
  month[3]="Apr";
  month[4]="May";
  month[5]="Jun";
  month[6]="Jul";
  month[7]="Aug";
  month[8]="Sep";
  month[9]="Oct";
  month[10]="Nov";
  month[11]="Dec";


  tranfin.open((shopid+"_transaction.txt").c_str());
  if (tranfin.fail()){
    cout<<"Unable to open transaction file\n";
    exit(1);
  }


  int grosssales=0,grossprofit=0,count,linenum=0,i,j=0,index;
  string monthin,id,line,bye;
  bool firstline =true,exit=false;
  while(!exit){
    //do{
      cout<<"Which monthly report would you like to view? (1-12)\n";
      cin >> monthin;
    //}while(!(monthin>="1"&&monthin<="12"));
    cout<<"************************************************MONTHLY REPORT*************************************************\n";
    int pos,lastpos,amount,price,idpos,itemsales,largestsale=0;
    temp.open((month[stoi(monthin)-1]+"_temp.txt").c_str(),ios::out);
    while (getline(tranfin,line)){
      if (line.find(month[stoi(monthin)-1])!=string::npos){
        temp << line <<endl;
        linenum++;
      }
    }
    temp.close();
    temp.open((month[stoi(monthin)-1]+"_temp.txt").c_str(),ios::in);
    itemstruct * products = new itemstruct[linenum];
    while(getline(temp,line)){
      count = 1 ;
      for(i=0;i<line.length();++i){
        if(line[i]=='|')
          count++;
        if(count==1)
          products[j].id+=line[i];
        else if(count==2 && line[i]!='|')
          products[j].name+=line[i];
        else if (count==3)
          break;
      }
      products[j].amount=stoi(checkamount((month[stoi(monthin)-1]+"_temp.txt").c_str(),products[j].id));
      products[j].price=stod(checkprice((month[stoi(monthin)-1]+"_temp.txt").c_str(),products[j].id));
      j++;
    }
    temp.close();
    sorting(1,linenum,1,products);
    int amountchange=0;
    double greatestgain=0,gain=0,totalgain=0;
    string bestsale_item;
    for(i=0;i<linenum;++i){
      //cout << products[i].id << "|" << products[i].name << "|" << products[i].amount << "|" << products[j].price << endl;
      if(i==0){
        amountchange+=products[i].amount;
        gain+=products[i].amount*products[i].price;
      }
      else if(products[i].id == products[i-1].id){
        amountchange+=products[i].amount;
        gain+=products[i].amount*products[i].price;
      }
      else{
        cout << products[i].id << "|" << products[i].name << "|" << amountchange << "|" << products[j].price << endl;
        if(gain>greatestgain){
          greatestgain=gain;
          bestsale_item=products[i-1].id;
          gain=0;
        }
        amountchange=products[i].amount;
      }
      totalgain+=products[i].amount*products[i].price;
    }
    cout << "The best selling item is " << bestsale_item << endl;
    cout << "The gross profit is $" << totalgain << endl;

    cout << "Back to main screen? (Y/N)";
    cin >> bye;
    if(bye=="Y")
      exit=true;
  }
}
