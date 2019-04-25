#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "datastructure.h"
#include <ctime>
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
void pos(string shopid){
  int amount,count;
  string productid,statusfilename,transactionfilename,price,line,pause,amountstr,cmd,shopids,id;
  itemstruct item;
  char checkout;
  time_t tt;
  struct tm*ti;
  bool exit=false,exist=false;
  fstream transaction,status,shop,shoplist;
  statusfilename=shopid+"_status.txt";
  transactionfilename=shopid+"_transaction.txt";
  //cout << statusfilename << transactionfilename << endl;
  while(!exit){
    system("clear");
    exist=false;
    cout << "1.Check price\n";
    cout << "2.Sell product\n";
    cout << "3.Exit\n";
    do{
      cout << "Please enter the command (1-3): ";
      cin >> cmd;
    }while(cmd>"3"||cmd<"1");

    exist=false;
    switch (stoi(cmd)) {
      case 1:
        system("clear");
        cout << "Please enter the product ID that you want to check: ";
        cin >> productid;
        status.open(statusfilename.c_str(),ios::in);
        while(getline(status,line)&&!exist){
          //cout << line <<endl;
          if(line.find(productid)!=string::npos)
            exist=true;
        }
        status.close();
        if(exist){
          price=checkprice(statusfilename,productid);
          cout << "The selling price of " << productid << " is $" << price << endl;
          cout << "Press any key to continue\n";
          cin.get();
          cin.get();
        }
        else{
          cout << "Product ID " << productid << " is not exist." <<endl;
          cout << "Press any key to continue.\n";
          cin.get();
          cin.get();
        }
        break;
      case 2:
        system("clear");
        cout << "Please enter product ID that needs check-out: ";
        cin >> productid;
        //cout << productid << endl;
        status.open(statusfilename.c_str(),ios::in);
        while(getline(status,line)&&!exist){
          if(line.find(productid)!=string::npos)
            exist=true;
        }
        //cout <<exist<< endl;
        status.close();
        if(exist){
          amountstr=checkamount(statusfilename,productid);
        //  cout << amountstr << endl;
          if(amountstr=="0"){
            cout << "Product ID " << productid << " is out of stock in your shop." << endl;
            shoplist.open("shoplist.txt",ios::in);
            while(getline(shoplist,id)){
              cout << "Opening shop " << id << endl;
              shop.open((id+"_status.txt").c_str(),ios::in);
              while(getline(shop,line)){
                cout << line << endl;
                if(line.find(productid)!=string::npos && line!=shopid){
                  if(checkamount((id+"_status.txt").c_str(),productid)!="0"){
                    shopids+=id+" ";
                    break;
                  }
                }
              }
              shop.close();
            }
            shoplist.close();
            if(!shopids.empty())
              cout << "Available at shop " << shopids << endl;
          }
          else{
            price = checkprice(statusfilename,productid);
            cout << "The price is " << price << " and have "<< amountstr<< " left."<< endl;
            cout << "Please enter the amount: ";
            cin >> amount;
            if(stoi(amountstr)<amount)
              cout << "Not enough stock!!" << endl;
            else{
              cout << "The total is $" << stod(price)*(amount) <<endl;
              cout << "Proceed? (Y/N) ";
              cin >> checkout;
              if(checkout=='Y'){
                transaction.open(transactionfilename.c_str(),ios::app);
                status.open(statusfilename.c_str(),ios::in);
                time(&tt);
                ti=localtime(&tt);
                //cout << asctime(ti);
                while(getline(status,line)){
                  count=1;
                  //cout << line << endl;
                  if(line.find(productid)!=string::npos){
                    for(int i=0;i<line.length();++i){
                      if(line[i]=='|')
                        count++;
                      if(count<=5)
                        transaction << line[i];
                      else if(count==6){
                        transaction << '|'<<-1*amount <<'|'<<asctime(ti);
                        break;
                      }
                    }
                    break;
                  }
                }
                status.close();
                updatestatus(statusfilename,6,to_string(stoi(amountstr)-amount),productid);
              }
            }
          }
          transaction.close();
          cout << "Press any key to continue.";
          cin.get();
          cin.get();
        }
        else{
          cout << "Product ID " << productid << " is not exist.\nPress any key to continue.";
          cin.get();
          cin.get();
        }
        break;
      case 3:
        exit=true;
        break;
    }
  }
}
