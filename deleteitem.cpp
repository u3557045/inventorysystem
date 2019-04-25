#include "datastructure.h"
#include <iostream>
#include <fstream>
#include <string>
void deleteitem(string shopid) {
  string productid,line,statusfilename;
  int cmd;
  bool exit = false,exist=false;
  fstream status,temp;
  while(!exit){
    system("clear");
    cout << "1.Delete obsolete commodity\n";
    cout << "2.Exit\n";
    cout << "Please enter command (1-2): ";
    cin >> cmd;
    switch (cmd) {
      case 1:
        cout << "Please enter the ID of the product that you want to delete from the inventory: " << endl;
        cin >> productid;
        statusfilename=shopid+"_status.txt";
        status.open(statusfilename.c_str());
        temp.open("temp_update.txt",ios::out);
        while (getline(status,line)){
          if(line.find(productid)==string::npos){
            temp << line <<endl;
            exist=true;
          }
        }
        temp.close();
        status.close();
        if(!exist){
          cout << "Product " << productid << " does not exist! " << endl;
        }
        else{
          status.open(statusfilename.c_str(),ios::out);
          temp.open("temp_update.txt",ios::in);
          while (getline(temp,line)){
            status << line <<endl;
          }
          temp.close();
          status.close();
          cout << "Sucessful deleted.\n";
        }
        cout << "Press any key to go back. ";
        cin.get();
        cin.get();
        break;
      case 2:
        exit = true;
        break;
    }
  }


}
