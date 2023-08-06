#include <iostream>
#include "TwoSum.h"

using namespace std;

TwoSum::TwoSum() {
	array = nullptr;
	target = 0;
}

TwoSum::~TwoSum() {
	if (!array) {
		return;
	}
	delete[]array;
	array = nullptr;
}

void TwoSum::inputArrayAndTarget() {
	cout << "Enter No of elements in array: ";
	cin >> noOfElements;
	array = new int[noOfElements];
	int i = 0;
	cout << "Enter elements in array: ";
	while (i < noOfElements) {
		cin >> array[i];
		i++;
	}
	cout << "Enter target: ";
	cin >> target;
}

void TwoSum::twoSum() {
	for (int i = 0; i < noOfElements; i++) {
		for (int j = i + 1; j < noOfElements; j++) {
			if (array[i] + array[j] == target) {
				cout << "[" << i << ", " << j << "]";
				return;
			}
		}
	}
}