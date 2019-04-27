//This function sorts an array of structs by certain column(command)
//It can sort in ascending or desceding order.Ascending when order==1, descending when order==2
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include "datastructure.h"
using namespace std;

void sorting(int command,int linenum,int order,itemstruct *array){

  //Sort by Product ID
  if (command==1){
    for (int i=0;i<linenum;++i){
      for (int j=0;j<linenum-i-1;++j){
        itemstruct temp;
        if ((order==1)&&((array[j].id)>(array[j+1].id))){    //sort by ascending order
          temp=array[j];
          array[j]=array[j+1];
          array[j+1]=temp;
        }
        else if ((order==2)&&((array[j].id)<(array[j+1].id))){    //sort by descending order
          temp=array[j];
          array[j]=array[j+1];

          array[j+1]=temp;
        }
      }
    }
  }
  //Sort by Product name
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
  //Sort by product category
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
  //Sort by Manufacturer
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
  //Sort by price
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
  //Sort by amount
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
  //Sort by product status(IN-STOCK/OUT-OF-STOCK)
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
