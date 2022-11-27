#include "stdio.h"

float calc(const float x, const int precision) {
    float temp_value = -x;
    long long d_triple = 1;
    float final_sum = 0;
    for (int i = 1; i <= precision; ++i) {
        temp_value = (temp_value * (-1) * (x * x)) / ((2 * i + 1) * (2 * i));
        d_triple *= 9;
        final_sum += temp_value * (d_triple - 1);
    }
    return final_sum * 0.75;
}

int main (void) {
    float x = 0;
    int status;
    int precision = 0;
    printf("Type x for sin ^ 3(x) formula:\n");
    do {
        status = scanf("%f", &x);
        if (status == EOF) return 0;
        if (!status) {
            printf("Incorrect input, try again:\n");
            scanf("%*[^\n]*c");
        }
    } while (status <= 0);

    printf("\nType precision (number of row members):\n");
    do {
        status = scanf("%d", &precision);
        if (status == EOF) return 0;
        if (!status) {
            printf("Incorrect input, try again:\n");
            scanf("%*[^\n]*c");
        }
    } while (status <= 0);

    printf("sin^3(x) = %.7f", calc(x, precision));
}
