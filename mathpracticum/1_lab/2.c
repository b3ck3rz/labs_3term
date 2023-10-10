#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

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
        if (is_prime(i)) mult_primes *= (i - 1.0) / i;
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

double e_function(double x) {
    return (log(x) - 1);
}

double pi_function(double x) {
    return (sin(x));
}

double ln2_function(double x) {
    return (exp(x) - 2);
}

double sqrt2_function(double x) {
    return (pow(x, 2) - 2);
}

double gamma_function(double x) {
    return (exp(-x) - limit_for_equation(0.001));
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
    eps = 0.0000000000001;
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

    return (res_new - pow(3.14, 2) / 6.0);
}

double e_limit(double eps) {
    int n = 1;
    double res = 0.0;
    double res_new = 0.0;
    do {
        res = res_new;
        res_new = pow(1.0 + 1.0 / n, n);
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

double gamma_limit(double eps) { 
    int m = 1; 
    double prev = 0; 
    double curr = 0; 

    do { 
        m++; 
        prev = curr; 
        curr = 0; 
        double elem = 0; 
        double comb = m; 
        double lg = 0; 
  
        for (int k = 2; k <= m; k++) { 
            comb *= (m-k+1.0) / k; 
            lg += log(k); 
  
            elem = comb * lg / k; 
            if (k & 1) elem *= -1; 
            curr += elem; 
        } 
    } while (fabs(prev - curr) > eps); 

    return curr; 
 } 

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Not enough values\n");
        return 0;
    }
    if (argc > 2) {
        printf("Too many values\n");
        return 0;
    }
    if (check_epsilon_validity(argv[1]) == 0) {
        printf("Incorrect epsilon value\n");
        return 0;
    };

    double eps = atof(argv[1]);
    printf("The result of the calculation E\n");
    printf("By limit: %f\n", e_limit(eps));
    printf("By row: %f\n", e_row(eps));
    printf("By equation: %f\n", dichotomy(e_function, 2.0, 3.0, eps));

    printf("The result of the calculation PI\n");
    printf("By limit: %f\n", pi_limit(eps));
    printf("By row: %f\n", pi_row(eps));
    printf("By equation: %f\n", dichotomy(pi_function, 3.0, 4.0, eps));

    printf("The result of the calculation ln2\n");
    printf("By limit: %f\n", ln2_limit(eps));
    printf("By row: %f\n", ln2_row(eps));
    printf("By equation: %f\n", dichotomy(ln2_function, 0.0, 1.0, eps));

    printf("The result of the calculation sqrt2\n");
    printf("By limit: %f\n", sqrt2_limit(eps));
    printf("By row: %f\n", sqrt2_row(eps));
    printf("By equation: %f\n", dichotomy(sqrt2_function, 1.0, 2.0, eps));

    printf("The result of the calculation gamma\n");
    printf("By limit: %f\n", gamma_limit(eps));
    printf("By row: %f\n", gamma_row(eps));
    printf("By equation: %f\n", dichotomy(gamma_function, 0.0, 1.0, eps));
}