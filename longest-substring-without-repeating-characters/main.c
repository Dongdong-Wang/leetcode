#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string.h"

int main(int argc, char **argv) {
    int max = 0;

    if (argc == 2) {
        max = substr_max_num(argv[1], strlen(argv[1]));
    }
    printf("max: %d\n", max);
    return 0;
}