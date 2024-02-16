# 🍴 Restaurant Simulator
THis is a project made in C++ that can be compared to an application for placing a food order.

# 📌 Steps
1. The menu is displayed (separate menus for main course, appetizer, pizza, pasta) and drinks
2. The user can navigate between menus as many times as he wants. They can view the order, delete what they don't want to order and access a frequently asked questions section
3. After confirming the order, he must authenticate based on an email taken from the CSV file, attempts allowed for email and password: 3. Passwords were encrypted in a text file based on the algorithm: add 3 of each character, placed with a new line and put 0 at the end of the password
4. After placing the command, it can also add feedback stored in a map of <string, int> pairs.
The application also generates various reports that are constantly updated, which can be viewed in text files and in the console. These are related to: security (regarding the number of successful and failed logins), feedback (based on what users entered, averaging the marks), FAQs (which were the most accessed questions), turnover (determining profit). by subtracting the expenses from a text file), customers (the list with the data related to the customers, but also the number of accounts created in a certain period).

# 💡 Concepts used
 - Constructor
 - Destructor
 - Access methods
 - Operator overloading
 - Inclusion of classes
 - Text files
 - Binary files
 - Csv files
 - STL containers (vector, map, list, set)
 - Regex
 - Virtual functions

# 🐛 Bug
- Displaying the first name in the CSV file with some special characters, called BOM
- If the user wants to delete an element, he is asked if it is a drink or a food preparation

