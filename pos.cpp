#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "datastructure.h"
#include <ctime>
using namespace std;
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
  while(!exit){
    system("clear");
    exist=false;
    cout << "1.Check price\n";
    cout << "2.Sell product\n";
    cout << "3.Exit\n";
    // simple input vaildation
    do{
      cout << "Please enter the command (1-3): ";
      cin >> cmd; //input is an integer from 1 to 3
    }while(cmd>"3"||cmd<"1");

    exist=false;
    switch (stoi(cmd)) {
      case 1:
        system("clear");
        cout << "Please enter the product ID that you want to check: "; //input is string of product ID
        cin >> productid;
        status.open(statusfilename.c_str(),ios::in);
        while(getline(status,line)&&!exist){
          //check the item is exist or not
          if(line.find(productid)!=string::npos)
            exist=true;
        }
        status.close();
        if(exist){
          price=checkprice(statusfilename,productid);
          cout << "The selling price of " << productid << " is $" << price << endl; //output the selling of the product
          cout << "Press any key to continue\n";
          cin.get();
          cin.get();
        }
        else{
          cout << "Product ID " << productid << " is not exist." <<endl; //output if the product is not exist
          cout << "Press any key to continue.\n";
          cin.get();
          cin.get();
        }
        break;
      case 2:
        system("clear");
        cout << "Please enter product ID that needs check-out: ";
        cin >> productid; // input is string of product ID

        status.open(statusfilename.c_str(),ios::in);
        while(getline(status,line)&&!exist){
          if(line.find(productid)!=string::npos)
            exist=true;
        }

        status.close();
        if(exist){
          amountstr=checkamount(statusfilename,productid);
          //check the item is still available at the current shop


          //if not available at the current shop -> look for availablity at other shop
          if(amountstr=="0"){
            cout << "Product ID " << productid << " is out of stock in your shop." << endl;//output if the product is out of stock
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
              cout << "Available at shop " << shopids << endl; //output the availablity of shop
          }

          //if the item is available perform normal checkout
          else{
            price = checkprice(statusfilename,productid);
            cout << "The price is $" << price << " and have "<< amountstr<< " left."<< endl;//output the info of the stock
            cout << "Please enter the amount: ";
            cin >> amount; //input is an interger

          //check if the volume left is enough
            if(stoi(amountstr)<amount)
              cout << "Not enough stock!!" << endl;
            else{
              cout << "The total is $" << stod(price)*(amount) <<endl;//output the total amount

          //to confirm the checkout
              cout << "Proceed? (Y/N) ";
              cin >> checkout; //input is a string
              if(checkout=='Y'){
                transaction.open(transactionfilename.c_str(),ios::app);
                status.open(statusfilename.c_str(),ios::in);
                time(&tt);
                ti=localtime(&tt);

                while(getline(status,line)){
                  count=1;
                  if(line.find(productid)!=string::npos){
                    for(int i=0;i<line.length();++i){
                      if(line[i]=='|')
                        count++;
                      if(count<=5)
                        transaction << line[i];
            //write a negative amount to the transaction file to represent sale
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
