#include <string>
using namespace std;
struct idstruct{
  string id;
  string name;
};
struct itemstruct{
  idstruct productid;
  string category;
  string manufacturer;
  int price;
  int amount;
  string shopid;
  string procurementdate;
  string status;
};
