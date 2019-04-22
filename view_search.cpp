#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include "datastructure.h"
using namespace std;

void view_search(){
  string shopcode;
  cout<<"Input the Shop ID that would like to search: ";
  cin>>shopcode;
  cout<<'\n';
  string statusfilename=shopid+"_status.txt";

  ifstream fin;
  fin.open(statusfilename.c_str());
  if (fin.fail()){
    cout<<"Unable to open commodity status file\n";
    exit(1);
  }
  int command;
  cout<<"Please enter command(1/2)"<<endl;
  cout<<"1.View through sorting by different columns"<<endl;
  cout<<"2.Search by different filters"<<endl;
  cout<<"3.Exit"<<end;
  cin>>command;
  while(command!=3){
    if (command==1){
      
    }
  }
}
