#include <iostream>
#include "datastructure.h"
#include <string>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
using namespace std;

void view_record(string shopid){
  //open transection file
  ifstream tranfin;
  fstream temp;
  string month[12];

  // intialize the month string from 1 - 12
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
  string monthin,id,line,bye,price,amountstr;
  bool firstline =true,exit=false;
  while(!exit){
    linenum=0;
    j=0;
    system("clear");

    cout<<"Which monthly report would you like to view? (1-12)\n";
    cin >> monthin; // the input is an integer from 1 to 12


    temp.open((month[stoi(monthin)-1]+"_temp.txt").c_str(),ios::out);
    tranfin.open((shopid+"_transaction.txt").c_str());

    //check the numbers of line in the transaction file.
    while (getline(tranfin,line)){
      if (line.find(month[stoi(monthin)-1])!=string::npos){
        temp << line <<endl;
        linenum++;
      }
    }
    temp.close();
    tranfin.close();

    //check if the transaction file is empty
    if(linenum==0)
      cout << "There is no transaction on " << month[stoi(monthin)-1] <<endl;
    else{
      cout<<"Report on " << month[stoi(monthin)-1]<< ":"<<endl; // output is the title of the report
      cout<<setw(10)<< "Product ID"<<setw(25)<<"Product Name"<<setw(20)<<"Inventory Change"<<setw(15)<<"Gross profit" <<endl; //output is the field name
      temp.open((month[stoi(monthin)-1]+"_temp.txt").c_str(),ios::in);
      itemstruct * products = new itemstruct[linenum];
      while(getline(temp,line)){
        count = 1 ;

        // feed the different field into the itemstruct
        for(i=0;i<line.length();++i){
          // count is the field counter
          if(line[i]=='|')
            count++;
          if(count==1){
            products[j].id+=line[i];
          }
          else if(count==2 && line[i]!='|'){
            products[j].name+=line[i];
          }
          else if(count==5 && line[i]!='|')
            price+=line[i];
          else if(count==6 && line[i]!='|')
              amountstr+=line[i];
          else if (count==7)
            break;
        }

        products[j].amount=stoi(amountstr);
        products[j].price=stod(price);

        amountstr.clear();
        price.clear();
        j++;
      }
      temp.close();

      // sort the itemstruct
      sorting(1,linenum,1,products);

      int amountchange=0,sale=0,greatestsale=0;
      double greatestgain=0,gain=0,totalgain=0;
      string bestsale_item,greatestgain_item;

      // transaction summary eg inventory change of each item and total revenue
      for(i=0;i<linenum;++i){

        if(i==0){
          amountchange+=products[i].amount;
          gain+=-1*products[i].amount*products[i].price;
          if(products[i].amount<0){  //amount is negative representing the transaction is sold out
            sale+=products[i].amount;
          }

        }
        else if(products[i].id == products[i-1].id){
          amountchange+=products[i].amount;
          gain+=-1*products[i].amount*products[i].price;
          if(products[i].amount<0){
            sale+=products[i].amount;
          }

        }
        else{
          if(gain>=greatestgain){
            greatestgain=gain;
            greatestgain_item=products[i-1].id;
          }
          if(sale<=greatestsale){
            greatestsale=sale;
            bestsale_item=products[i-1].id;
          }
          if(products[i].amount<0)
            sale=products[i].amount;
          cout <<setw(10)<<products[i-1].id  <<setw(25)<< products[i-1].name  <<setw(20)<< amountchange <<setw(15) << gain<< endl;//output is the item summary
          amountchange=products[i].amount;
          gain=-1*products[i].amount*products[i].price;
        }
        totalgain+=-1*products[i].amount*products[i].price;
      }
      if(gain>=greatestgain){
        greatestgain=gain;
        greatestgain_item=products[linenum-1].id;
      }
      if(sale<=greatestsale){
        greatestsale=sale;
        bestsale_item=products[linenum-1].id;
      }
      cout <<setw(10)<< products[linenum-1].id  <<setw(25)<< products[linenum-1].name  <<setw(20)<< amountchange <<setw(15) << gain<< endl;//output is the item summary
      cout <<endl;
      if(totalgain>0)
        cout << "The item makes the greatest profit is " << greatestgain_item << endl;
      cout << "The best selling item is " << bestsale_item << endl;
      cout << "The gross profit is $" << totalgain << endl;
      delete []products;
    }


    cout << "Back to main screen? (Y/N)";
    cin >> bye;
    if(bye=="Y")
      exit=true;
  }
  remove((month[stoi(monthin)-1]+"_temp.txt").c_str());

}
