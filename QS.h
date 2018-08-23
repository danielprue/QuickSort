#pragma once
#include <array>
#include "QSInterface.h"

class QS :public QSInterface {
public:
	QS() : myArray(nullptr), myArrayLength(0) {};
	~QS() { clear(); };

	void sortAll();
	void primarySort(int left, int right);
	int medianOfThree(int left, int right);
	int partition(int left, int right, int pivotIndex);
	string getArray() const;
	int getSize() const;
	bool addToArray(int value);
	bool createArray(int capacity);
	void clear();
private:
	int* myArray;
	int myArrayLength;
};