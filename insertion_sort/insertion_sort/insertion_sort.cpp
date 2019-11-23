#include "pch.h"
#include <iostream>
#include "Data.h"

int main()
{
	int n;
	std::cout << "import total: ";
	std::cin >> n;
	int *a = new int[n];
	int type;
	std::cout << "0. Random\n1. Sorted\n2. Reverse\n3. Nearly sorted\n";
	do {
		std::cout << "Type: ";
		std::cin >> type;
		double time_sec = GenerateData(a, n, type);
		std::cout << "Time: " << time_sec * 1000 << " milisecs" << std::endl;
		std::cout << "-----------------------------" << std::endl;
	} while (type > -1 && type < 4);
	delete[]a;
	return 0;
}


