#include "pch.h"
#include "heap.h"
#include <iostream>
#include "Data.h"

using namespace std;

//Hàm đổi chỗ nếu node con của node cha đang xét lớn hơn node cha
void heapify(int *a, int n, int i)
{
	while (i <= n / 2 - 1) {
		int c1 = 2 * i + 1;
		int c2 = 2 * i + 2;
		int m = c1;
		if (c2<n&&a[c2]>a[m]) {
			m = c2;
		}
		if (a[i] < a[m]) {
			swap(a[i], a[m]);
		}
		i = m;
	}
}

//Hàm xây dựng heap
void heap_sort(int *a, int n)
{
	for (int i = n / 2 - 1; i >= 0; i--) {
		heapify(a, n, i);
	}
	for (int i = n - 1; i >= 0; i--) {
		swap(a[0], a[i]);
		heapify(a, i, 0);
	}
}


//Hàm tính thời gian thực thi
double running_time(clock_t start, clock_t end)
{
	double run_time = double(end - start) / double(CLOCKS_PER_SEC);
	return run_time;
}

void display(int n, int *a)
{
	for (int i = 0; i < n; i++) {
		cout <<""<<i+1<<": "<< a[i] << endl;
	}
}