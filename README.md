# Smart Inventory System

## Problem Setting

### What is the problem?
When the commodity stack up, the inventory may become messy and difficult to monitor the inventory status. It is difficult determine when stock replenishment is needed.

### How does the system help managing the inventory?
With the aid of our system, staff would be able to examine the current status of the commodity and do some follow up actions.the smart inventory system provides an systematic approach to help increase the efficiency.

### What is this program?
The program is an integation of inventory database and user cilent. Using the user cilent, staff can update the database and retrive the inventory status from the database.

### Key Features
1. Search commodity using different filters and find information through sorting by column heading
2. Insert commodity information (name, manufacturer, amount, price, availability of shop(s)) after each
procurement
3. Delete obsolete commodity
4. Update commodity information
5. Automatic change of inventory status according to the amount of commodity that is currently available
6. Deliver alerts when the commodity is “OUT-OF-STOCK” and when the inventory for an item reaches the alert threshold
7. Give reports of monthly/yearly inventory change
8. Customers order recording function, and automatically delete bought items in the inventory. The amount that needed to pay by the customers would be calculated

## Implementation

### Transaction 
````
<Product ID>|<Product Name>|<Category Name>|<Manufacturer>|<Unit Price>|<Amount>|<Date> 
````
##### Procurement Example (i.e. postive amount)
````
ID00001|Milk|Dairy|Waikei|100|10000|Thu Apr 25 22:55:49 2019
````
#### Selling Example (i.e. negative amount)
````
ID00001|Milk|Dairy|Waikei|120|-8|Thu Apr 26 22:55:49 2019
````
### Status
````
<Product ID>|<Product Name>|<Category Name>|<Manufacturer>|<Selling Price>|<Amount>|<Status>
````
#### Example
````
ID00001|Milk|Dairy|Waikei|120|10000|IN-STOCK
ID00002|Milk tea|Dairy|Waikei|140|0|OUT-OF-STOCK
````
 

