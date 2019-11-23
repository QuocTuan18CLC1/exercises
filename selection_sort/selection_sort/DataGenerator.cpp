#include <iostream>
#include <fstream>
#include <cmath>
#include "pch.h"
#include <time.h>
#include "DataGenerator.h"
#include "selection.h"
using namespace std;


// Hàm phát sinh mảng dữ liệu ngẫu nhiên
void GenerateRandomData(int a[], int n)
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < n; i++)
	{
		a[i] = rand()%n;
	}
}

// Hàm phát sinh mảng dữ liệu có thứ tự tăng dần
void GenerateSortedData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
}

// Hàm phát sinh mảng dữ liệu có thứ tự ngược (giảm dần)
void GenerateReverseData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = n - 1 - i;
	}
}

// Hàm phát sinh mảng dữ liệu gần như có thứ tự
void GenerateNearlySortedData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
	srand((unsigned int) time(NULL));
	for (int i = 0; i < 10; i ++)
	{
		int r1 = rand()%n;
		int r2 = rand()%n;
		swap(a[r1], a[r2]);
	}
}

double GenerateData(int a[], int n, int dataType)
{
	clock_t start;
	clock_t end;
	switch (dataType)
	{
	case 0:	// ngẫu nhiên
		GenerateRandomData(a, n);
		start=clock();
		selection_sort(n, a);
		end=clock();
		break;
	case 1:	// có thứ tự
		GenerateSortedData(a, n);
		start = clock();
		selection_sort(n, a);
		end = clock();
		break;
	case 2:	// có thứ tự ngược
		GenerateReverseData(a, n);
		start = clock();
		selection_sort(n, a);
		end = clock();
		break;
	case 3:	// gần như có thứ tự
		GenerateNearlySortedData(a, n);
		start = clock();
		selection_sort(n, a);
		end = clock();
		break;
	default:
		printf("Error: unknown data type!\n");
	}
	return running_time(start, end);
}

