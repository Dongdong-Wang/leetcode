#ifndef STRUCT_LIST
#define STRUCT_LIST

struct list {
    int val;
    struct list *n;
};

#endif /*STRUCT_LIST*/

#ifdef RECURSION

static inline struct list *merge_list(struct list *a, struct list *b)
{
    if (!a) {
        return b;
    }
    if (!b) {
        return a;
    }
    if (a->val > b->val) {
        b->n = merge_list(a, b->n);
        return b;
    }
    a->n = merge_list(a->n, b);
    return a;
}

#else /*!RECURSION*/

static inline struct list *merge_list(struct list *a, struct list *b)
{
    struct list phead = {}, *t = &phead;

    while (a && b) {
        if (a->val > b->val) {
            t->n = b;
            t = b;
            b = b->n;
            continue;
        }
        t->n = a;
        t = a;
        a = a->n;
    }
    t->n = a ? a : b;

    return phead.n;
}

#endif /*RECURSION*/