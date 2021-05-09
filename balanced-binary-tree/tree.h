#include <stdlib.h>

#ifndef STRUCT_TREE_NODE
#define STRUCT_TREE_NODE

struct tree_node {
    int val;
    struct tree_node *left;
    struct tree_node *right;
};

#endif /*STRUCT_TREE_NODE*/

static inline int max(int a, int b)
{
    return a > b ? a : b;
}

static inline int height(struct tree_node *root)
{
    if (!root)
        return 0;

    return 1 + max(height(root->left), height(root->right));
}

static inline int is_balanced(struct tree_node *root)
{
    if (!root)
        return 1;

    return abs(height(root->left) - height(root->right)) <= 1 && 
        is_balanced(root->left) && is_balanced(root->right);
}