#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int check_epsilon_validity(char* eps) {
    int flag = 1;
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

int factorial(int number) {
    if (number == 0) {
        return 1.0;
    }
    int result = 1.0;
    for(int i = 1.0; i <= number; i++) {
        result *= i;
    }
    
    return result;
}

int is_prime(int number) {
    if (number > 1) {    
        for (int i = 2; i*i <= number; i++) {
            if (number % i == 0) {
                return 0;
            }
        }
        return 1;
    }
    return 0;
}

double mult_primes(int n) {
    double mult_primes = 1.0;

    for (int i = 2; i <= n; i++) {
        if (isprime(i)) mult_primes *= (i - 1.0) / i;
    }

    return mult_primes;
}

double limit_for_equation(double eps) {
    int t = 2;
    double res = 0.0;
    double res_new = 0.0;
    do {
        res = res_new;
        res_new = log(t) * mult_primes(t);
        t++;
    } while (fabs(res_new - res) > eps);

    return res_new;
}

double dichotomy(double (*func)(double x), double a, double b, double eps) {
    double x = 0.0;
    while (fabs(b - a) > eps) {
        x = (a + b) / 2.0;
        if (func(a) * func(x) < 0)
            b = x;
        else
            a = x;
    }
    return x;
}

double function_e(double x) {
    return (log(x) - 1);
}

double function_pi(double x) {
    return (sin(x));
}

double function_ln2(double x) {
    return (exp(x) - 2);
}

double function_sqrt2(double x) {
    return (pow(x, 2) - 2);
}

double function_gamma(double eps, double x) {
    return (exp(-x) - limit_for_equation(eps));
}

double e_row(double eps) {
    double elem = 0.0, elem_prev;
    int n = 0;
    do {
        elem_prev = elem;
        elem += (1.0/factorial(n));
        n++;

    } while (fabs(elem - elem_prev) >= eps); 

    return elem;
}

double pi_row(double eps) {
    int n = 1;
    double elem = 0.0, elem_prev;
    do {
        elem_prev = elem;
        elem += (pow(-1, n - 1)) / (2 * n - 1);
        n++;
    } while (fabs(elem - elem_prev) > eps);

    return (4 * elem);
}

double ln2_row(double eps) {
    int n = 1;
    double elem = 0.0, elem_prev;
    do {
        elem_prev = elem;
        elem += (pow(-1, n - 1)) / n;
        n++;
    } while (fabs(elem - elem_prev) > eps);

    return elem;
}

double sqrt2_row(double eps) {
    int n = 2;
    double elem = 0.0;
    double mult = 0.0;
    double mult_new = 1.0;
    double power = 0.25;
    do {
        mult = mult_new;
        elem = pow(2, power);
        power *= 0.5;
        mult_new *= elem;
        n++;
    } while (fabs(mult_new - mult) > eps);

    return mult;
}

double gamma_row(double eps) {   
    int k = 3;
    double res = 0.0;
    double res_new = 0.5;
    double elem = 0.0;
    do {
        res = res_new;
        elem = ((1.0 / pow(floor(sqrt(k)), 2)) - (1.0 / k));
        res_new += elem;
        if (elem < eps)
            res = 0.0;
        k++;
    } while (fabs(res_new - res) > eps);

    return (res_new - pow(PI, 2) / 6.0);
}

double e_limit(double eps) {
    int n = 1;
    double res = 0.0;
    double res_new = 0.0;
    do {
        result = result_new;
        result_new = pow(1.0 + 1.0 / n, n);
        n++;
    } while (fabs(res_new - res) > eps);

    return res;
}

double pi_limit(double eps) {
    int n = 1;
    double res = 0.0;
    double res_new = 4.0;
    do {
        res = res_new;
        res_new *= (4 * n * (n + 1)) / pow(2 * n + 1, 2);
        n++;
    } while (fabs(res_new - res) > eps);

    return res;
}

double ln2_limit(double eps) {
    int n = 1;
    double res = 0.0;
    double res_new = 0.0;
    do {
        res = res_new;
        res_new = n * (pow(2, 1.0 / n) - 1);
        n++;
    } while (fabs(res_new - res) > eps);

    return res;
}

double sqrt2_limit(double eps) {
    int n = 1;
    double res = 0.0;
    double res_new = -0.5;
    do {
        res = res_new;
        res_new = res - (pow(res, 2) / 2.0) + 1.0;
        n++;
    } while (fabs(res_new - res) > eps);

    return res;
}


int main() {
    double eps = 0.0001;
    double e = e_row(eps);
    double pi = pi_row(eps);
    double ln2 = ln2_row(eps);
    double sqrt2 = sqrt2_row(eps);
    printf("%f\n", e);
    printf("%f\n", pi);
    printf("%f\n", ln2);
    printf("%f\n", sqrt2);
}