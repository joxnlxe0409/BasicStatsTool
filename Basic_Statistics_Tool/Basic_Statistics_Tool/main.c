#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "stats.h"

int main() {
    int data[MAX_DATA];
    int n = 0;
    double avg;
    int choice;

    while (1) {
        printf("\n->Simple Stats Analyzer<-\n");
        printf("1. Input Data\n");
        printf("2. Print Data\n");
        printf("3. Show Statistics\n");
        printf("4. Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            n = input_data(data, MAX_DATA);  
            break;
        case 2:
            if (n > 0)
                print_data(data, n);
            else
                printf("No data. Please input data first.\n");
            break;
        case 3:
            if (n > 0) {
                avg = calc_average(data, n);
                printf("Average: %.2f\n", avg);
                printf("Max: %d\n", find_max(data, n));
                printf("Min: %d\n", find_min(data, n));
                printf("Count over average: %d\n", count_over_average(data, n, avg));
                sort_data(data, n);
                printf("Sorted data: ");
                print_data(data, n);
                printf("Median: %.2f\n", calc_median(data, n));
            }
            else {
                printf("No data. Please input data first.\n");
            }
            break;
        case 4:
            printf("Exiting program.\n");
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
}

