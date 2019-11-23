#include "pch.h"
#include "quick.h"
#include <iostream>
#include "Data.h"

using namespace std;

//Hàm tạo vách ngăn
int Partition(int *a, int left, int right) {
	int p = a[left];
	int i = left;
	int j = right + 1;
	do {
		do { 
			i++; 
		} while (a[i] < p);
		do {
			j--; 
		} while (a[j] > p);
		swap(a[i], a[j]);
	} while (i < j);
	swap(a[i], a[j]); // hủy lần hoán đổi cuối khi i >= j
	swap(a[left], a[j]);
	return j;
	
}

//Hàm sắp xếp sau khi có vách ngăn
void quick_sort(int *a, int left, int right)
{
	if (left < right) {
		int s = Partition(a, left, right);
		quick_sort(a, left, s - 1);
		quick_sort(a, s + 1, right);
	}
}

//Hàm tính thời gian thực thi
double running_time(clock_t start, clock_t end) 
{
	double time_run = double(end - start) / double(CLOCKS_PER_SEC);
	return time_run;

}


