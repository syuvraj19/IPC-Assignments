//==============================================
// Group Member 1:
//		Name:           Yuvraj Singh
//		Student Number: 155580210
//		Email:          yuvraj-singh5@myseneca.ca
//==============================================
// Group Member 2:
//		Name:            Raghav Malhotra
//		Student Number:
//==============================================
// Assignment:     Final Assessment
// Part:           C
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Declare macros
#define MIN_CATEGORY 1
#define MAX_CATEGORY 7

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "stock.h"

// Clear the standard input buffer
void clearKeyboard(void) {
    while (getchar() != '\n'); // empty execution code block on purpose
}

// readStockItems:
// Get user inputs for a product stock (including product name)
int readStockItems(struct StockRecord stockRecord[], int maxEntry, int infoInProgram) {

    // Variables:
    int i;
    int loopFlag = 0;

    // Checking for conditions: when loopFlag != 0 and i < maxEntry(=100)
    for (i = 0; !loopFlag && i < maxEntry;) {

        scanf("%d, %d, %lf, %d, %30[^\n]", &stockRecord[i].productStock.productAmount, &stockRecord[i].productStock.productCategory,
            &stockRecord[i].productStock.productPrice, &stockRecord[i].productStock.byWeight,
            stockRecord[i].productName);
        clearKeyboard();

        // Checking if user wants to end stocking
        if (stockRecord[i].productStock.productAmount == 0) 
            loopFlag = 1;
        else 
        {
            // Call the function "stockErrorMessage:
            stockErrorMessage(stockRecord, i, MIN_CATEGORY, MAX_CATEGORY);
            i++;
        }
    }
    return i;
}

// stockErrorMessage:
// Shows the user an error message when the user inputs wrong data
void stockErrorMessage(struct StockRecord stockRecord[], int index, int min, int max) {

    // Variable:
    int whileFlag = 1;

    // Infinite loop until the user inputs correct set of data
    while (whileFlag) {

        // Checking for the condition of "productCategory"
        if (stockRecord[index].productStock.productCategory < min || stockRecord[index].productStock.productCategory > max) {
            printf("Invalid Category - Enter a number between 1 and 7: ");
            scanf("%d,%lf,%d,%30[^\n]", &stockRecord[index].productStock.productCategory, 
                                        &stockRecord[index].productStock.productPrice,                                      
                                        &stockRecord[index].productStock.byWeight, 
                                        stockRecord[index].productName);
            clearKeyboard();
        }
        // Checking for the condition of "byWeight"
        else if (stockRecord[index].productStock.byWeight < 0 || stockRecord[index].productStock.byWeight > 1) {
            printf("Invalid soldByWeight - Enter a number between 0 and 1: ");
            scanf("%d,%30[^\n]", &stockRecord[index].productStock.byWeight, 
                                 stockRecord[index].productName);
            clearKeyboard();
        }
        else {
            whileFlag = 0;
        }
    }
}


// centreText:
// Displaying centre messages (including titles, lines)
void centreText(int numCharacters, char symbol, char* centreMessage) {          

    // Variables:
    int i;
    int starSymbol = (numCharacters - strlen(centreMessage)) / 2;
    int messageFlag = starSymbol + strlen(centreMessage);

    // Checking if the centreMessage is empty or not
    if (strlen(centreMessage) == 0) {
        for (i = 0; i < numCharacters; i++) {
            printf("%c", symbol);
        }
    } 
    else {
        for (i = 0; i < numCharacters; i++) {

            // Condition to display a symbol until a certain point
            if (i < starSymbol) 
                printf("%c", symbol);
            // Condition to display the centred message 
            else if (i < (messageFlag - 2)) {                                                                                                       
                printf(centreMessage);
                // Changing the value of the messageFlag to prevent the repetition of the displaying the "centreMessage"
                i = messageFlag - 1;
            } 
            // Condition to display the symbol on the other side
            else
                printf("%c", symbol);
        }    
    }
}

// convertCategory:
// To convert the category number to its name (depending on the category number)
void convertCategory(int productCategory, char changeCategory[]) {

    switch(productCategory)
    {
        case 1:
            strcpy(changeCategory, "produce");
            break; 
        
        case 2:
              strcpy(changeCategory, "bakery");
            break; 
        
        case 3:
          strcpy(changeCategory, "meat");
            break; 
        
        case 4:
          strcpy(changeCategory, "dairy");
            break; 
        
        case 5:
          strcpy(changeCategory, "baking");
            break; 
        
        case 6:
          strcpy(changeCategory, "house wares");
            break;

        case 7:
          strcpy(changeCategory, "miscellaneous");
            break;

        default:
            break;
    }

}

// printStockReport:
// To output the every inputted stock by the user
void printStockReport(const struct StockRecord stockRecord[], int maxReport) {
    
    // Variables:
    int i;
    char categoryName[30] = { '\0' };

    puts("  ID                        Product        Category   Price Quantity  ");
    for(i = 0; i < maxReport; i++) {
       
        convertCategory(stockRecord[i].productStock.productCategory, categoryName);
        printf("%4d %30s %15s %7.2lf %8d\n", (i + 1), stockRecord[i].productName, categoryName, 
                                                      stockRecord[i].productStock.productPrice, 
                                                      stockRecord[i].productStock.productAmount);
    }
}

// readSale:
// To prompt the user how many or much of a product the user wants to buy
int readSale(struct StockRecord stockRecord[], int maxReport, struct SalesRecord salesRecord[]) {

    // Variables:
    int i = 0;
    int whileFlag = 0;

    // Unlimited looping until the user decides to quit
    do {
        printf("Enter a product ID to purchase, and the quantity (0 to stop): ");
        scanf("%d, %lf", &salesRecord[i].productValue, &salesRecord[i].productSold);
        clearKeyboard();
        
        // Check for existing value
        if (salesRecord[i].productValue == 0)
            whileFlag = 1;

        else {
            // Call the funtion "restockProducts"
            restockProducts(stockRecord, salesRecord, i, maxReport);
            // Increment i by 1 to go to the next index
            i++;
        }
    } while (!whileFlag);
    
    // Return the amount of products the user bought
    return i;
}

// restockProducts:
// To calculate the remaining amount of products after the user decided to purhcase them
// Restocking the stock of the products after the user bought
void restockProducts(struct StockRecord stockRecord[], struct SalesRecord salesRecord[], int index, int maxReport) {

    // Variable:
    int indexRecord;
    int whileFlag = 1;

    // Infinite loop until the user inputted correct set of data
    while (whileFlag) {
        // Checking condition of productValue:
        if (salesRecord[index].productValue < 0 || salesRecord[index].productValue > maxReport) {
            printf("Invalid Product - Enter a number between 0 and %d: ", maxReport);
            scanf("%d, %lf", &salesRecord[index].productValue, &salesRecord[index].productSold);
            clearKeyboard();
        }
        // Checking condition of productSold:
        else if (salesRecord[index].productSold < 0.10 || salesRecord[index].productSold > 100) {
            printf("Invalid quantity - Enter a number between 0.10 and 100.00: ");
            scanf("%d, %lf", &salesRecord[index].productValue, &salesRecord[index].productSold);

            clearKeyboard();
        }
        // If the set of data has been inputted correctly:
        else{
            whileFlag = 0;
        }
    }

    // Initializing the value for indexRecord
    indexRecord = salesRecord[index].productValue - 1;

    // Checking for condition (when the user bought more products than the original amount)
    if (stockRecord[indexRecord].productStock.productAmount < salesRecord[index].productSold) {
        // Have the user to only buy the remaining amount of the stock available 
        stockRecord[indexRecord].amountSold = stockRecord[indexRecord].productStock.productAmount;
        // The total amount of stock available would be 0 
        stockRecord[indexRecord].productStock.productAmount = 0;
    }
    else {
        // Reduce the total amount of product by the amount the user wants to buy
        stockRecord[indexRecord].productStock.productAmount -= (salesRecord[index].productSold);  
        // Have the user to buy certain amount of products the user wants
        stockRecord[indexRecord].amountSold += salesRecord[index].productSold;
    }
}

// printSalesReport:
// Outputting the the history of the user's purchases (including the subtotal, tax, and total)
double printSalesReport(const struct StockRecord stockRecord[], struct SalesRecord salesRecord[], int saleItems) {

    // Variable:
    int i, indexRecord;
    double tax = 0.0, purchaseTotal = 0.0, total = 0.0, price = 0.0;

    // Making title of "Seneca Groceries"
    puts("");
    centreText(70, '*', " Seneca Groceries ");
    puts("");
    centreText(70, '=', "");
    puts("");

    for (i = 0; i < saleItems; i++) {

        // Calculating the index of the product in the salesRecord struct
        indexRecord = salesRecord[i].productValue - 1;
        // Calculating subtotal of a product
        price = stockRecord[indexRecord].productStock.productPrice * (int)stockRecord[indexRecord].amountSold;

        // Outputting the subtotal of a product (including its name and original price)
        printf("%30s %8.2lf %7.2lf\n", stockRecord[indexRecord].productName, stockRecord[indexRecord].productStock.productPrice, price);

        // Checking condition of productCategory:
        if (stockRecord[indexRecord].productStock.productCategory == 6 || stockRecord[indexRecord].productStock.productCategory == 7) {
            // Calculating for tax
            tax += price * 0.13;
        }
        purchaseTotal += price;
        total = purchaseTotal + tax;
    }    

    printf("Purchase Total %32.2lf\n", purchaseTotal);
    printf("Tax %43.2lf\n", tax);
    printf("Total %41.2lf\n", total);
    puts("Thank you for shopping at Seneca!\n");
    
    // Return the subtotal (excluding the tax) of the entire products bought
    return purchaseTotal;
}


// getTopSellers:
// Finding the products depending on category (=cat) inputted (from main) and store them in struct topSellers
void getTopSellers(struct StockRecord stockRecord[], int maxReport, struct SalesRecord topSellers[], int topNumber, int cat) {

    // Variables:
    int catCount;
    int topCount = 0;

    for (catCount = 0; catCount < maxReport; catCount++) {
        // Checking for condition for "productCategory"
        if (stockRecord[catCount].productStock.productCategory == (cat + 1)) {
            // Store information of the amount of a product sold in the stockRecord struct
            topSellers[topCount].productSold = (int)stockRecord[catCount].amountSold;
            // Storing category number in the productValue
            topSellers[topCount].productValue = (cat + 1);
            strcpy(topSellers[topCount].productName, stockRecord[catCount].productName);
            topCount++;        
        }
    }
    // Using the "sortInformation" function to sort
    sortInformation(topSellers, topCount);
}

// sortInformation:
// - Processes from end to beginning
// Using the bubble sorting (from greatest to smalles amount of products)
void sortInformation(struct SalesRecord salesRecord[], int max) {

    // Variables:
    int firstIndex = 0, secondIndex = 0;
    double tempValue = 0.0;
    char tempChar[30] = { '\0' };

    // Start: At end of array and work towards the beginning
    for (firstIndex = (max - 1); firstIndex > 0; firstIndex--) {
        for (secondIndex = 0; secondIndex < firstIndex; secondIndex++) {
            if (salesRecord[secondIndex].productSold < salesRecord[secondIndex + 1].productSold) {
                tempValue = salesRecord[secondIndex].productSold;
                strcpy(tempChar, salesRecord[secondIndex].productName);

                salesRecord[secondIndex].productSold = salesRecord[secondIndex + 1].productSold;
                strcpy(salesRecord[secondIndex].productName, salesRecord[secondIndex + 1].productName);

                salesRecord[secondIndex + 1].productSold = tempValue;
                strcpy(salesRecord[secondIndex + 1].productName, tempChar);
            }
        }
    }
}

// printTopSellers:
// To output the first set of a topSellers struct (depending on topNumber), from each category (=cat)
void printTopSellers(const struct StockRecord stockRecord[], struct SalesRecord topSellers[], int topNumber, int cat) {

    // Variables:
    int i;
    char categoryName[30] = { '\0' };

    // Call function "convertCategory": 
    convertCategory((cat + 1), categoryName);

    printf("------------ Top %d sellers in %s ------------\n", topNumber, categoryName);
    printf("Rank                       Product   Sales\n");

     for (i = 0; i < topNumber; i++) {
         // If the product is within a category and has been sold at least once:
         if (topSellers[i].productValue == (cat +1) && topSellers[i].productSold != 0)
             // Output the ranking, the product name, and how many or much of a product has been sold
            printf("%4d %29s %7.2lf\n", (i + 1), topSellers[i].productName, (double)topSellers[i].productSold);
         else
             // Output the rank and "<none>"
            printf("%4d                        <none>    0.00\n", (i + 1)); 
     }
     puts("");
}


