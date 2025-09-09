#pragma once

#define MAX_DATA 100

int input_data(int data[], int n_max);
void print_data(const int data[], int n);
double calc_average(const int data[], int n);
int find_max(const int data[], int n);
int find_min(const int data[], int n);
int count_over_average(const int data[], int n, double avg);
void sort_data(int data[], int n);
double calc_median(int data[], int n);
