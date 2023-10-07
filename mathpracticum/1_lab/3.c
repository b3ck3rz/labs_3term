#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int check_epsilon_validity(char* eps) {
    int flag = 1;
    char* double_symbols = "1234567890.";
    for (int i = 0; i < strlen(eps); i++) {
        if (strchr(double_symbols, eps[i]) == 0) {
            flag = 0;
            return 0;
        }
    }
    if (atof(eps) < 0) {
        return 0;
    }
    return 1;
}

void swap(double* arr, int i, int j) {
  double temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

int next_set(double* arr, int n) {
    int j = n - 2;
    while (j != -1 && arr[j] >= arr[j + 1]) j--;
    if (j == -1) {
        return 0;
    }
    int i = n - 1;
    while (arr[j] >= arr[i]) i--;
    swap(arr, j, i);
    int l = j + 1, r = n - 1;
    while (l < r) swap(arr, l++, r--);
    return 1;
}


int get_combinations(int m, double combinations[][m], double* arr) {
    for(int i = 0; i < 3; i++) {
        combinations[0][i] = arr[i];
    }
    int count = 1;
    while (next_set(arr, 3) == 1) {
        for(int i = 0; i < 3; i++) {
            combinations[count][i] = arr[i];
        }
        count++;
    }
    return count;
}

void quadratic_equation(double eps, double a, double b, double c, double* solve) {
    double D = b*b - 4.0*a*c;
    if (D > 0.0) {
        solve[0] = (-b + sqrt(D))/2.0*a;
        solve[1] = (-b - sqrt(D))/2.0*a;
        
    }
    if (D == 0.0) {
        solve[0] = solve[1] = -b/2.0*a; 
    }
    if (D < 0.0) {
        solve[0] = solve[1] = 0;
    }
}

void bubble_sort(double *arr, int size) {
  for (int i = 0; i < size - 1; i++) {
    for (int j = (size - 1); j > i; j--) {
        if (arr[j - 1] > arr[j]) {
            swap(arr, j-1, j);
        }
    }
  }
}

void comparing_numbers(double* arr, int n, double eps) {
    for (int i = 0; i < n-1; i++) {
        if (fabs(arr[i] - arr[i+1]) < eps) {
            arr[i+1] = arr[i];
        }
    }
}

int is_multiple(int a, int b) {
    if (a % b == 0) {
        return 1;
    }
    return 0;
}

int is_triangle(double* arr) {
    if (arr[0] + arr[1] > arr[2] && arr[1] + arr[2] > arr[0] && arr[2] + arr[0] > arr[1]) {
        return 1;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    if (argv[1][1] == 'q' ) {
        if (argc < 6) {
            printf("Not enough values to unpack\n");
            return 0;
        }
        if (argc > 6) {
            printf("Too many values\n");
            return 0;
        }
        if (check_epsilon_validity(argv[2]) == 0) {
            printf("Incorrect epsilon value\n");
            return 0;
        };
        double eps = atof(argv[2]);
        double arr[3];
        for (int i = 0; i < 3; i++) {
            arr[i] = atof(argv[i+3]);
        }
        bubble_sort(arr, 3);
        comparing_numbers(arr, 3, eps);
        double combinations[6][3];
        double solve[2];
        int count = get_combinations(3, combinations, arr);
        for (int i = 0; i < count; i++) {
            printf("a = %f, b = %f, c = %f\n", combinations[i][0], combinations[i][1], combinations[i][2]);
            quadratic_equation(0.1, combinations[i][0], combinations[i][1], combinations[i][2], solve);
            double x1 = solve[0];
            double x2 = solve[1];
            if (x1 == 0 && x2 == 0) {
                printf("There are no roots\n");
            }
            else {
                printf("Roots of the equation: x1 = %f, x2 = %f\n", x1, x2);                
            }

        }
        return 0;
    }

    if (argv[1][1] == 'm') {
        if (argc < 4) {
            printf("Not enough values to unpack\n");
            return 0;
        }
        if (argc > 4) {
            printf("Too many values\n");
            return 0;
        }        
        int a = atoi(argv[2]);
        int b = atoi(argv[3]);
        if (is_multiple(a, b)) {
            printf("Number is multiple\n");
        }
        else {
            printf("Number is not multiple\n");
        }

        return 0;
    }

    if(argv[1][1] == 't') {
        if (argc < 6) {
            printf("Not enough values to unpack\n");
            return 0;
        }
        if (argc > 6) {
            printf("Too many values\n");
            return 0;
        }
        double eps = atof(argv[2]);
        double arr[3];
        for (int i = 0; i < 3; i++) {
            arr[i] = atof(argv[i+3]);
        }
        bubble_sort(arr, 3);
        comparing_numbers(arr, 3, eps);
        if (is_triangle(arr)) {
            printf("It's triangle\n");
        }    
        else {
            printf("Is not triangle\n");
        }
        return 0;
    }
}