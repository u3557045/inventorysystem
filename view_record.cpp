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
  fstream temp;
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





  int grosssales=0,grossprofit=0,count,linenum=0,i,j=0,index;
  string monthin,id,line,bye;
  bool firstline =true,exit=false;
  while(!exit){
    j=0;
    system("clear");
    //do{
      cout<<"Which monthly report would you like to view? (1-12)\n";
      cin >> monthin;
    //}while(!(monthin>="1"&&monthin<="12"));
    cout<<"Report on " << month[stoi(monthin)-1]<< ":"<<endl;
    cout<< "Product ID\tProduct Name\tInventory Change\tGross profit\n ";
    int pos,lastpos,amount,price,idpos,itemsales,largestsale=0;
    temp.open((month[stoi(monthin)-1]+"_temp.txt").c_str(),ios::out);
    tranfin.open((shopid+"_transaction.txt").c_str());
    while (getline(tranfin,line)){
      if (line.find(month[stoi(monthin)-1])!=string::npos){
        temp << line <<endl;
        linenum++;
      }
    }
    temp.close();
    tranfin.close();
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
    for(i=0;i<linenum;++i){
      cout << products[i].id << "|" << products[i].name << "|" << products[i].amount << "|" << products[j].price << endl;
    }
    sorting(1,linenum,1,products);
    cout << "after: " << endl;
    for(i=0;i<linenum;++i){
      cout << products[i].id << "|" << products[i].name << "|" << products[i].amount << "|" << products[j].price << endl;
    }
    int amountchange=0;
    double greatestgain=0,gain=0,totalgain=0;
    string bestsale_item;
    for(i=0;i<linenum;++i){

      if(i==0){
        amountchange+=products[i].amount;
        gain+=products[i].amount*products[i].price;
      }
      else if(products[i].id == products[i-1].id){
        amountchange+=products[i].amount;
        gain+=products[i].amount*products[i].price;
      }
      else{
        if(gain>=greatestgain){
          greatestgain=gain;
          bestsale_item=products[i-1].id;
        }

        cout << products[i].id << "\t" << products[i].name << "\t\t" << amountchange << "\t\t\t" << products[i].price<< endl;
        amountchange=products[i].amount;
        gain=0;
      }
      totalgain+=products[i].amount*products[i].price;
    }
    cout << "The best selling item is " << bestsale_item << endl;
    cout << "The gross profit is $" << totalgain << endl;
    delete []products;
    cout << "Back to main screen? (Y/N)";
    cin >> bye;
    if(bye=="Y")
      exit=true;
  }
}
