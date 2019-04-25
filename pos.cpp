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
  int cmd,amount,count;
  string productid,statusfilename,transectionfilename,price,line,pause,amountstr;
  itemstruct item;
  char checkout;
  time_t tt;
  struct tm*ti;
  bool exit=false,exist=false;
  fstream transection,status;
  statusfilename=shopid+"_status.txt";
  transectionfilename=shopid+"_transection.txt";
  //cout << statusfilename << transectionfilename << endl;
  while(!exit){
    system("clear");
    exist=false;
    cout << "1.Check price\n";
    cout << "2.Sell product\n";
    cout << "3.Exit\n";
    cout << "Please enter the command (1-3): ";
    cin >> cmd;
    exist=false;
    switch (cmd) {
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
          if(amountstr=="0")
            cout << "Product ID " << productid << " is out of stock." << endl;
          else{
            price = checkprice(statusfilename,productid);
            cout << "The price is " << price << " and have "<< amountstr<< " left."<< endl;
            cout << "Please enter the amount: ";
            cin >> amount;
            if(stoi(amountstr)<amount)
              cout << "Not enough stock!!" << endl;
            else{
              cout << "Proceed? (Y/N)\n";
              cin >> checkout;
              if(checkout=='Y'){
                transection.open(transectionfilename.c_str(),ios::app);
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
                        transection << line[i];
                      else if(count==6){
                        transection << '|'<<-1*amount <<'|'<<asctime(ti);
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
          transection.close();
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
