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

  //open shoplist file
  ifstream fin;
  finlist.open(shoplist.txt);
  if (fin.fail()){
    cout<<"Unable to open shop list file\n";
    exit(1);
  }
  //check whether the shop id already exists
  bool exist=false;
  while (exist==false){
    while (getline(finlist,shopline)){
      if (shopline==shopcode)
        exist=true;
    }
    if (exist==false){
      cout<<"Shop id does not exist, please enter shop id again: "<<endl;
      cin>>shopcode;}
  }
  finlist.close();


  string statusfilename=shopid+"_status.txt";

  ifstream fin;
  fin.open(statusfilename.c_str());
  if (fin.fail()){
    cout<<"Unable to open commodity status file\n";
    exit(1);
  }

  //input information into the dynamic array of structs
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
  fin.close();

  int command,sortcommand,ascenddescend;
  cout<<"Please enter command(1-2)"<<endl;
  cout<<"1.View through sorting by different columns"<<endl;
  cout<<"2.Search by different filters"<<endl;
  cout<<"3.Exit"<<end;
  cin>>command;
  while(command!=3){
    if (command==1){
      cout<<"Please enter command(1-7)"<<endl;
      cout<<"Sort by 1.Product ID 2.Product Name 3.Category 4.Manufacturer 5.Selling Price 6.Amount 7.Status\n"
      cin>>sortcommand;
      cout<<"Sort in 1.ascending or 2.descending order?(1/2) ";
      cin>>ascenddescend;
      cout<<endl;
      sorting(sortcommand,count,ascenddescend,dynamicarray);
    }
    else if (command==2){
      string filter;
      cout<<"Search by only showing: "
      cin>>filter;
      for (int k=0;k<count;++k){
        dynamicarray[k].price= string dynamicarray[k].price;
        dynamicarray[k].amount=string dynamicarray[k].amount;
        if (filter==dynamicarray[k].id||filter==dynamicarray[k].name||filter==dynamicarray[k].category||filter==dynamicarray[k].manufacturer||filter==dynamicarray[k].price||filter==dynamicarray[k].amount||filter==dynamicarray[k].status)
          cout<<dynamicarray[k].id<<" "<<dynamicarray[k].name<<" "<<dynamicarray[k].category<<" "<<dynamicarray[k].manufacturer<<" "<<dynamicarray[k].price<<" "<<dynamicarray[k].amount<<" "<<dynamicarray[k].status<<" "<<endl;
      }
    }
  }
  delete [] dynamicarray;
}
