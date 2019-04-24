#include <iostream>
#include <fstream>
#include "datastructure.h"
using namespace std;
void printmenu(){
  string line;
  ifstream menu;
  menu.open("menu.txt");
  if(menu.fail()){
    cout << "Unable the open menu file" << endl;
    exit(1);
  }
  while(getline(menu,line)){
    cout << line << endl;
  }
}
int main() {
  int command,threshold=0,numberofshop=0;
  string trackid="0";
  bool bye=false;
  while (!bye) {
    system("clear");
    printmenu();
    alert(trackid,threshold);
    cout << "----------------------------------------\n";


    // place alert system here which pop notification when the volume reaches the threshol


    cout << "Please enter command (1-8): ";
    cin >> command;
    switch (command) {
      case 1:            //buy new item or procurement
        system("clear");
        procurement();
        break;
      case 2:            //update commodity info eg price name
        system("clear");
        update();
        break;
      case 3:           // view and search items
        //view_search();
        break;
      case 4:           //delete items
        //
        break;
      case 5:          //POS system, product sold out
        //pos();
        break;
      case 6:          //view monthly record
        //
        break;
      case 7:          //setting
        system("clear");
        cout << "Please enter the shop ID that you want to track: ";
        cin >> trackid;
        cout << "Please enter the threshold (default 0) volume that triger the alert: ";
        cin >> threshold;
        break;
      case 8: // Exit
        bye=true;
        cout << "Thanks for using, bye!\n";
        break;
    }
  }



  return 0;
}
