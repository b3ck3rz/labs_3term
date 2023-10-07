#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int check_epsilon_validity(char* eps) {
    int flag = 1;
    char* double_symbols = "1234567890.";
    for (int i = 0; i < strlen(eps); i++) {
        if (strchr(double_symbols, eps[i]) == 0) {
            flag = 0;
            break;
        }
    }
    if (flag == 0) {
        return 0;
    }
    if (atof(eps) < 0) {
        return 0;
    }
    return 1;
}

double calculate_a(double eps, double x) {
    int n = 1;
    double sum = 1;
    double element = 1, elem_prev;
    do {
        elem_prev = element;
        element *= x/n;
        n++;
        sum += element;
    } while (fabs(element - elem_prev) > eps);

    return sum;
}

double calculate_b(double eps, double x) {
    int n = 1;
    double sum = 1;
    double element = 1, elem_prev;
    do {
        elem_prev = element;
        element *= -(x*x/(4*n*n - 2*n));
        n++;
        sum += element;
    } while (fabs(element - elem_prev) > eps);

    return sum; 
}

double calculate_c(double eps, double x) {
    int n = 1;
    double sum = 1;
    double element = 1, elem_prev;
    do {
        elem_prev = element;
        element *= (9*n*n*x*x)/(9*n*n - 9*n +2);
        n++;
        sum += element;

    } while (fabs(element - elem_prev) > eps);

    return sum; 
}

double calculate_d(double eps, double x) {
    int n = 2;
    double sum = -x*x/2;
    double element = -x*x/2, elem_prev;
    do {
        elem_prev = element;
        element *= -((2*n-1)*x*x)/(2*n);
        n++;
        sum += element;
    } while (fabs(element - elem_prev) > eps);

    return sum; 
}

int main(int argc, char* argv[]) {

    if (check_epsilon_validity(argv[1]) == 0) {
        printf("Incorrect epsilon value\n");
        return 0;
    };

    double eps = atof(argv[1]);
    double x = atof(argv[2]);
    double res_a = calculate_a(eps, x);
    double res_b = calculate_b(eps, x);
    double res_c = calculate_c(eps, x);
    double res_d = calculate_d(eps, x);
    
    printf("The result of the calculation of a.: %f\n", res_a);
    printf("The result of the calculation of b.: %f\n", res_b);
    printf("The result of the calculation of c.: %f\n", res_c);
    printf("The result of the calculation of d.: %f\n", res_d);
}