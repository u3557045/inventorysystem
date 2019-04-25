#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <ctime>
#include "datastructure.h"
using namespace std;

void procurement(string shopid){
  time_t tt;
  struct tm*ti;
  int number_insert;
  ofstream sfout;
  ofstream tfout;
  string statusfilename=shopid+"_status.txt";
  string tranfilename=shopid+"_transection.txt";

  //Open shop status file
  sfout.open(statusfilename.c_str(), ios::app);
  if (sfout.fail()){
    cout<< "Unable to open commodity status file\n";
    exit(1);
  }
  //Open shop transection file
  tfout.open(tranfilename.c_str(), ios::app);
  if (tfout.fail()){
    cout<< "Unable to open transection file\n";
    exit(1);
  }

  cout<<"Enter the number of items that you would like to insert: ";
  cin>>number_insert;
  cout<<'\n';

  string itemexist;
  string productid,productname,categoryname,price,manufacturer;
  int amount,sellingprice;

  for (int i=0;i<number_insert;++i){
    cout<<"Has the item been procured before? (Yes/No)";
    cin>>itemexist;
    cout<<'\n';

    cout<<"Enter Product ID: ";
    cin>>productid;
    cout<<endl;
    cout<<"Enter Product Name: ";
    cin>>productname;
    cout<<endl;
    cout<<"Enter Category Name: ";
    cin>>categoryname;
    cout<<endl;
    cout<<"Enter Unit Price: ";
    cin>>price;
    cout<<endl;
    cout<<"Enter Amount: ";
    cin>>amount;
    cout<<endl;
    cout<<"Enter Manufacturer: ";
    cin>>manufacturer;
    cout<<endl;
    cout<<"Enter Selling Price: ";
    cin>>sellingprice;
    cout<<endl;

    if (itemexist=="No"){
      //append into files
      sfout<<productid<<"|"<<productname<<"|"<<categoryname<<"|"<<manufacturer<<"|"<<sellingprice<<"|"<<amount<<"|IN-STOCK\n";
      time(&tt);
      ti=localtime(&tt);
      tfout<<productid<<"|"<<productname<<"|"<<categoryname<<"|"<<manufacturer<<"|"<<price<<"|"<<amount<<"|"<<asctime(ti)<<'\n';
    }
    if (itemexist=="Yes"){
      time(&tt);
      ti=localtime(&tt);
      tfout<<productid<<"|"<<productname<<"|"<<categoryname<<"|"<<manufacturer<<"|"<<price<<"|"<<amount<<"|"<<asctime(ti)<<'\n';
      //change item status in status.txt
      updatestatus(statusfilename,6,to_string(amount),productid);
    }
  }
  delete ti;
  sfout.close();
  tfout.close();
}
