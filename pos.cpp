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
void pos(){
  int cmd,amount,count;
  string productid,shopid,statusfilename,transectionfilename,price,line,pause;
  itemstruct item;
  char checkout;
  time_t tt;
  struct tm*ti;
  bool exit=false,exist=false;
  fstream transection,status;

  system("clear");
  cout << "Please enter your shop ID: ";
  cin >> shopid;
  statusfilename=shopid+"_status.txt";
  transectionfilename=shopid+"_transection.txt";
  cout << statusfilename << transectionfilename << endl;

  while(!exit){
    //system("clear");
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
          cout << line <<endl;
          if(line.find(productid)!=string::npos)
            exist=true;
        }
        //cout << exist << endl;
        //cin >> pause;
        status.close();
        if(exist){
          price=checkprice(statusfilename,productid);
          cout << "The selling price of " << productid << " is " << price << endl;
          cout << "Press any key to continue\n";
          cin.ignore();
        }
        else{
          cout << "Product ID " << productid << " is not exist.\nPress any key to continue.";
          cin.ignore();
        }
        break;
      case 2:
        cout << "Please enter product ID that needs check-out: ";
        cin >> productid;
        cout << productid << endl;
        status.open(statusfilename.c_str(),ios::in);
        while(getline(status,line)&&!exist){
          if(line.find(productid)!=string::npos)
            exist=true;
        }
        //cout <<exist<< endl;
        status.close();
        if(exist){
          price = checkprice(statusfilename,productid);
          cout << "The price is " << price <<endl;
          cout << "Please enter the amount: ";
          cin >> amount;
          cout << "Proceed? (Y/N)\n";
          cin >> checkout;
          cout << checkout <<endl;
          if(checkout=='Y'){
            transection.open(transectionfilename.c_str(),ios::app);
            status.open(statusfilename.c_str(),ios::in);
            time(&tt);
            ti=localtime(&tt);
            //cout << asctime(ti);
            while(getline(status,line)){
              count=1;
              cout << line << endl;
              if(line.find(productid)!=string::npos){
                for(int i=0;i<line.length();++i){
                  if(line[i]=='|')
                    count++;
                  if(count<=5)
                    transection << line[i];
                  else if(count==6){
                    transection << -1*amount <<'|'<<asctime(ti);
                    break;
                  }
                }
                break;
              }
            }
          }
          transection.close();
          cout << "Press any key to continue.";
          cin.ignore();
        }
        else{
          cout << "Product ID " << productid << " is not exist.\nPress any key to continue.";
          cin.ignore();
        }
        break;
      case 3:
        exit=true;
        cout << "Please press key to go back to main screen.";
        cin.ignore();
        break;
    }
  }


}
