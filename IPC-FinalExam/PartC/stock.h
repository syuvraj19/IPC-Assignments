//==============================================
// Group Member 1:
//        Name:           Yuvraj Singh
//        Student Number: 155580210
//        Email:          yuvraj-singh5@myseneca.ca
//==============================================
// Group Member 2:
//        Name:            Raghav Malhotra
//        Student Number:
//==============================================
// Assignment:     Final Assessment
// Part:           C
//==============================================

#define MAX_ITEMS_IN_SALE 100 // The total number of Items is 100
#define NUM_CATS 7            // The total number of Category is 7

// Structure type productStock declaration
struct productStock {
	int productAmount;     // Amount of product in the beginning
	int productCategory;   // Category a product belongs in
	double productPrice;   // Originalprice of a product
	int byWeight;          // (0 -> Sold by number of product) or (1 -> Sold by weight)
};

// Structure type StockRecord declaration
struct StockRecord {
	struct productStock productStock;    // Struct of productStock
	char productName[30];                // Name of a product 
	double amountSold;                   // How many or much of a product are bought by the user
};

// Structure type SalesRecord declaration 
struct SalesRecord {
	int productValue;	    // ID or category of a product
	double productSold;     // How many or much of a product has been sold
	char productName[30];   // Name of the product sold
};


//--------------------------------
// Function Prototypes
//--------------------------------

// clearKeyboard:
void clearKeyboard(void); 

// readStockItems:
// Get user inputs for a product stock (including product name)
int readStockItems(struct StockRecord stockRecord[], int maxEntry, int infoInProgram); 

//errorMessage:
// Shows the user an error message when the user inputs wrong data
void stockErrorMessage(struct StockRecord stockRecord[], int index, int min, int max); 

// centreText:
// Displaying centre messages (including titles, lines)
void centreText(int numCharacters, char symbol, char* centreMessage); 

// convertCategory 
// To convert the category number to its name (depending on the category number)
void convertCategory(int productCategory, char changeCategory[]); 					

// printStockReport:
// To output the every inputted stock by the user
void printStockReport(const struct StockRecord stockRecord[], int maxReport); 					

// readSale:
// To prompt the user how many or much of a product the user wants to buy
int readSale(struct StockRecord stockRecord[], int maxReport, struct SalesRecord salesRecord[]); 														

// restockProducts
// To calculate the remaining amount of products after the user decided to purhcase them
// Restocking the stock of the products after the user bought
void restockProducts(struct StockRecord stockRecord[], struct SalesRecord salesRecord[], int index, int maxOrder);					

// printSalesReport:
// Outputting the the history of the user's purchases (including the subtotal, tax, and total)
double printSalesReport(const struct StockRecord stockRecord[], struct SalesRecord salesRecord[], int saleItems); 								

// getTopSellers: 
// Finding the products depending on category (=cat) inputted (from main) and store them in struct topSellers
void getTopSellers(struct StockRecord stockRecord[], int maxReport, struct SalesRecord topSellers[], int topNumber, int cat); 

// sortInformation: 
// - Processes from end to beginning
// Using the bubble sorting (from greatest to smalles amount of products)
void sortInformation(struct SalesRecord salesRecord[], int max);

// printTopSellers:
// To output the first set of a topSellers struct (depending on topNumber), from each category (=cat)
void printTopSellers(const struct StockRecord stockRecord[], struct SalesRecord topSellers[], int topNumber, int cat); 




