# Smart Inventory System

## Problem Setting

### What is the problem?
When the commodity stack up, the inventory may become messy and difficult to monitor the inventory status. It is difficult determine when stock replenishment is needed.

### How does the system help managing the inventory?
With the aid of our system, staff would be able to examine the current status of the commodity and do some follow up actions.the smart inventory system provides an systematic approach to help increase the efficiency.

### What is this program?
The program is an integation of inventory database and user cilent. Using the user cilent, staff can update the database and retrive the inventory status from the database.

### Key Features
1. Search commodity in different shops using different filters and find information through sorting by column heading
2. Insert commodity information (name, manufacturer, amount, price, availability of shop(s)) after each
procurement
3. Delete obsolete commodity
4. Update commodity information
5. Automatic change of inventory status according to the amount of commodity that is currently available
6. Deliver alerts when the commodity is “OUT-OF-STOCK” and when the inventory for an item reaches the alert threshold
7. Give monthly reports of sales and inventory change
8. Customers order recording function, and automatically delete bought items in the inventory. The amount that needed to pay by the customers would be calculated

### How to use

```
make build
./build
```

## Implementation

### Data structure

We stored the inventory database into two different files, i.e. xxx_status.txt and xxx_transaction.txt, which handles the status of each unique item and records every transaction detail. Details are as follow.(<> represent a field)

#### Transaction file 

##### Procurement (i.e. postive amount)

###### Structure
````
<Product ID>|<Product Name>|<Category Name>|<Manufacturer>|<Unit Cost>|<Amount>|<Date> 
````
###### Example 
````
ID00001|Milk|Dairy|Waikei|100|10000|Thu Apr 25 22:55:49 2019
````
##### Selling (i.e. negative amount)

###### Structure
````
<Product ID>|<Product Name>|<Category Name>|<Manufacturer>|<Unit Selling Price>|<Amount>|<Date> 
````
###### Example 
````
ID00001|Milk|Dairy|Waikei|150|-2|Thu Apr 26 22:55:49 2019
````
#### Status file structure
````
<Product ID>|<Product Name>|<Category Name>|<Manufacturer>|<Selling Price>|<Amount>|<Status>
````
##### Example
````
ID00001|Milk|Dairy|Waikei|120|10000|IN-STOCK
ID00002|Milk tea|Dairy|Waikei|140|0|OUT-OF-STOCK
````

### Modules

#### Procurement 
This module allows the user to update the inventory when new item is bought and ready for sale. 
It requires the user to input the detail of the commodity.
The system will automatically store the detail into database and record the time of purchase.

#### Update Commoidity Info
This module allows the user to update the item detail which is already exist in the database in case of details erorrs or modification of price tag.

#### View and Search Item
This module allows the user to view the inventory status of different shop by appling different filters.

#### Delete Obsolete Commodity
This module allows the user to delete the commodity that is expired or not avavilble any more.

#### POS System
This module allows the staff to perform the checkout action. 
The system prompts the user to input the product ID and amount, then the system will output the total.
Once the staff confirms the transaction, it will be recorded.

#### View Monthly Record

