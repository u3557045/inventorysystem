#include <string>
#include <iostream>
#include "datastructure.h"
using namespace std;

void update(string shopid){
  string id,status,transaction,choice;
  bool exit=false;
  status=shopid+"_status.txt";
  transaction=shopid+"_transaction.txt";
  cout << "Please enter the ID of the product that you want to modify:"; //input is string of product ID
  itemstruct item;
  cin >> item.id;
  while(true && !exit){
    system("clear");
    cout << "Please choose the info you want to change:\n";
    cout << "1.Product Name\n";
    cout << "2.Selling price\n";
    cout << "3.Category Name\n";
    cout << "4.Manufacturer\n";
    cout << "5.Exit\n";
    //simple input vaildation
    do{
      cout << "Please enter command (1-5): ";
      cin >> choice; //input is an integer from 1 to 5
    }while(choice<"1" || choice>"5");

    //use a numerical variable choice to limit the field that subject to change
    switch (stoi(choice)) {
      case 1:
        cout << "Please enter the name after modification: ";
        cin>>item.name;
        updatestatus(status,2,item.name,item.id);
        updatestatus(transaction,2,item.name,item.id);
        cout<<"Information is sucessfully updated.\nPress any key to continue.";
        cin.get();
        cin.get();
        break;
      case 2:
        cout << "Please enter the selling price after modification: ";
        cin>>item.price;
        updatestatus(status,5,item.name,item.id);
        cout<<"Information is sucessfully updated.\nPress any key to continue.";
        cin.get();
        cin.get();
        break;
      case 3:
        cout << "Please enter the category name after modification: ";
        cin>>item.category;
        updatestatus(status,3,item.category,item.id);
        updatestatus(transaction,3,item.category,item.id);
        cout<<"Information is sucessfully updated.\nPress any key to continue.";
        cin.get();
        cin.get();
        break;
      case 4:
        cout << "Please enter the manufacturer after modification: ";
        cin>>item.manufacturer;
        updatestatus(status,5,item.manufacturer,item.id);
        updatestatus(transaction,5,item.manufacturer,item.id);
        cout<<"Information is sucessfully updated.\nPress any key to continue.";
        cin.get();
        cin.get();
        break;
      case 5:
        exit = true;
        break;
    }
  }
}
