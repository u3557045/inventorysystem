#include <iostream>
#include <fstream>
#include "datastructure.h"
using namespace std;
// display the menu
void printmenu(){
  cout << "----------------------------------------\n";
  cout << "----------Smart Inventory System--------\n";
  cout << "----------------------------------------\n";
  cout << " 1.Procurement\n";
  cout << " 2.Update Commodity Info\n";
  cout << " 3.View and Search Items\n";
  cout << " 4.Delete obsolete commodity\n";
  cout << " 5.POS System\n";
  cout << " 6.View Monthly Record\n";
  cout << " 7.Setting\n";
  cout << " 8.Exit\n";
  cout << "---------------------------------------\n";
}

//put the shop id to the shoplist.txt to represent the existance of the shop
void creatnewshop(string shopid){
  ofstream snew,tnew;
  string statusfilename,transactionfilename;
  statusfilename=shopid+"_status.txt";
  transactionfilename=shopid+"_transaction.txt";
  snew.open(statusfilename.c_str());
  tnew.open(transactionfilename.c_str());
  snew.close();
  tnew.close();

}

//check the existance of the shop by reading through the shoplist.txt
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
    if(add=='Y'){
      shoplist << shopid <<endl;
      creatnewshop(shopid);
    }

  }
  shoplist.close();
  if (shopexist || add=='Y')
    return true;
  else
    return false;
}
int main() {
  int threshold=30,numberofshop=0;
  string shopid,temp,command,cmd;
  bool add;
  bool bye=false,case7exit=false;

  while (!bye) {
    system("clear");
    if(shopid.empty()){
      do{
        cout<<"Enter your Shop ID: ";
        cin>>shopid; // the input is a string of shopid
        add=checkshop(shopid);
      }while(!add);
    }
    printmenu();

    //alert function which pop notification on the mai screeen which the volume is below the threshold
    alert(shopid,threshold);
    cout << "----------------------------------------\n";




    do{
      cout << "Please enter command (1-8): ";
      cin >> command; // the input is an integer from 1 to 8
    }while(command<"1" || command>"8");

    switch (stoi(command)) {
      case 1:            //buy new item or procurement
        system("clear");
        procurement(shopid);
        break;
      case 2:            //update commodity info eg price name
        system("clear");
        update(shopid);
        break;
      case 3:
        system("clear");    // view and search items
        view_search();
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
        system("clear");
        view_record(shopid);
        break;
      case 7:          //setting
        case7exit=false;
        while(!case7exit){
          system("clear");
          cout <<"1.Set notification\n";
          cout <<"2.Change shop ID\n";
          cout <<"3.Exit\n";
          do{
            cout << "Please enter command (1-3): ";
            cin >> cmd; //the input is an integer from 1 to 3
          }while(cmd<"1"||cmd>"3");

          switch (stoi(cmd)) {

            // set threshold of the alert system
            case 1:
              cout << "Please enter the threshold (default 30) volume that triger the alert: ";
              cin >> threshold; //the input is an integer
              break;
            // change the shop id that you want to perform operation
            case 2:
              cout << "Enter your shop ID: ";
              cin >> temp; // input is a string of shopid
              if(checkshop(temp)){
                shopid=temp;
                cout << "Sucessfully changed shop ID!\n";
                cout << "Press any key to go back. \n";
                cin.get();
                cin.get();
              }

              break;
            case 3:
              case7exit=true;
              break;
            default:
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
