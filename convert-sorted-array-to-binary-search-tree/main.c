#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

static int search(struct tree_node *root, int x, int *found) {
    if (!root) {
        *found = 0;
        return 0;
    }
    if (root->val == x) {
        *found = 1;
        return 0;
    }
    if (root->val > x) {
        return 1 + search(root->left, x, found);
    }
    return 1 + search(root->right, x, found);
}

int main(int argc, char **argv) {
    int i, times, found, array[7] = { 1, 2, 3, 4, 5, 6, 7 };
    struct tree_node *root;

    root = array2bst(array, 7);

    times = search(root, 4, &found);
    if (times != 0 || found != 1) {
        printf("search %d %d times, found %d\n", 4, times, found);
        goto err;
    }

    for (i = 2; i <= 6; i += 4) {
        times = search(root, i, &found);
        if (times != 1 || found != 1) {
            printf("search %d %d times, found %d\n", i, times, found);
            goto err;
        }
    }

    for (i = 1; i <= 7; i += 2) {
        times = search(root, i, &found);
        if (times != 2 || found != 1) {
            printf("search %d, %d times, found %d\n", i, times, found);
            goto err;
        }
    }

    return 0;
err:
    return 1;
}