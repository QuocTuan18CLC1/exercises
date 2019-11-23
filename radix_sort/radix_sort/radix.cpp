#include "pch.h"
#include "radix.h"
#include <iostream>
#include "Data.h"

using namespace std;

//Hàm đếm sắp xếp dựa vào chữ số tượng trưng bởi biến exp
void RadixSort(int *a, int n)
{
	int i, max = a[0], exp = 1;
	int *b = new int[n + 1];
	for (i = 0; i < n; i++) //tìm giá trị lớn nhất trong mảng
	{
		if (a[i] > max)
			max = a[i];
	}
	while (max / exp > 0) 
	{
		int c[10] = { 0 }; //khởi tạo mảng chứa loại phần tử
		for (i = 0; i < n; i++) {
			c[(a[i] / exp) % 10]++; //lưu số lần xuất hiện của các chữ số vào c
		}
		for (i = 1; i < 10; i++) {
			c[i] += c[i - 1]; //thay đổi c[i] để c[i] chứa vị trí thực tế của i trong b
		}
		for (i = n - 1; i >= 0; i--) {
			b[--c[(a[i] / exp) % 10]] = a[i]; //lưu a vào b
		}
		for (i = 0; i < n; i++) { 
			a[i] = b[i]; //copy b vào a
		}
		exp *= 10;
	}
}

//Hàm tính thời gian thực thi
double running_time(clock_t start, clock_t end)
{
	double run_time = double(end - start) / double(CLOCKS_PER_SEC);
	return run_time;
}