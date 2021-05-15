void two_sum(int *array, int array_size, int target, int *x, int *y)
{
    int one, another;
    int hashset_ready = 0, hashset[10000] = {};

    for (*x = 0; *x < array_size; ++(*x)) {
        one = target - array[*x];
        if (hashset_ready) {
            if ((*y = hashset[one]) && (*y != *x)) {
                return;
            }
            continue;
        }
        for (*y = *x + 1; *y < array_size; ++(*y)) {
            another = array[*y];
            if (another == one) {
                return;
            }
            hashset[another] = *y;
        }
        hashset_ready = 1;
    }
}