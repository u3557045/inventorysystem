#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <stdlib.h>
#include "updatestatus.h"
using namespace std;

void procurement(){
  int number_insert;
  string shopid;
  ofstream sfout;
  ofstream tfout;
  cout<<"Enter your Shop ID";
  cin>>shopid;
  cout>>'\n';
  string statusfilename=shopid+"_status.txt";
  string tranfilename=shopid+"_transection.txt";

  //Open shop status file
  sfout.open(statusfilename.c_str(), ios::app);
  if (fout.fail()){
    cout<< "Unable to open commodity status file\n";
    exit(1);
  }
  //Open shop transection file
  tfout.open(tranfilename.c_str(), ios::app);
  if (fout.fail()){
    cout<< "Unable to open transection file\n";
    exit(1);
  }

  cout<<"Enter the number of items that you would like to insert: ";
  cin<<	number_insert;
  cout<<'\n';

  string yesorno;
  for (int i=0;i<number_insert;++i){
    cout<<"Has the item been procured before?"
    cin>>yesorno;
    cout<<'\n';
    if (yesorno=="No"){
      cout<<"Enter the item in the order of [Product ID,Product Name,Catagory ID,Catagory Name,Manufacturer,Unit Price,Amount]\n";

    }
  }

}
