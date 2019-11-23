#include <algorithm>
#include <time.h>

void merge(int *a, int l, int m, int r);
void merge_sort(int *a, int l, int r);
double running_time(clock_t start, clock_t end);