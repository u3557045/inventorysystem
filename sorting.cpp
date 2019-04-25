#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include "datastructure.h"
using namespace std;

void sorting(int command,int linenum,int order){
  string element;
  if (command==1)
    element="id";
  if (command==2)
    element="name";
  if (command==3)
    element="category";
  if (command==4)
    element="manufacturer";
  if (command==5)
    element="price";
  if (command==6)
    element="amount";
  if (command==7)
    element=="status";

  for (int i=0;i<linenum-1;++i){
    for (int j=0;j<linenum;++j){
      int temp;
      if ()
    }
  }
}
