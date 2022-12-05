#include "stdio.h"
#include "math.h"

#define MAX_ROW_COUNTER 1000

float calc(const float x, const float precision, int *counter) {
    float eth_res = sinf(x) * sinf(x) * sinf(x);
    printf("Ethalon result: %f\n", eth_res);
    float temp_clear = -x;
    float temp_value = -x;
    float final_sum = 0;
    int i = 1;
    do {
        temp_clear = (temp_clear * (-1) * (x * x)) / ((2 * i + 1) * (2 * i));
        temp_value = (temp_value * (-1) * (x * x) * (3 * 3)) / ((2 * i + 1) * (2 * i));
        final_sum += temp_value - temp_clear;
        i += 1;
    } while ((fabsf(eth_res - (final_sum * 3 / 4)) > precision) && (i < MAX_ROW_COUNTER));
    if (i >= MAX_ROW_COUNTER) {
        *counter = -1;
        return final_sum * 3 / 4;
    } else {
        *counter = i;
        return final_sum * 3 / 4;
    }
}

int main(void) {
    float x = 0;
    int status;
    float precision = 0;
    printf("Type x for sin ^ 3(x) formula:\n");
    do {
        status = scanf("%f", &x);
        if (status == EOF) return 0;
        if (!status) {
            printf("Incorrect input, try again:\n");
            scanf("%*[^\n]*c");
        }
    } while (status <= 0);

    printf("\nType precision (diff between ethalon result and calc):\n");
    do {
        status = scanf("%f", &precision);
        if (status == EOF) return 0;
        if (!status) {
            printf("Incorrect input, try again:\n");
            scanf("%*[^\n]*c");
        }
    } while (status <= 0);
    int counter = 0;
    float res = calc(x, precision, &counter);
    if (counter != -1) {
        printf("sin^3(x) = %.7f\n", res);
        printf("Number of row members: %d", counter);
    } else {
        printf("Error occurred, cant get value due to type calculation limitations");
    }
}
