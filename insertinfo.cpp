#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <stdlib.h>
#include "updatestatus.h"
using namespace std;

void insertinfo(){
  int number_insert;
  string shopid;
  ofstream fout;
  cout<<"Enter your Shop ID";
  cin>>shopid;
  cout>>'\n';
  string filename=shopid+"_status.txt";

  //Append to info file
  fout.open(filename.c_str(), ios::app);
  if (fout.fail()){
    cout<< "Unable to open commodity information file\n";
    exit(1);
  }
  cout<<"Enter the number of items that you would like to insert: ";
  cin<<	number_insert;
  cout<<'\n';
  for (int i=0;i<number_insert;++i){
    cout<<"Enter each item in the order of [Product ID,Product Name,Catagory ID,Catagory Name,Manufacturer,Price,Amount,Shop ID,Date of purchase]\n";

  }

}
