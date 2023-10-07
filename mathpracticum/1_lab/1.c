#include <stdio.h>
#include <stdlib.h>

void multiples_numbers(int* multiples_array, int number, int count) {
    multiples_array[0] = number;
    for (int i = 1; i < count; i++) {
            multiples_array[i] = multiples_array[i-1] + number;
    }
}

int is_prime(int number) {
    int count = 0;
    for (int i = 2; i*i <= number; i++) {
        if (number % i == 0) {
            count++;
        }
    }
    if (count > 0) {
        return 1;
    }
    return 0;
}

void power(int n, int m, long long powers[][m]) {
    for (int i = 1; i <= n; i++) {
        long long res = i;
        for (int j = 0; j < m; j++) {
            powers[i-1][j] = res;
            res *= i;
        }    
    }
}

int sum_of_numbers(int number) {
    int result = 0;
    
    for(int i = 1; i <= number; i++) {
        result += i;
    }

    return result;
}

int factorial(int number) {
    if (number == 0) {
        return 0;
    }
    int result = 1;
    for(int i = 1; i <= number; i++) {
        result *= i;
    }
    
    return result;
}

int main(int argc, char *argv[]) {

    if (argc < 3) {
        printf("Not enough values to unpack\n");
        return 0;
    }

    int number = atoi(argv[2]);

    if (argv[1][1] == 'h') {
        if (number == 0) {
            printf("Wrong value\n");
        }
        int count = 100 / number;
        if (count == 0) {
            printf("Multiples not found\n");
            return 0;
        }
        int result[count];
        multiples_numbers(result, number, count);
        for (int i = 0; i < count; i++) {
            printf("%d ", result[i]);
        } 

        return 0;
    }

    if (argv[1][1] == 'p') {
        (is_prime(number) == 0) ? printf("The number is prime\n") : printf("The number is composite\n");

        return 0;
    }

    if (argv[1][1] == 's') {
        for (int i = 0; argv[2][i] != '\0'; i++) {
            printf("%c ", argv[2][i]);
        }

        return 0;
    }


    if (argv[1][1] == 'e') {
        long long result[10][number];
        power(10, number, result);
        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < number; j++) {
                printf("%lld ", result[i][j]);
            }
            printf("\n");
        }

        return 0;
    }

    if (argv[1][1] == 'a') {
        int sum = sum_of_numbers(number);

        printf("The sum of numbers is %d\n", sum);

        return 0;
    }

    if(argv[1][1] == 'f') {
        printf("The factorial of %d is %d\n", number, factorial(number));

        return 0;
    }

}