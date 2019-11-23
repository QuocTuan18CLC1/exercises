#include "pch.h"
#include "insertion.h"
#include <iostream>


void insertion_sort(int *a, int n)
{
	int v = 0;
	for (int i = 1; i < n; i++) {
		v = a[i]; //gán giá trị gần ngoài cùng bên trái cho v
		int j = i - 1;
		while (j >= 0 && a[j] > v) { //so sánh v với các giá trị đằng trước nó
			a[j + 1] = a[j];		 //nếu lớn hơn thì dịch giá trị đó sang phải 1 đơn vị
			j--;
		}
		a[j + 1] = v; //nếu nhỏ hơn hoặc bằng thì dịch v sang phải 1 đơn vị tính từ giá trị đang xét
	}
}

//Hàm tính thời gian thực thi hàm sắp xếp
double running_time(clock_t start, clock_t end)
{
	double time = double(end - start) / double(CLOCKS_PER_SEC);
	return time;
}