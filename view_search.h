#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include "datastructure.h"
#include "sorting.h"
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
  int linenum=0,count=0,position,n=0;
  itemstruct * dynamicarray=new itemstruct[linenum];
  while (getline(fin,line)){
    position=line.find("|",n)
    dynamicarray[count].id=line.substr(n,position);
    n=position+1;
    position=line.find("|",n);

    dynamicarray[count].name=line.substr(n,position);
    n=position+1;
    position=line.find("|",n);

    dynamicarray[count].category=line.substr(n,position);
    n=position+1;
    position=line.find("|",n);

    dynamicarray[count].manufacturer=line.substr(n,position);
    n=position+1;
    position=line.find("|",n);

    dynamicarray[count].price=line.substr(n,position);
    n=position+1;
    position=line.find("|",n);

    dynamicarray[count].amount=line.substr(n,position);
    n=position+1;
    position=line.find("|",n);

    dynamicarray[count].procurementdate=line.substr(n,position);
    n=position+1;

    dynamicarray[count].status=line.substr(n,position);

    n=0;
    position=0;
    count++;
  }



  int command;
  cout<<"Please enter command(1/2)"<<endl;
  cout<<"1.View through sorting by different columns"<<endl;
  cout<<"2.Search by different filters"<<endl;
  cout<<"3.Exit"<<end;
  cin>>command;
  while(command!=3){
    if (command==1){
      cout<<"Please enter command(1-7)"<<endl;
      cout<<"Sort by 1.Product ID 2.Product Name 3.Category 4.Manufacturer 5.Selling Price 6.Amount 7.Status\n"


    }
  }
}
