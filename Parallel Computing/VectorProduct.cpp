#include <iostream>
#include <vector>
#include "omp.h"

using namespace std;

void product(int low, int high, vector<int> v1, vector<int> v2, vector<int>& result) {
		for (int i = low; i < high; i++) 
			result.push_back(v1.at(i) * v2.at(i));
}

int main()
{	//create vectors
	vector<int> vec1 = { 1,3,4,5,6,7,1,8,4,7 }; 
	vector<int> vec2 = { 2,6,9,2,3,2,6,1,5,5 }; 
	int size = 10;

	//method 1: Regular iteration to compute dot product of two vectors
	vector<int> productVec1;
	for (int i = 0; i < size; i++) {
		productVec1.push_back(vec1.at(i) * vec2.at(i));
	}
	cout << "Product of two vectors without parallel computing:" << endl;
	for (int i = 0; i < size; i++) {
		cout << productVec1.at(i) << " ";
	}
	cout << endl;

	//method 2: Parallel computing to compute dot product of two vectors
	vector <int> productVec2;
	
#pragma omp parallel sections shared(size)
	{
#pragma omp section //Thread no.1 handles first half of both vectors
		product(0, size / 2, vec1, vec2, productVec2);
#pragma omp section //Thread no.2 handles second half of vectors
		product(size / 2, size, vec1, vec2, productVec2);
	}
	cout << "\nProduct of two vectors with parallel computing:" << endl;
	cout << "**NOTE: Order of products may vary**" << endl;

	for (int i = 0; i < size; i++) {
		cout << productVec2.at(i) << " ";
	}
	cout << endl;
	
}

