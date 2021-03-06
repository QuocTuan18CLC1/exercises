#include "pch.h"
#include <iostream>
#include "Data.h"

using namespace std;

int main()
{
	int n;
	cout << "Total number: ";
	cin >> n;
	int *a = new int[n];
	int type;
	cout << "0. Random\n1. Sorted\n2. Reverse\n3. Nearly sorted\n";
	cout << "Type: ";
	do {
		cin >> type;
		double time_sec = GenerateData(a, n, type);
		cout << "Time: " << time_sec * 1000 << " milisecs" << endl;
		cout << "---------------------------------" << endl;
	} while (type > -1 && type < 4);
	delete[]a;
	return 0;
}

