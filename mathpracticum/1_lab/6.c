#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int check_epsilon_validity(char* eps) {
    char* double_symbols = "1234567890.";
    for (int i = 0; i < strlen(eps); i++) {
        if (strchr(double_symbols, eps[i]) == 0) {
            return 0;
        }
    }
    if (atof(eps) < 0) {
        return 0;
    }
    return 1;
}

double function_a(double x) {
    return log(1.0 + x) / x;
}

double function_b(double x) {
    return exp(- x * x / 2);
}

double function_c(double x) {
    return log(1 / (1 - x));
} 

double function_d(double x) {
    return pow(x, x);
}

double calculate_a(double eps) {
    double delta_x = 1;
    double step = 1;
    double curr = log(2);
    double prev;

    do {
        prev = curr;
        curr = 0;
        step /= 2;
        delta_x /= 2;

        for (double x = 1; x > 0; x -= step) {
            curr += function_a(x) * delta_x;
        }
    } while (fabs(curr - prev) > eps);

    return curr;
}

double calculate_b(double eps) {
    double delta_x = 1;
    double step = 1;
    double prev = function_b(1);
    double curr = prev;

    do {
        prev = curr;
        curr = 0;
        step /= 2;
        delta_x /= 2;

        for (double x = 1; x > 0; x -= step) {
            curr += function_b(x) * delta_x;
        }
    } while (fabs(curr - prev) > eps);

    return curr;
}

double calculate_c(double eps) {
    double delta_x = 1;
    double step = 1;
    double prev = function_c(0);
    double curr = prev;

    do {
        prev = curr;
        curr = 0;
        step /= 2;
        delta_x /= 2;

        for (double x = 0; x < 1; x += step) {
            curr += function_c(x) * delta_x;
        }
    } while (fabs(curr - prev) > eps);

    return curr;
}

double calculate_d(double eps) {
    double delta_x = 1;
    double step = 1;
    double prev = function_d(0);
    double curr = prev;

    do {
        prev = curr;
        curr = 0;
        step /= 2;
        delta_x /= 2;

        for (double x = 0.0; x <= 1.0; x += step) {
            curr += function_d(x) * delta_x;
        }
    } while (fabs(curr - prev) > eps);

    return curr;
}

int main(int argc, char* argv[]) {

    if (check_epsilon_validity(argv[1]) == 0) {
        printf("Incorrect epsilon value\n");
        return 0;
    };

    double eps = atof(argv[1]);
    double res_a = calculate_a(eps);
    double res_b = calculate_b(eps);
    double res_c = calculate_c(eps);
    double res_d = calculate_d(eps);
    
    printf("The result of the calculation of a.: %f\n", res_a);
    printf("The result of the calculation of b.: %f\n", res_b);
    printf("The result of the calculation of c.: %f\n", res_c);
    printf("The result of the calculation of d.: %f\n", res_d);

    return 0;
}