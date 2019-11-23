#include "pch.h"
#include <iostream>
#include "bubble.h"

//Hàm hoán vị nếu chúng không đứng theo thứ tự
void bubble_sort(int *a, int n) 
{
	for (int i = 1; i < n; i++) {
		for (int j = n - 1; j >= i; j--) {
			if (a[j] < a[j - 1]) {
				std::swap(a[j], a[j - 1]);
			}
		}
	}
}

//Hàm tính thời gian thực thi hàm sắp xếp
double running_time(clock_t start, clock_t end)
{
	double time = double(end - start) / double(CLOCKS_PER_SEC);
	return time;
}