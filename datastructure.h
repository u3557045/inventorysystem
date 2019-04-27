#ifndef STRUCT_H
#define STRUCT_H
#include <string>
using namespace std;
struct itemstruct{
  string id;
  string name;
  string category;
  string manufacturer;
  double price;
  int amount;
  string procurementdate;
  string status;
};
void update(string shopid);
void procurement(string shopid);
void updatestatus(string filename,int field,string content,string id);
void alert(string id,int threshold);
void pos(string shopid);
void deleteitem(string shopid);
void view_record(string shopid);
void sorting(int command,int linenum,int order,itemstruct *array);
void view_search();
void sorting(int command,int linenum,int order,itemstruct *array);
string checkid(string line);
string checkprice(string filename,string productid);
string checkamount(string filename, string productid);
#endif
