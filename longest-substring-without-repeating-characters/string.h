
static inline int substr_max_num(char *str, int len) 
{
    int l, r, max = 0;
    char set[256] = {};

    r = 1;
    for (l = 0; l < len; ++l) {
        set[str[l]] = 1;
        for (; r < len; ++r) {
            if (set[str[r]]) {
                break;
            }
            set[str[r]] = 1;
        }
        if (r - l > max) {
            max = r - l;
        }
        set[str[l]] = 0;
    }

    return max;
}