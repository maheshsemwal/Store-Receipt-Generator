

# Store Receipt Generator

This is a simple C program that generates a store receipt based on user input. The program takes in the number of items to be purchased, their names, quantity, and price, and calculates the subtotal, tax, and total amount. It then generates a receipt with a unique receipt number and the date and time of purchase.

## Instructions

1. Open a terminal or command prompt and navigate to the directory where the program file is located.
2. Compile the program using the command `gcc -o receiptGenerator receiptGenerator.c`.
3. Run the program using the command `./receiptGenerator`.
4. Enter the number of items to be purchased when prompted.
5. Enter the name, quantity, and price of each item when prompted.
6. The program will generate a receipt in a file named `receipt.txt` in the same directory as the program file.

## File Structure

- `receiptGenerator.c`: the source code for the program.
- `receipt.txt`: the generated receipt file.

## Dependencies

- The program requires the `stdio.h`, `stdlib.h`, and `time.h` header files.

## Sample Output

```
Enter number of items: 3
Enter Name of Item 1: T-Shirt
Enter Quantity of Item 1: 2
Enter price of item 1: 500

Enter Name of Item 2: Jeans
Enter Quantity of Item 2: 1
Enter price of item 2: 1200

Enter Name of Item 3: Shoes
Enter Quantity of Item 3: 1
Enter price of item 3: 1000

-----------------------------------------------------
ABC Store
Lane No.3, Clement Town, Dehradun
0135-232567
store@abcstore.com
www.abcstore.com

Date: 2023-05-13 12:45:30
Receipt No: 23862

--------------------------------------
| ITEM           |   QTY  |   PRICE |
--------------------------------------
| T-Shirt        |     2 | $  1000 |
| Jeans          |     1 | $  1200 |
| Shoes          |     1 | $  1000 |
--------------------------------------
Subtotal: $ 3200
Tax: $ 160(5%)
Total: $ 3360

Thank you for shopping with us!
-----------------------------------------------------
```

## Author

This program was written by [Mahesh Semwal](https://github.com/maheshsemwal).
