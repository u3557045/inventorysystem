#ifndef STRUCT_H
#define STRUCT_H
#include <string>
using namespace std;
struct itemstruct{
  string id;
  string name;
  string category;
  string manufacturer;
  int price;
  int amount;
  string procurementdate;
  string status;
};
void update();
void procurement();
void updatestatus(string filename,int field,string content,string id);
#endif
