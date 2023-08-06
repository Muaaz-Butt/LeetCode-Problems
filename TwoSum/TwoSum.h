#pragma once
#ifndef TWOSUM_H
#define TWOSUM_H

class TwoSum {
public:
	TwoSum();
	~TwoSum();
	void inputArrayAndTarget();
	void twoSum();
private:
	int* array;
	int target;
	int noOfElements;
};

#endif TWOSUM_H
