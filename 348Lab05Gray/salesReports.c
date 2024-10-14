
#include <stdio.h>
#include <stdlib.h>
/*
input file format:
ex:
23458.01
40112.00
56011.85
37820.88
37904.67
60200.22
*/
void getArray(double allSales[]);
void getMonthlySales(double allSales[], const char* months[]);
void getSummaryReport(double allSales[], const char* months[12]);
void getSixMonthReport(double allSales[12], const char* months[12]);
void getSalesReport(double allSales[12], const char* months[12]);

int main(){
    
    //sales array initialization
    double allSales[12];
    
    //months array initialization
    
    const char* months[12] = {
        "JAN", "FEB", "MAR", "APR", "MAY", "JUN",
        "JUL", "AUG", "SEP", "OCT","NOV","DEC"
    };
    
    //call to open file and enter to array
    getArray(allSales);
    
    //call each report
    getMonthlySales(allSales, months);
    getSummaryReport(allSales, months);
    getSixMonthReport(allSales, months);
    getSalesReport(allSales, months);
    
    
    return 0;
}

void getArray(double allSales[]){
    //open file and add to an array(allSales)
    
    //File pointer and file open
    FILE *salesFile; 
    salesFile = fopen("sales.txt", "r");
    
    //Error check file
    if (salesFile == NULL){
        perror("File Error");
        return;
    }
    
    char line[300];
    int i = 0;
    
    //Add to array
    while(fgets(line, sizeof(line), salesFile) != NULL && 1 < 12) {
        
        allSales[i] = atof(line); 
        i++;
    }

    // Close the file
    fclose(salesFile);
    
}

void getMonthlySales(double allSales[], const char* months[]){
    //Print each sale by month
    
    //formatting 
    printf("Monthly Sales Report: \n");
    printf("%-10s %-10s\n", "Month", "Sale");
    printf("--------------------\n");
    
    //incrementing to print each month with respective sale 
    for(int i = 0; i < 12; i++){
    printf("%-10s $%-10.2f\n", months[i], allSales[i]);
    printf("\n");
    }
}

void getSummaryReport(double allSales[], const char* months[12]){
    //Find min, max, and average
    
    double minSale = 99999.0;
    double maxSale = 0.0;
    const char* minMonth;
    const char* maxMonth;
    double totalSales = 0.0;
    double avgSales;
    
    //for loop to find each value (max, min, avg)
    for (int i = 0; i < 12; i++){
        
        //find min
        if(allSales[i] <= minSale){
            minSale = allSales[i];
            minMonth = months[i];
        }
        
        //find max
        if(allSales[i] >= maxSale){
            maxSale = allSales[i];
            maxMonth = months[i];
        }
        
        //find total for avg
        totalSales +=allSales[i];
    }
    
    //find avg
    avgSales = totalSales / 12.0;
    
    printf("Maximum Sale: $%.2f (%s)\n", maxSale, maxMonth);
    printf("Minimum Sale: $%.2f (%s)\n", minSale, minMonth);
    printf("Average Sales: $%.2f\n", avgSales);
    printf("\n");
}

void getSixMonthReport(double allSales[], const char* months[]){
//jan-jun, feb-july.. etc. 
    //6 month window
    printf("Six-Month Sales Report: \n");
    
    for (int j = 0; j < 7; j++){
        double sixMonthTotal = 0.0;

        //adding each
        for(int i = j ; i < j + 6; i++){
            sixMonthTotal += allSales[i];
        }   

        //find avg
        double sixMonthAvg = sixMonthTotal / 12.0;
        //format print ex:jan-june
        
        printf("%s - %s: $%-10.2f\n\n", months[j], months[j+5], sixMonthAvg);

    }
}

void getSalesReport(double allSales[], const char* months[]){
    //sorting 
    for(int j = 0; j < 11; j++){
        for(int i = j + 1; i < 12; i++){
            if(allSales[j] < allSales[i]){

                //switch sale $
                double tempS = allSales[j];
                allSales[j] = allSales[i];
                allSales[i] = tempS;
                //switch month
                const char* tempM = months[j];
                months[j] = months[i];
                months[i] = tempM;
            }
        }
    }

    //format and print
    printf("Sales Report (high to low): \n");
    for (int k = 0; k < 12; k++) {
        printf("%-10s $%-10.2f\n", months[k], allSales[k]);
    }
}



