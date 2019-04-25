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
bool checkshop(string shopid){
  fstream shoplist;
  string line;
  char add;
  bool shopexist=false;
  shoplist.open("shoplist.txt",ios::in);
  while(getline(shoplist,line)){
    if(line==shopid)
      shopexist=true;
  }
  shoplist.close();
  shoplist.open("shoplist.txt",ios::app);
  if(!shopexist){
    cout << "Shop does not exist. Do you want to create shop " <<shopid <<" ?(Y/N) ";
    cin >> add;
    if(add=='Y')
      shoplist << shopid <<endl;
  }
  shoplist.close();
  if (shopexist || add=='Y')
    return true;
  else
    return false;
}
int main() {
  int command,threshold=30,numberofshop=0,cmd;
  string shopid,temp;
  bool add;
  bool bye=false,case7exit=false;

  while (!bye) {
    system("clear");
    if(shopid.empty()){
      do{
        cout<<"Enter your Shop ID: ";
        cin>>shopid;
        add=checkshop(shopid);
      }while(!add);
    }
    //system("clear");
    printmenu();
    alert(shopid,threshold);
    cout << "----------------------------------------\n";


    // place alert system here which pop notification when the volume reaches the threshol


    cout << "Please enter command (1-8): ";
    cin >> command;
    switch (command) {
      case 1:            //buy new item or procurement
        system("clear");
        procurement(shopid);
        break;
      case 2:            //update commodity info eg price name
        system("clear");
        update(shopid);
        break;
      case 3:           // view and search items
        //view_search();
        break;
      case 4:           //delete items
        system("clear");
        deleteitem(shopid);
        break;
      case 5:          //POS system, product sold out
        system("clear");
        pos(shopid);
        break;
      case 6:          //view monthly record
        //
        break;
      case 7:          //setting
        case7exit=false;
        while(!case7exit){
          system("clear");
          cout <<"1.Set notification\n";
          cout <<"2.Change shop ID\n";
          cout <<"3.Exit\n";
          cout << "Please enter command (1-3): ";
          cin >> cmd;
          switch (cmd) {
            case 1:
              cout << "Please enter the threshold (default 30) volume that triger the alert: ";
              cin >> threshold;
              break;
            case 2:
              cout << "Enter your shop ID: ";
              cin >> temp;
              if(checkshop(shopid)){
                shopid=temp;
                cout << "Sucessful change shop ID!\n";
                cout << "Press any key to go back. ";
                cin.get();
                cin.get();
              }

              break;
            case 3:
              case7exit=true;
              break;
          }
        }
        break;
      case 8: // Exit
        bye=true;
        cout << "Thanks for using, bye!\n";
        break;
    }
  }



  return 0;
}
