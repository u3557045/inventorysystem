#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
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
  int command;
  while (true) {
    printmenu();
    cout << "Please enter command (1-6): ";
    cin >> command;
    switch (command) {
      case 1:            //buy new item or procurement
        procurement();
        break;
      case 2:            //update commodity info eg price name
        //update();
        break;
      case 3:           // view and search items
        view_search();
        break;
      case 4:           //delete items
        //pos();
        break;
      case 5;          //POS system, product sold out
        //
        break;
      case 6;          //view monthly record
        //
        break;
    }
    system("clear");


  }



  return 0;
}
