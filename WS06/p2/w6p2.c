/*
	==================================================
	Workshop #6 (Part-2):
	==================================================
	Name   :
	ID     :
	Email  :
	Section:
*/

#define _CRT_SECURE_NO_WARNINGS

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>// System Libraries
#include "w6p2.h" // User Libraries



// ----------------------------------------------------------------------------
// PART-1

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument
int getIntPositive(int* i_pointer)
{
	int i = 0;
	int positive_int = 0;
	do
	{
		scanf(" %d", &positive_int);
		if (positive_int <= 0)
		{
			printf("ERROR: Enter a positive value: ");
			++i;

		}
		else if (positive_int > 0 && i_pointer != NULL)
		{
			*i_pointer = positive_int;
			++i;
			return positive_int;

		}
		else
		{
			return positive_int;
			++i;

		}
	} while (i < PRODUCT);

	return positive_int;
}


// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* double_pointer)
{
	int i = 0;
	double positive_double = 0.0;
	do
	{
		scanf(" %lf", &positive_double);
		if (positive_double <= 0)
		{
			printf("ERROR: Enter a positive value: ");
			++i;

		}
		else if (positive_double > 0 && double_pointer != NULL)
		{
			*double_pointer = positive_double;
			++i;
			return positive_double;


		}
		else
		{
			return positive_double;
			++i;

		}
	} while (i < PRODUCT);
return positive_double; 
}

// 3. Opening Message (include the number of products that need entering)
void openingMessage(int defined_product)
{
	printf("Cat Food Cost Analysis\n======================\n\n");
	printf("Enter the details for %d dry food bags of product data for analysis.\n", defined_product);
	printf("NOTE: A 'serving' is %dg\n", GRAMS);
}



// 4. Get user input for the details of cat food product
void getCatFoodInfo(int* sku, double* price, double* lbs, int* calserve, const int procces_counter)
{
	printf("\nCat Food Product #%d\n--------------------\n", procces_counter);//procces_number
	printf("SKU           : ");//sku
	*sku = getIntPositive(NULL);
	printf("PRICE         : $");//price
	*price = getDoublePositive(NULL);
	printf("WEIGHT (LBS)  : ");//weight
	*lbs = getDoublePositive(NULL);
	printf("CALORIES/SERV.: "); //calories
	*calserve = getIntPositive(NULL);
}


// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int sku, const double* price, double* lbs, const int calserve)
{
	printf("%07d %10.2lf %10.1lf %8d\n", sku, *price, *lbs, calserve);
}



// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg(const double* lbs, double* kg)
{
	double i;
	double KG = 2.20462;
	i = *lbs / KG;
	if (kg != NULL)
	{
		*kg = i;
	}
	return(i);
}

// 9. convert lbs: g (call convertKG, then * 1000)
int convertLbsG(const double* lbs, int* g)
{
	int j;
	j = convertLbsKg(lbs, 0) * 1000;
	if (g != NULL)
	{
		*g = j;
	}
	return(j);
}

// 10. convert lbs: kg and g
void convertLbs(const double* lbs_convert, double* kg, int* g)
{
	convertLbsKg(lbs_convert, kg);
	convertLbsG(lbs_convert, g);
}

// 11. calculate: servings based on gPerServ
double calculateServings(const int volume, const int sum, double* result)
{
	double i;
	i = (double)sum / (double)volume;
	if (result != NULL)
	{
		*result = i;
	}
	return(i);
}

// 12. calculate: cost per serving
double calculateCostPerServing(const double* rate, const double* result, double*
	CostofResult)
{
	double cost = 0;
	cost = *rate / *result;
	if (CostofResult != NULL)
	{
		*CostofResult = cost;
	}
	return(cost);
}

// 13. calculate: cost per calorie
double calculateCostPerCal(const double* price, const double* calories, double*
	CostCalories)
{
	double cost = 0;
	cost = *price / *calories;
	if (CostCalories != NULL)
	{
		*CostCalories = cost;
	}
	return(cost);
}
// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo getDetailCatFood)
{
	struct ReportData reportinfo;
	double calo;
	// For SKU, RATE, Weight and Calories
	reportinfo.sku = getDetailCatFood.sku;
	reportinfo.rate = getDetailCatFood.price;
	reportinfo.weightLbs = getDetailCatFood.lbs;
	reportinfo.calories = getDetailCatFood.calories;
	// For kg and g 
	reportinfo.kg = convertLbsKg(&getDetailCatFood.lbs, &reportinfo.kg);
	reportinfo.g = convertLbsG(&getDetailCatFood.lbs, &reportinfo.g);
	reportinfo.sumServe = calculateServings(GRAMS, reportinfo.g,&reportinfo.sumServe);
	reportinfo.perServe = calculateCostPerServing(&reportinfo.rate,&reportinfo.sumServe, &reportinfo.perServe);
	calo = reportinfo.calories * reportinfo.sumServe;
	reportinfo.calPerServe = calculateCostPerCal(&reportinfo.rate, &calo,&reportinfo.calPerServe);
	return(reportinfo);
}


// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
	printf("Analysis Report (Note: Serving = %dg\n", GRAMS);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData reportinfo, const int cheap)
{
	printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf",
		reportinfo.sku, reportinfo.rate, reportinfo.weightLbs, reportinfo.kg, reportinfo.g,
		reportinfo.calories, reportinfo.sumServe, reportinfo.perServe,
		reportinfo.calPerServe);
}
// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo cheaper_product)
{
	printf("\n");
	printf("Final Analysis\n--------------\n");
	printf("Based on the comparison data, the PURRR-fect economical option is:\n");
		printf("SKU:%07d Price: $%.2lf\n\n", cheaper_product.sku,
			cheaper_product.price);
	printf("Happy shopping!\n");
}
// ----------------------------------------------------------------------------

// 7. Logic entry point
void start(void)
{
	int i = 0, cheapproduct = 0;
	struct CatFoodInfo cf[PRODUCT] = { {0, 0, 0, 0} };
	openingMessage(PRODUCT);
	while (i < PRODUCT)
	{
		getCatFoodInfo(&cf[i].sku, &cf[i].price, &cf[i].lbs, &cf[i].calories, i + 1);
		++i;
	}
	i = 0;
	displayCatFoodHeader();
	while (i < PRODUCT)
	{
		displayCatFoodData(cf[i].sku, &cf[i].price, &cf[i].lbs, cf[i].calories);
		++i;
	}
	struct ReportData reportArray[PRODUCT];
	displayReportHeader();
	for (i = 0; i < PRODUCT; i++)
	{
		reportArray[i] = calculateReportData(cf[i]);
		if (reportArray[i].perServe < reportArray[i - 1].perServe)
		{
			cheapproduct = i;
		}
	}
	int j;
	for (j = 0; j < PRODUCT; j++)
	{
		struct ReportData x = { 0 };
		x = reportArray[j];
		displayReportData(x, cheapproduct);
		if (cheapproduct == j)
		{
			printf(" ***");
		}
		printf("\n");
	}
	displayFinalAnalysis(cf[cheapproduct]);
}



