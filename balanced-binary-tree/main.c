#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "../convert-sorted-array-to-binary-search-tree/tree.h"
#include "../merge-two-sorted-lists/list.h"

struct tree_node *array2nbst(int *array, int len) {
    struct tree_node root = {}, *c, *p;

    p = &root;
    for (int i = 0; i < len; i++) {
        c = calloc(1, sizeof(struct tree_node));
        c->val = array[i];
        p->right = c;
        p = c;
    }
    return root.right;
}

int main(int argc, char **argv) {
    int array[7] = { 1, 2, 3, 4, 5, 6, 7 };
    struct tree_node *balanced, *not_balanced;

    balanced = array2bst(array, 7);
    if (!is_balanced(balanced)) {
        printf("should be balanced tree\n");
        goto err;
    }

    not_balanced = array2nbst(array, 7);
    if (is_balanced(not_balanced)) {
        printf("should not be balanced tree\n");
        goto err;
    }

    return 0;
err:
    return 1;
}