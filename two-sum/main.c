#include <stdio.h>
#include <stdlib.h>
#include "number.h"

int main(int argc, char **argv) {
    int x, y, target = 6;
    int a[] = { 0, 3, 3, 1, 2 };
    int b[] = { 2, 3, 1, 5, 5 };
    int c[] = { 0, 4, 3, 1, 5 };
    int d[] = { 1, 6, 3, 0, 2 };

    two_sum(a, 5, 6, &x, &y);
    if (x != 1 || y != 2) {
        printf("array a : x %d y %d not expected\n", x, y);
        goto err;
    }
    two_sum(b, 5, 6, &x, &y);
    if (x != 2 || y != 4) {
        printf("array b : x %d y %d not expected\n", x, y);
        goto err;
    }
    two_sum(c, 5, 6, &x, &y);
    if (x != 3 || y != 4) {
        printf("array c : x %d y %d not expected\n", x, y);
        goto err;
    }
    two_sum(d, 5, 6, &x, &y);
    if (x != 1 || y != 3) {
        printf("array d : x %d y %d not expected\n", x, y);
        goto err;
    }
    return 0;
err:
    return 1;
}