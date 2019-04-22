#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>
#include "updatestatus.h"
using namespace std;

void procurement(){
  time_t tt;
  struct tm*ti;

  int number_insert;
  string shopid;
  ofstream sfout;
  ofstream tfout;
  cout<<"Enter your Shop ID";
  cin>>shopid;
  cout<<'\n';
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
  string productid,productname,categoryid,categoryname,price,manufacturer;
  int amount;

  for (int i=0;i<number_insert;++i){
    cout<<"Has the item been procured before?";
    cin>>itemexist;
    cout<<'\n';

    cout<<"Enter Product ID: ";
    cin>>productid;
    cout<<endl;
    cout<<"Enter Product Name: ";
    cin>>productname;
    cout<<endl;
    cout<<"Enter Category ID: ";
    cin>>categoryid;
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

    if (itemexist=="No"){
      //append into files
      sfout<<productid<<"|"<<productname<<"|"<<categoryid<<"|"<<categoryname<<"|"<<manufacturer<<"|"<<price<<"|"<<amount<<"|IN-STOCK\n";
      time(&tt);
      ti=localtime(&tt);
      tfout<<productid<<"|"<<productname<<"|"<<categoryid<<"|"<<categoryname<<"|"<<manufacturer<<"|"<<price<<"|"<<amount<<"|"<<asctime(ti)<<'\n';
    }
    if (itemexist=="Yes"){
      time(&tt);
      ti=localtime(&tt);
      tfout<<productid<<"|"<<productname<<"|"<<categoryid<<"|"<<categoryname<<"|"<<manufacturer<<"|"<<price<<"|"<<amount<<"|"<<asctime(ti)<<'\n';
      //change item status in status.txt
      updatestatus(productid,amount);
    }
  }
  delete ti;
  sfout.close();
  tfout.close();
}
