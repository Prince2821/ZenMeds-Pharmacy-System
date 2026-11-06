# ZenMeds Pharmacy System (CSE1001 Project)

*Course Name:* Introduction to Programming (CSE1001)  
*Languages Used:* C Programming & Basic HTML  

## 1. Aim
To design and implement a menu-driven Pharmacy Inventory and Patient Billing System (*ZenMeds*) in C using structures, arrays, loops, conditional branching, and file handling to generate HTML stock and receipt pages.

## 2. Problem Statement
Small pharmacies often record medicine stock and patient bills manually on paper, leading to slow billing, GST calculation errors, and unmonitored stock shortages. *ZenMeds* digitizes inventory management, flags medicines when stock drops below 5 units, and exports visual HTML pages (stock.html and bill.html) linked through a central dashboard (index.html).

## 3. Files in This Repository
* zenmeds.c - Core C program handling inventory, search, billing, and HTML file generation.
* index.html - Main pharmacy dashboard linking the live inventory and latest patient receipt.
* stock.html - Auto-generated webpage displaying live stock and low-stock alerts.
* bill.html - Auto-generated official patient receipt with 5% GST calculation.

## 4. C Programming Concepts Used
* *Structure (struct Med):* Groups id (int), name (char[30]), qty (int), and price (float).
* *Array of Structures (struct Med m[50]):* Stores up to 50 medicine records in memory.
* *Control Statements (if-else ladder & nested if):* Handles menu choices, stock checks (buyQty <= m[i].qty), and low-stock alerts (m[i].qty < 5).
* *Loops (do-while & for):* Repeats the interactive menu until exit (choice != 5) and traverses the medicine array.
* *File Handling (FILE *fp, fopen, fprintf, fclose):* Dynamically writes HTML tables into stock.html and bill.html.

## 5. Algorithm
1. *Start* the program and define struct Med with id, name, qty, and price.
2. Declare struct Med m[50] and initialize counter n = 0.
3. Display the ZenMeds menu inside a do-while loop and read choice:
   * *Choice 1 (Add Medicine):* Read medicine ID, name, quantity, and price into m[n] and increment n.
   * *Choice 2 (View Stock):* Loop from 0 to n-1, print details in the terminal, flag "LOW STOCK" if qty < 5, and write the table to stock.html.
   * *Choice 3 (Search Medicine):* Compare searchId against m[i].id using linear search and print matching details.
   * *Choice 4 (Make Bill):* Read patient name, searchId, and buyQty. If stock is sufficient, deduct buyQty from m[i].qty, add 5% GST (total + total * 0.05), and write the receipt to bill.html.
   * *Choice 5 (Exit):* Terminate the loop.
4. *Stop* the program.

## 6. Sample Terminal & HTML Output
text
=== ZENMEDS PHARMACY ===
1. Add Medicine
2. View Stock & Update HTML Stock Page
3. Search Medicine
4. Make Bill & HTML Receipt
5. Exit

Enter choice: 1
Enter Medicine ID: 114
Enter Medicine Name (one_word): dollo_650
Enter Quantity: 39
Enter Price: 56
Medicine added successfully!

Enter choice: 4
Enter Patient Name (one_word): kullu
Enter Medicine ID to buy: 114
Enter Quantity: 5

--- ZENMEDS BILL ---
Patient: kullu
Medicine: dollo_650
Quantity: 5
Total with 5% GST: Rs. 294.00
--> Webpage 'bill.html' updated! View it from index.html.

Enter choice: 2
ID      Name            Qty     Price   Status
114     dollo_650       34      56.00   AVAILABLE
--> Webpage 'stock.html' updated! View it from index.html.
