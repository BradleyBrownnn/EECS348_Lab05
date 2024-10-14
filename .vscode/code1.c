#include <stdio.h>


void monthly_reports(const char* months[], double sales[]);
void sale_summary(const char* months[], double sales[]);
void six_month_movingAverage(double sales[]);
void sales_report_high_2_low(const char* months[], double sales[]);

int main() {
    const char* months[] = {
        "January", "February", "March", "April", "May", "June", 
        "July", "August", "September", "October", "November", "December"
    };
    double sales[12];


    for (int i = 0; i < 12; i++) {
        printf("Type the sales number for %s: ", months[i]);
        scanf("%lf", &sales[i]);  
    }

    monthly_reports(months, sales);
    sale_summary(months, sales);
    six_month_movingAverage(sales);
    sales_report_high_2_low(months, sales);

    return 0;
}


void monthly_reports(const char* months[], double sales[]) {
    printf("\nMonthly Sales Report for 2024\n");
    printf("Month       Sales\n");
    for (int i = 0; i < 12; i++) {
        printf("%-10s %.2f\n", months[i], sales[i]);
    }
    printf("\n");
}


void sale_summary(const char* months[], double sales[]) {
    double min_sales = sales[0], max_sales = sales[0], total_sales = 0.0;
    int min_index = 0, max_index = 0;

    for (int i = 0; i < 12; i++) {
        if (sales[i] < min_sales) {
            min_sales = sales[i];
            min_index = i;
        }
        if (sales[i] > max_sales) {
            max_sales = sales[i];
            max_index = i;
        }
        total_sales += sales[i];
    }

    double avg_sales = total_sales / 12;

    printf("Sales Summary\n");
    printf("Max sales: %.2f (%s)\n", max_sales, months[max_index]);
    printf("Min sales: %.2f (%s)\n", min_sales, months[min_index]);
    printf("Avg sales: %.2f\n\n", avg_sales);
}

void six_month_movingAverage(double sales[]) {
    printf("Six-Month Moving Average Report:\n");
    for (int i = 0; i < 7; i++) {
        double sum_of_months = 0.0;

        for (int j = i; j < i + 6; j++) {
            sum_of_months += sales[j];
        }

        printf("%s-%s   %.2f\n", 
            i == 0 ? "January" : i == 1 ? "February" : i == 2 ? "March" : 
            i == 3 ? "April" : i == 4 ? "May" : i == 5 ? "June" : "July", 
            i == 0 ? "June" : i == 1 ? "July" : i == 2 ? "August" : 
            i == 3 ? "September" : i == 4 ? "October" : i == 5 ? "November" : "December", 
            sum_of_months / 6);
    }
    printf("\n");
}


void sales_report_high_2_low(const char* months[], double sales[]) {

    double sorted_sales[12];
    const char* sorted_months[12];


    for (int i = 0; i < 12; i++) {
        sorted_sales[i] = sales[i];
        sorted_months[i] = months[i];
    }


    for (int i = 0; i < 11; i++) {
        for (int j = i + 1; j < 12; j++) {
            if (sorted_sales[i] < sorted_sales[j]) {

                double temp_sales = sorted_sales[i];
                sorted_sales[i] = sorted_sales[j];
                sorted_sales[j] = temp_sales;


                const char* temp_month = sorted_months[i];
                sorted_months[i] = sorted_months[j];
                sorted_months[j] = temp_month;
            }
        }
    }


    printf("Sales Report (Highest to Lowest):\n");
    printf("Month       Sales\n");
    for (int i = 0; i < 12; i++) {
        printf("%-10s %.2f\n", sorted_months[i], sorted_sales[i]); 
    }
    printf("\n");
}
