#include "pch.h"
#include "selection.h"
#include <iostream>

//Hàm di chuyển các phần tử về vị trí cuối cùng của chúng trong chuỗi 
void selection_sort(int n, int* a)
{
	for (int i = 0; i < n - 1; i++) {
		int minIdx = i;
		int minVal = a[i];
		for (int j = i + 1; j < n; j++) 
			if (a[j] < minVal) {
				minIdx = j;
				minVal = a[j];
			}
		a[minIdx] = a[i];
		a[i] = minVal;
	}
}

//Hàm tính thời gian thực thi của hàm sắp xếp
double running_time(clock_t start, clock_t end)
{
	double time = double(end - start) / double(CLOCKS_PER_SEC);
	return time;
}