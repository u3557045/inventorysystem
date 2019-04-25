#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include "datastructure.h"
using namespace std;

void sorting(int command,int linenum,int order,itemstruct *array){
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
    element="status";

  for (int i=0;i<linenum-1;++i){
    for (int j=1;j<linenum;++j){
      itemstruct temp;
      if ((order==1)&&((array[i].element)>(array[j].element))){
        temp=array[i];
        array[i]=array[j];
        array[j]=temp;
      }
      if ((order==2)&&((array[i].element)<(array[j].element))){
        temp=array[i];
        array[i]=array[j];
        array[j]=temp;
      }

    }
  }
  for (int k=0;k<linenum;++k)
    cout<<array[k].id<<" "<<array[k].name<<" "<<array[k].category<<" "<<array[k].manufacturer<<" "<<array[k].price<<" "<<array[k].amount<<" "<<array[k].status<<" "<<endl;
}
