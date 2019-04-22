#include <iostream>
#include <fstream>
#include <string>
#include "datastructure.h"
#include <sstream>
#include "updatestatus.h"
using namespace std;
void update(){
  string id,shopid,status,transection;
  int choice;
  bool exit=false;
  cout << "Plesae enter the shop ID: ";
  cin >> shopid;
  status=shopid+"_status.txt";
  transection=shopid+"_transection.txt";
  cout << "Please enter the ID of the product that you want to modify:";
  itemstruct item;

  cin >> item.productid.id;
  while(true && !exit){
    cout << "Please choose the info you want to change:\n";
    cout << "1.Product Name\n";
    cout << "2.Selling price\n";
    cout << "3.Category Name\n"
    cout << "4.Manufacturer\n";
    cout << "5.Exit\n";
    cin >> choice;
    switch (choice) {
      case 1:
        cout >> "Please enter the name after modification: ";
        cin>>item.productid.name;
        updatestatus(status,2,item.productid.name,item.productid.id);
        updatestatus(transection,2,item.productid.name,item.productid.id);
        break;
      case 2:
        cout >> "Please enter the selling price after modification: ";
        cin>>item.price;
        updatestatus(status,5,item.productid.name,item.productid.id);
        break;
      case 3:
        cout >> "Please enter the category name after modification: ";
        cin>>item.categoryid.name;
        updatestatus(status,3,item.category,item.productid.id);
        updatestatus(transection,3,item.category,item.productid.id);
        break;
      case 4:
        cout >> "Please enter the manufacturer after modification: "
        cin>>item.manufacturer;
        updatestatus(status,5,item.manufacturer,item.productid.id);
        updatestatus(transection,5,item.manufacturer,item.productid.id);
      case 5:
        exit = true;
        break;
    }
  }




}
