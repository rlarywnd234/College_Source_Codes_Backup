/*
	==================================================
	Workshop #6 (Part-2):
 ==================================================
 Name : KYOJUNG KIM
 ID :kkim107
 Email : kkim107@mysenec.ca
 Section: ipc144ZAA
*/

// ----------------------------------------------------------------------------
// defines/macros
#define GRAMS 64
#define PRODUCT 3


// ----------------------------------------------------------------------------
// structures
struct CatFoodInfo
{
	int sku;
	int calories;
	double price;
	double lbs;
};

struct ReportData
{
	int sku;
	double rate;
	int calories;
	double weightLbs;
	double kg;
	int g;
	double sumServe;
	double perServe;
	double calPerServe;
};

// ----------------------------------------------------------------------------
// function prototypes

// PART-1

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* i);

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* d);

// 3. Opening Message (include the number of products that need entering)
void openingMessage(int defined_product);

// 4. Get user input for the details of cat food product
void getCatFoodInfo(int* sku, double* price, double* lbs, int* calserve, const int procces_counter);

// 5. Display the formatted table header
void displayCatFoodHeader(void);

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int sku, const double* price, double* lbs, const int calserve);

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg
double convertLbsKg(const double* lbs, double* kg);


// 9. convert lbs: g
int convertLbsG(const double* lbs, int* g);


// 10. convert lbs: kg / g
void convertLbs(const double* lbs_convert, double* kg, int* g);

// 11. calculate: servings based on gPerServ
double calculateServings(const int volume, const int sum, double* result);


// 12. calculate: cost per serving
double calculateCostPerServing(const double* rate, const double* result, double* CostofResult);

// 13. calculate: cost per calorie
double calculateCostPerCal(const double* price, const double* calories, double*
	CostCalories);



// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo getDetailCatFood);

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void);

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData reportinfo, const int cheap);


// 17. Display the findings (cheapest)
void displayReportData(const struct ReportData reportinfo, const int cheap);


// ----------------------------------------------------------------------------

// 7. Logic entry point 
void start(void);

