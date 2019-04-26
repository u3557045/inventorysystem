#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include "datastructure.h"
using namespace std;

void sorting(int command,int linenum,int order,itemstruct *array){
  string element;

  if (command==1){
    for (int i=0;i<linenum-1;++i){
      for (int j=1;j<linenum;++j){
        itemstruct temp;
        if ((order==1)&&((array[i].id)>(array[j].id))){
          temp=array[i];
          array[i]=array[j];
          array[j]=temp;
        }
        if ((order==2)&&((array[i].id)<(array[j].id))){
          temp=array[i];
          array[i]=array[j];

          array[j]=temp;
        }
      }
    }
  }
  if (command==2){
    for (int i=0;i<linenum-1;++i){
      for (int j=1;j<linenum;++j){
        itemstruct temp;
        if ((order==1)&&((array[i].name)>(array[j].name))){
          temp=array[i];
          array[i]=array[j];
          array[j]=temp;
        }
        if ((order==2)&&((array[i].name)<(array[j].name))){
          temp=array[i];
          array[i]=array[j];

          array[j]=temp;
        }
      }
    }
  }
  if (command==3){
    for (int i=0;i<linenum-1;++i){
      for (int j=1;j<linenum;++j){
        itemstruct temp;
        if ((order==1)&&((array[i].category)>(array[j].category))){
          temp=array[i];
          array[i]=array[j];
          array[j]=temp;
        }
        if ((order==2)&&((array[i].category)<(array[j].category))){
          temp=array[i];
          array[i]=array[j];

          array[j]=temp;
        }
      }
    }
  }
  if (command==4){
    for (int i=0;i<linenum-1;++i){
      for (int j=1;j<linenum;++j){
        itemstruct temp;
        if ((order==1)&&((array[i].manufacturer)>(array[j].manufacturer))){
          temp=array[i];
          array[i]=array[j];
          array[j]=temp;
        }
        if ((order==2)&&((array[i].manufacturer)<(array[j].manufacturer))){
          temp=array[i];
          array[i]=array[j];

          array[j]=temp;
        }
      }
    }
  }
  if (command==5){
    for (int i=0;i<linenum-1;++i){
      for (int j=1;j<linenum;++j){
        itemstruct temp;
        if ((order==1)&&((array[i].price)>(array[j].price))){
          temp=array[i];
          array[i]=array[j];
          array[j]=temp;
        }
        if ((order==2)&&((array[i].price)<(array[j].price))){
          temp=array[i];
          array[i]=array[j];

          array[j]=temp;
        }
      }
    }
  }
  if (command==6){
    for (int i=0;i<linenum-1;++i){
      for (int j=1;j<linenum;++j){
        itemstruct temp;
        if ((order==1)&&((array[i].amount)>(array[j].amount))){
          temp=array[i];
          array[i]=array[j];
          array[j]=temp;
        }
        if ((order==2)&&((array[i].amount)<(array[j].amount))){
          temp=array[i];
          array[i]=array[j];

          array[j]=temp;
        }
      }
    }
  }
  if (command==7){
    for (int i=0;i<linenum-1;++i){
      for (int j=1;j<linenum;++j){
        itemstruct temp;
        if ((order==1)&&((array[i].status)>(array[j].status))){
          temp=array[i];
          array[i]=array[j];
          array[j]=temp;
        }
        if ((order==2)&&((array[i].status)<(array[j].status))){
          temp=array[i];
          array[i]=array[j];

          array[j]=temp;
        }
      }
    }
  }
  for (int k=0;k<linenum;++k)
    cout<<array[k].id<<" "<<array[k].name<<" "<<array[k].category<<" "<<array[k].manufacturer<<" "<<array[k].price<<" "<<array[k].amount<<" "<<array[k].status<<" "<<endl;
}
