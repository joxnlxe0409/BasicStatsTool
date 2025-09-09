#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "stats.h"

int input_data(int data[], int n_max) {
    int n;
    printf("Enter number of data (max %d): ", n_max);
    scanf("%d", &n);
    if (n > n_max) {
        printf("Too many data. Limiting to %d.\n", n_max);
        n = n_max;
    }
    printf("Enter %d data:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }
    return n;
}

void print_data(const int data[], int n) {
    printf("Data: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
}

double calc_average(const int data[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += data[i];
    }
    return (double)sum / n;
}

int find_max(const int data[], int n) {
    int max = data[0];
    for (int i = 1; i < n; i++) {
        if (data[i] > max)
            max = data[i];
    }
    return max;
}

int find_min(const int data[], int n) {
    int min = data[0];
    for (int i = 1; i < n; i++) {
        if (data[i] < min)
            min = data[i];
    }
    return min;
}

int count_over_average(const int data[], int n, double avg) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (data[i] > avg)
            count++;
    }
    return count;
}

void sort_data(int data[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (data[i] > data[j]) {
                temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
}

double calc_median(int data[], int n) {
    sort_data(data, n); 
    if (n % 2 == 1) {
        return data[n / 2];
    }
    else {
        return (data[(n / 2) - 1] + data[n / 2]) / 2.0;
    }
}

