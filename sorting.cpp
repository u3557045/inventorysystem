#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include "datastructure.h"
using namespace std;

void sorting(int command,int linenum,int order,itemstruct *array){

  if (command==1){
    for (int i=0;i<linenum;++i){
      for (int j=0;j<linenum-i-1;++j){
        itemstruct temp;
        if ((order==1)&&((array[j].id)>(array[j+1].id))){
          temp=array[j];
          array[j]=array[j+1];
          array[j+1]=temp;
        }
        else if ((order==2)&&((array[j].id)<(array[j+1].id))){
          temp=array[j];
          array[j]=array[j+1];

          array[j+1]=temp;
        }
      }
    }
  }
  if (command==2){
    for (int i=0;i<linenum;++i){
      for (int j=0;j<linenum-i-1;++j){
        itemstruct temp;
        if ((order==1)&&((array[j].name)>(array[j+1].name))){
          temp=array[j];
          array[j]=array[j+1];
          array[j+1]=temp;
        }
        else if ((order==2)&&((array[j].name)<(array[j+1].name))){
          temp=array[j];
          array[j]=array[j+1];

          array[j+1]=temp;
        }
      }
    }
  }
  if (command==3){
    for (int i=0;i<linenum;++i){
      for (int j=0;j<linenum-i-1;++j){
        itemstruct temp;
        if ((order==1)&&((array[j].category)>(array[j+1].category))){
          temp=array[j];
          array[j]=array[j+1];
          array[j+1]=temp;
        }
        else if ((order==2)&&((array[j].category)<(array[j+1].category))){
          temp=array[j];
          array[j]=array[j+1];

          array[j+1]=temp;
        }
      }
    }
  }
  if (command==4){
    for (int i=0;i<linenum;++i){
      for (int j=0;j<linenum-i-1;++j){
        itemstruct temp;
        if ((order==1)&&((array[j].manufacturer)>(array[j+1].manufacturer))){
          temp=array[j];
          array[j]=array[j+1];
          array[j+1]=temp;
        }
        else if ((order==2)&&((array[j].manufacturer)<(array[j+1].manufacturer))){
          temp=array[j];
          array[j]=array[j+1];

          array[j+1]=temp;
        }
      }
    }
  }
  if (command==5){
    for (int i=0;i<linenum;++i){
      for (int j=0;j<linenum-i-1;++j){
        itemstruct temp;
        if ((order==1)&&((array[j].price)>(array[j+1].price))){
          temp=array[j];
          array[j]=array[j+1];
          array[j+1]=temp;
        }
        else if ((order==2)&&((array[j].price)<(array[j+1].price))){
          temp=array[j];
          array[j]=array[j+1];

          array[j+1]=temp;
        }
      }
    }
  }
  if (command==6){
    for (int i=0;i<linenum;++i){
      for (int j=0;j<linenum-i-1;++j){
        itemstruct temp;
        if ((order==1)&&((array[j].amount)>(array[j+1].amount))){
          temp=array[j];
          array[j]=array[j+1];
          array[j+1]=temp;
        }
        else if ((order==2)&&((array[j].amount)<(array[j+1].amount))){
          temp=array[j];
          array[j]=array[j+1];

          array[j+1]=temp;
        }
      }
    }
  }
  if (command==7){
    for (int i=0;i<linenum;++i){
      for (int j=0;j<linenum-i-1;++j){
        itemstruct temp;
        if ((order==1)&&((array[j].status)>(array[j+1].status))){
          temp=array[j];
          array[j]=array[j+1];
          array[j+1]=temp;
        }
        else if ((order==2)&&((array[j].status)<(array[j+1].status))){
          temp=array[j];
          array[j]=array[j+1];

          array[j+1]=temp;
        }
      }
    }
  }

  
}
