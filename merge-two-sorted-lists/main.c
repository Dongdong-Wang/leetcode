#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(int argc, char **argv) {
    struct list *a, *b, *t, *c;

    a = c = calloc(1, sizeof(struct list));
    for (int i = 2; i < 10; i += 2) {
        t = calloc(1, sizeof(struct list));
        t->val = i;
        c->n = t;
        c = t;
    }

    b = c = calloc(1, sizeof(struct list));
    b->val = 1;
    for (int i = 3; i < 10; i += 2) {
        t = calloc(1, sizeof(struct list));
        t->val = i;
        c->n = t;
        c = t;
    }

    c = t = merge_list(a, b);

    while (t) {
        printf("val %d\n", t->val);
        t = t->n;
    }

    return 0;
}