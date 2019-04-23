#ifndef ITEM
#define ITEM

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
void updatestatus(string filename,int field,string content,string id);
void update();
void procurement();


#endif
