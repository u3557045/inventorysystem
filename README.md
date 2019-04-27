# Smart Inventory System

## Problem Setting

### What is the problem?
When the commodity stack up, the inventory may become messy and difficult to monitor the inventory status. It is difficult determine when stock replenishment is needed.

### How does the system help managing the inventory?
With the aid of our system, staff would be able to examine the current status of the commodity in different shops and do some follow up actions.the smart inventory system provides an systematic approach to help increase the efficiency.

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
You can use test as the shop ID for testing, where test_status.txt and test_transaction contain the sample database.

## Implementation

### Data structure

We stored the inventory database into two different files, i.e. xxx_status.txt and xxx_transaction.txt, which handles the status of each unique item and records every transaction detail. Details are as follow.(<> represent a field)
Each individual shops have two files.

### Transaction file (Recording every inventory change)
#### Procurement (i.e. postive amount)
##### Structure
````
<Product ID>|<Product Name>|<Category Name>|<Manufacturer>|<Unit Cost>|<Amount>|<Date> 
````
###### Example 
````
ID00001|Milk|Dairy|Waikei|100|10000|Thu Apr 25 22:55:49 2019
````
#### Selling (i.e. negative amount)
##### Structure
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

## Modules

#### Procurement 
This module allows the user to update the inventory when new items are bought and ready for sale. 
It requires the user to input the detail of the commodity.
The system will automatically store the detail into database and record the time of purchase, inputting data into transaction file and status file.

#### Update Commoidity Info
This module allows the user to update the item details which already exist in the database in case of details erorrs or modification of price tag.


#### View and Search Item
This module allows the user to choose which branch store inventory status he/she would like to view.
It allows the user to search(Product ID/Product Name/Category Name/Manufacturer/Status) in the inventory status, and view the inventory status by sorting different columns.
````
Please use fullscreen to obtain the best result
````

#### Delete Obsolete Commodity
This module allows the user to delete the commodity that is expired or not avavilble any more.

#### POS System
This module allows the staff to perform a checkout action. 
The system prompts the user to input the product ID and amount, then the system will output the total.
Once the staff confirms the transaction, it will be recorded.
If the product that customer wants is out-of-stock, the system will show which branch stores in other locatons have the product.

#### View Monthly Record
This module allows user the get the summary of the transaction in a month, like inventory change or gross profit.
Also it provides the staff of information which item is best selling or profit making.

#### Alert system
When a commodity stock amount in the user's branch store reaches the threshold amount(default 30) or becoming out-of-stock, an alert will appear once the user open the menu interface. The threshold amount could be modified in the setting.

#### Setting
1. Change the threshold amount for the alert system
2. Change Shop ID
