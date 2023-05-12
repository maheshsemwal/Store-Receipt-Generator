#include<stdio.h>
#include <stdlib.h>
#include <time.h>
/*
here's a simple template for a store receipt:
-----------------------------------------------------
[Store Name and Logo]
[Store Address]
[Store Phone Number]
[Store Email]
[Store Website]

Date: [Date and Time of Purchase]
Receipt No: [Unique Receipt Number]

--------------------------------------
| ITEM           |   QTY  |   PRICE |
--------------------------------------
| [Item 1]       |   [Qty]  |  $[Price] |
| [Item 2]       |   [Qty]  |  $[Price] |
| [Item 3]       |   [Qty]  |  $[Price] |
| [Item 4]       |   [Qty]  |  $[Price] |
| [Item 5]       |   [Qty]  |  $[Price] |
--------------------------------------

Subtotal: $[Subtotal]
Tax: $[Tax Amount]
Total: $[Total Amount]

Thank you for shopping with us!
-----------------------------------------------------
*/
struct items
{
    char itemName[100];
    int quantity, price;
};
void itemIn(struct items item[],int n){
    for (int i = 0; i < n; i++)
    {
        int price = 0;
        printf("Enter Name of Item %d: ",i+1);
        gets(item[i].itemName);
        printf("Enter Quantity of Item %d: ",i+1);
        scanf("%d",&item[i].quantity);
        printf("Enter price of item %d: ",i+1);
        scanf("%d",&price);
        item[i].price = (item[i].quantity * price);
        getchar();
        printf("\n");
    }
    
}
void grandTotal(struct items item[],int n,int* netBill,int* subtotal, int* tax){
    for (int i = 0; i < n; i++)
    {
        (*subtotal) += item[i].price;
    }
    (*tax) = (*subtotal)*5/100;
    (*netBill) = (*subtotal) + (*tax);
    
}
void id(int* tid){
    srand(time(NULL));
    *tid = rand() % 100000;
}
void reciptGenerator(FILE* f,struct items item[],int n,int* netBill,int* subtotal, int* tax,int *tid,char time_str[50]){
    f = fopen("receipt.txt","w");
    fprintf(f, "-----------------------------------------------------\n");
    fprintf(f, "ABC Store\n");
    fprintf(f, "Lane No.3, Clement Town, Dehradun\n");
    fprintf(f, "0135-232567\n");
    fprintf(f, "store@abcstore.com\n");
    fprintf(f, "www.abcstore.com\n\n");
    fprintf(f, "Date: %s\n",time_str);
    fprintf(f, "Receipt No: %d\n\n",*tid);
    fprintf(f, "--------------------------------------\n");
    fprintf(f, "| ITEM           |   QTY  |   PRICE |\n");
    fprintf(f, "--------------------------------------\n");
    for (int i = 0; i < n; i++) {
        fprintf(f, "| %-14s | %5d | $%6d |\n", item[i].itemName, item[i].quantity, item[i].price);
    }
    fprintf(f, "--------------------------------------\n");
    fprintf(f, "Subtotal: $%d\n", *subtotal);
    fprintf(f, "Tax: $%d(5%%)\n", *tax);
    fprintf(f, "Total: $%d\n\n", *netBill);
    fprintf(f, "Thank you for shopping with us!\n");
    fprintf(f, "-----------------------------------------------------\n");

}
int main(){
    FILE* f=NULL;
    int n;
    int netBill=0, subtotal=0, tax=0,tid;
    time_t current_time;
    struct tm* time_info;
    char time_str[50];
    time(&current_time);
    time_info = localtime(&current_time);
    strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", time_info);
    printf("Enter number of items: ");
    scanf("%d",&n);
    getchar();
    struct items item[n];
    itemIn(item,n);
    grandTotal(item,n,&netBill,&subtotal,&tax);
    id(&tid);
    reciptGenerator(f,item,n,&netBill,&subtotal,&tax,&tid,time_str);
    return 0;
}
