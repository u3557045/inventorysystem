#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

void updatestatus(string filename,string productid,int amountprocured){
  fstream inoutfile;
  inoutfile.open(filename.c_str(),ios::app|ios::out);
  if (inoutfile.fail()){
    cout<<"Unable to open commodity status file\n";
    exit(1);
  }

int idpos,amountpos;
  while (getline(inoutfile,line)){
    //find the place of product id
    idpos=line.find("|");
    if (line.substr(0,idpos)==productid){

    }
  }

}
