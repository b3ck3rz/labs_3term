#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fill_random(int* arr, int size, int a, int b) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % b - a;
    }
}

void print(int *arr, int n) {
    for (int i=0;i<n;i++)
    printf ("%d ", arr[i]);
    printf("\n");
}

void find_n_swap(int* arr, int size, int* minmax_val, int* minmax_pos) {
    int min = INT_MAX, max = -INT_MAX, pos_min, pos_max;
    for (int i = 0; i < size; i++) {
        if (arr[i] > max) {max = arr[i]; pos_max = i;}
        else if (arr[i] == max) pos_max = i;
        if (arr[i] < min) {min = arr[i]; pos_min = i;}
        else if (arr[i] == min) pos_min = i;
    }
    arr[pos_min] = max;
    arr[pos_max] = min;
    minmax_val[0] = min;
    minmax_val[1] = max;
    minmax_pos[0] = pos_min;
    minmax_pos[1] = pos_max;
}

void task_1(int a, int b) {
    int size = 200;
    int arr[size];
    fill_random(arr, size, a, b);
    printf("The original array:\n");
    print(arr,size);
    printf("\n");
    int minmax_val[2];
    int minmax_pos[2];
    find_n_swap(arr, size, minmax_val, minmax_pos);
    printf ("Min value: %d\nMax value: %d\n", minmax_val[0], minmax_val[1]);
    printf ("Min value position: %d\nMax value position: %d\n\n", minmax_pos[0], minmax_pos[1]);
    printf("The changed array:\n");
    print(arr, size);
}

void task_2() {
    int size_A = rand()%100+10;
    int size_B = rand()%100+10;
    int* A;
    int* B;
    int* C;
    A = (int*)malloc(size_A * sizeof(int));
    B = (int*)malloc(size_B * sizeof(int));
    C = (int*)malloc(size_A * sizeof(int));
    fill_random(A, size_A, 1000, 2000);
    fill_random(B, size_B, 1000, 2000);
    printf ("Array A\n");
    print(A,size_A);
    printf ("Array B\n");
    print(B, size_B);
    for (int i = 0; i < size_A; i++) {
        int min = A[i] - B[0], diff, pos_B = 0;
        for (int j = 0; j < size_B; j++) {
            diff = A[i] - B[j];
            if (abs(diff) <= abs(min)) {
                min = diff;
                pos_B = j;
            }
        }
        C[i] = A[i] + B[pos_B];
    }
    printf("Array C\n");
    print(C, size_A);    
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf ("Not enough values"); 
        return 0;
    }
    if (argc > 3) {
        printf ("Too many values"); 
        return 0;
    }
    srand(time(NULL));
    int a = atoi(argv[1]), b = atoi(argv[2]);
    task_1(a, b);
    printf("\n");
    task_2();
}