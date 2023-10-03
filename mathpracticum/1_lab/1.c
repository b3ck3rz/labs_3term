#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>


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

int sum_of_numbers(int number) {
    int result = 0;
    
    for(int i = 1; i <= number; i++) {
        result += i;
    }

    return result;
}

int factorial(int number) {
    int result = 1;
    for(int i = 1; i <= number; i++) {
        result *= i;
    }
    
    return result;
}

int main(int argc, char *argv[]) {

    if (argc < 3) {
        printf("Not enough values to unpack (expected 3, got 2)");
        return 0;
    }

    int number = atoi(argv[2]);

    if (argv[1][1] == 'h') {
        if (number == 0) {
            printf("Wrong value");
        }
        int count = 100 / number;
        if (count == 0) {
            printf("Multiples not found");
            return 0;
        }
        int* result = (int*)malloc(sizeof(int)*count);
        multiples_numbers(result, number, count);
        for (int i = 0; i < count; i++) {
            printf("%d ", result[i]);
        } 
        free(result);

        return 0;
    }

    if (argv[1][1] == 'p') {
        (is_prime(number) == 0) ? printf("The number is prime") : printf("The number is composite");

        return 0;
    }

    if (argv[1][1] == 's') {
        for (int i = 0; argv[2][i] != '\0'; i++) {
            printf("%c ", argv[2][i]);
        }

        return 0;
    }

    if (argv[1][1] == 'e') {
        for (int i = 1; i <= 10; i++) {
            long long res = i;
            for (int j = 0; j < number; j++) {
                printf("%d ", res);
                res *= i;
            }
            printf("\n");
        }

        return 0;
    }

    if (argv[1][1] == 'a') {
        int sum = sum_of_numbers(number);

        printf("The sum of numbers is %d", sum);

        return 0;
    }

    if(argv[1][1] == 'f') {
        printf("The factorial of %d is %d", number, factorial(number));

        return 0;
    }

    return 0;
}