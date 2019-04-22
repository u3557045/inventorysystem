#include <string>
using namespace std;
struct catagorystruct{
  string id;
  string name;
};
struct itemstruct{
  idstruct productid;
  catagorystruct catagoryid;
  int amount;
  string shopid;
  string purchasedate;
};
struct idstruct{
  string id;
  string name;
};
