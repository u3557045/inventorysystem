#include <iostream>
#include "datastructure.h"
#include <fstream>
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
  int command,threshold;
  while (true) {
    printmenu();


    // place alert system here which pop notification when the volume reaches the threshol


    cout << "Please enter command (1-6): ";
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
        cout << "Please enter the threshold volume that triger the alert: ";
        cin >> threshold;
        break;
    }

  }



  return 0;
}
