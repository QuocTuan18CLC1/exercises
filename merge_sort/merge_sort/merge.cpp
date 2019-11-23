#include "pch.h"
#include "merge.h"
#include <iostream>
#include "Data.h"

using namespace std;

//Hàm nối mảng
void merge(int *a, int l, int m, int r)
{
	int *arr = new int[r - l + 1];
	int i = l;
	int j = m + 1;
	for (int k = 0; k <= r - l; k++) {
		if (a[i] < a[j]) {
			arr[k] = a[i];
			i++;
		}
		else {
			arr[k] = a[j];
			j++;
		}
		if (i == m + 1) {
			while (j <= r) {
				k++;
				arr[k] = a[j];
				j++;
			}
			break;
		}
		if (j == r + 1) {
			while (i <= m) {
				k++;
				arr[k] = a[i];
				i++;
			}
			break;
		}
	}
	for (int k = 0; k <= r - l; k++) {
		a[l + k] = arr[k];
	}
	delete arr;
}

//Hàm chia mảng lớn thành mảng phụ
void merge_sort(int *a, int l, int r)
{
	if (l < r) {
		int mid = (r + l) / 2; 
		merge_sort(a, l, mid); 
		merge_sort(a, mid + 1, r);
		merge(a, l, mid, r); 
	}
}

//Hàm tính thời gian thực thi 
double running_time(clock_t start, clock_t end)
{
	double time = double(end - start) / double(CLOCKS_PER_SEC);
	return time;
}