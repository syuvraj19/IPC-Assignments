// main.c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include "stock.h"

#define MAX_STOCK_ENTRIES 100

/***************************************************************/

/* Students who are implementing the file reading version for  */

/* bonus marks are allowed to change STOCK_FROM_STDIN to 0     */

/* to enable the program to read from a file.                  */

/***************************************************************/

#define STOCK_FROM_STDIN 1

int main(void)

{

  struct StockRecord storeStock[MAX_STOCK_ENTRIES] = {{{0, 0, 0.0, 0}, 0, 0.0}};

  struct SalesRecord saleItems[MAX_ITEMS_IN_SALE];

  struct SalesRecord topSellers[5];

  int numStockItems = 0, numSales = 0, numSaleItems, totalSaleItems = 0, cat;

  double sale, totalSales = 0.0;

  // Read existing stock from stdin

  printf("Enter current stock in format amount, category, price, byWeight, name (0 amount to end):\n");

  numStockItems = readStockItems(storeStock, MAX_STOCK_ENTRIES, STOCK_FROM_STDIN);

  printf("\n");

  centreText(70, '*', " Seneca Groceries - Opening Stock ");

  printf("\n");

  centreText(70, '=', "");

  printf("\n");

  printStockReport(storeStock, numStockItems);

  printf("\n");

  centreText(70, '*', " Now in Sales Mode ");

  printf("\n");

  centreText(70, '=', "");

  printf("\n");

  do

  {

    numSaleItems = readSale(storeStock, numStockItems, saleItems);

    if (numSaleItems > 0)

    {

      sale = printSalesReport(storeStock, saleItems, numSaleItems);

      totalSales += sale;

      totalSaleItems += numSaleItems;

      numSales++;
    }

  } while (numSaleItems > 0);

  printf("\n");

  centreText(70, '*', " End of Day Summary ");

  printf("\n");

  centreText(70, '=', "");

  printf("\n");

  printf("%35s%8.2lf\n", "Cost of items sold before taxes", totalSales);

  printf("%35s%8d\n", "Number of Sales", numSales);

  printf("%35s%8.2lf\n\n", "Average items per sale", totalSaleItems / (double)numSales);

  printf("\n");

  centreText(70, '*', " Closing Stock ");

  printf("\n");

  centreText(70, '=', "");

  printf("\n");

  printStockReport(storeStock, numStockItems);

  printf("\n");

  for (cat = 0; cat < 5; cat++)

  {

    getTopSellers(storeStock, numStockItems, topSellers, 3, cat);

    printTopSellers(storeStock, topSellers, 3, cat);
  }

  for (cat = 5; cat < NUM_CATS; cat++)

  {

    getTopSellers(storeStock, numStockItems, topSellers, 2, cat);

    printTopSellers(storeStock, topSellers, 2, cat);
  }

  return 0;
}

/*
Sample Data 
    
    21,9,1.99,0,broccoli

    1,1.99,2,broccoli

    0,broccoli

    21,1,1.5,1,potato

    3,1,1.5,0,carrots

    10,3,12.99,1,steak

    2,3,9.5,1,Italian sausage

    2,4,4.99,0,2% milk

    2,4,3.99,0,coffee cream

    2,2,3.99,0,white bread

    5,2,4.99,0,chocolate cup cakes

    10,5,4.99,0,all purpose flour

    8,5,5.99,0,whole wheat flour

    5,5,2.99,0,raisins

    2,6,0.99,0,scrub pads

    4,7,13.95,0,laundry detergent

    0

    1,2

    20,3

    2,200

    2,2

    3,2

    4,1

    6,3

    8,1

    0

    5,2

    7,1

    10,2

    14,1

    0
*/