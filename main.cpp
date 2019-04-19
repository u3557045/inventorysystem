#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <stdlib.h>
#include 
using namespace std;

int main() {
  int command;

  while (true) {
    cout<<"************************************************************\n";
    cout<<"Enter 1 to Insert New Commodity Information\n";
    cout<<"Enter 2 to Edit and Update Commodity Information\n";
    cout<<"Enter 3 to View and Search Items\n";
    cout<<"Enter 4 to Delete obsolete commodity\n";
    cout<<"Enter 5 to Enter the POS System\n";
    cout<<"Enter 6 to View Monthly Inventory Change Record\n";
    cout<<"************************************************************\n";
    cin>>command;

    if (command==1){
      insertinfo();
    }
    else if (command==2) {
      editinfo();
    }
    else if (command==3){

    }

  }



  return 0;
}
