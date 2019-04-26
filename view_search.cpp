#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include "datastructure.h"
using namespace std;
void view_search(){
  string shopcode;
  cout<<"Input the Shop ID you would like to search: ";
  cin>>shopcode;
  cout<<'\n';

  //open shoplist file
  ifstream finlist;
  finlist.open("shoplist.txt");
  if (finlist.fail()){
    cout<<"Unable to open shop list file\n";
    exit(1);
  }
  //check whether the shop id already exists
  string shopline;
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

  string statusfilename=shopcode+"_status.txt";

  ifstream fin;
  fin.open(statusfilename.c_str());
  if (fin.fail()){
    cout<<"Unable to open commodity status file\n";
    exit(1);
  }
  string line;
  //input information into the dynamic array of structs
  int linenum=0,count=0,position=0,n=0,substrlength;
  while (getline(fin,line))
    linenum+=1;
  itemstruct * dynamicarray=new itemstruct[linenum];
  fin.close();

  fin.open(statusfilename.c_str());
  if (fin.fail()){
    cout<<"Unable to open commodity status file\n";
    exit(1);
  }
  while (getline(fin,line)){
    position=line.find("|",n);
    substrlength=position-n;
    dynamicarray[count].id=line.substr(n,substrlength);
    n=position+1;
    position=line.find("|",n);

    substrlength=position-n;
    dynamicarray[count].name=line.substr(n,substrlength);
    n=position+1;
    position=line.find("|",n);

    substrlength=position-n;
    dynamicarray[count].category=line.substr(n,substrlength);
    n=position+1;
    position=line.find("|",n);

    substrlength=position-n;
    dynamicarray[count].manufacturer=line.substr(n,substrlength);
    n=position+1;
    position=line.find("|",n);

    substrlength=position-n;
    int intprice=atoi((line.substr(n,substrlength)).c_str());
    dynamicarray[count].price=intprice;
    n=position+1;
    position=line.find("|",n);

    substrlength=position-n;
    int intamount=atoi((line.substr(n,substrlength)).c_str());
    dynamicarray[count].amount=intamount;
    n=position+1;
    position=line.find("|",n);

    substrlength=position-n;
    dynamicarray[count].status=line.substr(n,8);

    n=0;
    position=0;
    count++;
  }
  fin.close();

  int command,sortcommand,ascenddescend;
  cout<<"1.View through sorting by different columns"<<endl;
  cout<<"2.Search commodity"<<endl;
  cout<<"3.Exit"<<endl;
  cout<<"Please enter command(1-3): ";
  cin>>command;
  cout<<endl;
  while(command!=3){
    if (command==1){
      cout<<"Sort by \n1.Product ID \n2.Product Name \n3.Category \n4.Manufacturer \n5.Selling Price \n6.Amount \n7.Status\n";
      cout<<"Please enter command(1-7): ";
      cin>>sortcommand;
      cout<<endl;
      cout<<"Sort in 1.ascending or 2.descending order?(1/2) ";
      cin>>ascenddescend;
      cout<<endl;
      sorting(sortcommand,count,ascenddescend,dynamicarray);
      cout<<"Product ID\t"<<"Product Name\t"<<"Category Name\t"<<"Manufacturer\t"<<"Selling Price\t"<<"Amount\t"<<"Status\n";
      for (int k=0;k<linenum;++k)
        cout<<dynamicarray[k].id<<"\t\t"<<dynamicarray[k].name<<"\t\t"<<dynamicarray[k].category<<"\t\t"<<dynamicarray[k].manufacturer<<"\t\t"<<dynamicarray[k].price<<"\t\t"<<dynamicarray[k].amount<<'\t'<<dynamicarray[k].status<<'\n'<<endl;
    }
    else if (command==2){
      string filter;
      bool checkex=false;
      cout<<"Search: ";
      cin>>filter;
      string price,amount;
      int countsearch=0;
      while (checkex==false){
        for (int k=0;k<count;++k){
          if (filter==dynamicarray[k].id||filter==dynamicarray[k].name||filter==dynamicarray[k].category||filter==dynamicarray[k].manufacturer||filter==dynamicarray[k].status){
            checkex=true;
            countsearch++;
            if (countsearch==1&&(checkex==true))
              cout<<"Product ID\t"<<"Product Name\t"<<"Category Name\t"<<"Manufacturer\t"<<"Selling Price\t"<<"Amount\t"<<"Status\n";
            cout<<dynamicarray[k].id<<"\t\t"<<dynamicarray[k].name<<"\t\t"<<dynamicarray[k].category<<"\t\t"<<dynamicarray[k].manufacturer<<"\t\t"<<dynamicarray[k].price<<"\t\t"<<dynamicarray[k].amount<<'\t'<<dynamicarray[k].status<<'\n'<<endl;
          }
        }
        if (checkex==false){
          cout<<"Such item does not exist, please search again: ";
          cin>>filter;
          cout<<endl;
        }
      }
    }
    cout<<"Press any key to continue\n";
    cin.get();
    cin.get();
    system("clear");

    cout<<"1.View through sorting by different columns"<<endl;
    cout<<"2.Search by different filters"<<endl;
    cout<<"3.Exit"<<endl;
    cout<<"Please enter command(1-3): ";
    cin>>command;
    cout<<endl;
  }
  delete [] dynamicarray;
}
