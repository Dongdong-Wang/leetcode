#include <stdlib.h>
#include <stdio.h>

struct tree_node {
    int val;
    struct tree_node *left;
    struct tree_node *right;
};

static inline struct tree_node *array2bst(int *array, int len) {
    int mid;
    struct tree_node *t;

    if (len <= 0 || !array)
        return NULL;

    t = (struct tree_node *) calloc(1, sizeof(struct tree_node));

    mid = len / 2;
    t->val = array[mid];
    t->left = array2bst(&array[0], mid);
    t->right = array2bst((mid + 1 == len) ? NULL : &array[mid + 1], len - mid - 1);

    return t;
}