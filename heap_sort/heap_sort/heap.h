#include <algorithm>
#include <time.h>

void heapify(int *a, int n, int i);
void heap_sort(int *a, int n);

double running_time(clock_t start, clock_t end);
void display(int n, int *a);
