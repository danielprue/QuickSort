#include "QS.h"

void QS::sortAll() {

	primarySort(0, getSize() - 1);
	return;

	/*
	//if size is 0, return nothing
	if (getSize() == 0 || myArray == nullptr) {
		return;
	}

	//if size is 1, it's already in order
	else if (getSize() == 1) {
		return;
	}

	//if size is 2, swap them if needed
	else if (getSize() == 2) {
		if (myArray[0] > myArray[1]) {
			int temp = myArray[0];
			myArray[0] = myArray[1];
			myArray[1] = temp;
		}
		return;
	}

	//if size is 3 or greater, then do the things
	else {
		int left = 0;
		int right = getSize() - 1;
		int pivot = medianOfThree(left, right);

		int upperLeft = pivot;
		int lowerLeft = 0;

		int upperRight = getSize() - 1;
		int lowerRight = pivot - 1;

		partition(left, right, pivot);


		while () {

		}

	}

	return;
	*/
}

void QS::primarySort(int left, int right) {
	if (left < right) {
		int pivot = medianOfThree(left, right);
		pivot = partition(left, right, pivot);
		if (right - left > 5) {
			primarySort(left, pivot - 1);
			primarySort(pivot + 1, right);
		}
	}
	return;
}

//Alpha content, breaks program :/ maybe?
//PART 2 WORKING
//PART 3 WORKING
int QS::medianOfThree(int left, int right) {
	//return -1 if the array is empty
	if (getSize() == 0 || myArray == nullptr) {
		return -1;
	}

	//nothing inbetween two numbers
	//because int things
	if (left + 1 == right) {
		return -1;
	}

	//I guess this one doesn't work either
	if (left == right) {
		return -1;
	}

	//return -1 if an invalid index is given
	if (left < 0 || right > getSize() - 1) {
		return -1;
	}

	//how could I forget this one??
	if (left > right) {
		return -1;
	}

	int middle = (left + right) / 2;
	int temp1 = myArray[left];
	int temp2 = myArray[middle];
	int temp3 = myArray[right];

	if (temp2 < temp1) {
		myArray[left] = temp2;
		myArray[middle] = temp1;
		temp1 = myArray[left];
		temp2 = myArray[middle];
		temp3 = myArray[right];
	}

	if (temp3 < temp2) {
		myArray[middle] = temp3;
		myArray[right] = temp2;
		temp1 = myArray[left];
		temp2 = myArray[middle];
		temp3 = myArray[right];
	}

	if (temp2 < temp1) {
		myArray[left] = temp2;
		myArray[middle] = temp1;
	}


	return middle;
}

//PART 3 SO CLOSE TO WORKING
int QS::partition(int left, int right, int pivotIndex) {

	//check for nullptr
	if (myArray == nullptr) {
		return -1;
	}

	//make sure the bounds exist
	if (left < 0 || right >= getSize()) {
		return -1;
	}

	//make sure left is on the left of right
	if (left - right >= 0) {
		return -1;
	}

	//make sure the pivot is in the range of left and right
	if (pivotIndex < left || pivotIndex > right) {
		return -1;
	}

	int temp1 = myArray[pivotIndex];
	int temp2 = myArray[left];

	myArray[left] = temp1;
	myArray[pivotIndex] = temp2;

	int i = left + 1;
	int j = right;

	while (i < j) {
		while (myArray[i] < myArray[left]) {
			i++;
		}

		while (myArray[j] > myArray[left]) {
			j--;
		}

		if (myArray[i] == myArray[left]) {
			i++;
		}

		if (myArray[j] == myArray[left] && j != left) {
			j--;
		}

		if (i < j) {
			temp1 = myArray[i];
			temp2 = myArray[j];

			myArray[i] = temp2;
			myArray[j] = temp1;
		}
	}

	if (i >= j) {
		temp1 = myArray[j];
		temp2 = myArray[left];

		myArray[j] = temp2;
		myArray[left] = temp1;

		return j;
	}
}

//probs some bugs, idk yet
//PART 1 WORKING
//PART 2 WORKING
//PART 3 WORKING
string QS::getArray() const{
	if (myArray == nullptr || getSize() == 0) {
		return "";
	}

	string soFar = to_string(myArray[0]);
	for (int n = 1; n < getSize(); n++) {
		if (myArray[n] != -999999999) {
			soFar += ",";
			soFar += to_string(myArray[n]);
		}
	}

	return soFar;
}

//not super confident about this one but w/e
//PART 1 WORKING
//PART 2 WORKING
//PART 3 WORKING
int QS::getSize() const{
	if (myArray != nullptr) {
		int counter = 0;
		for (int i = 0; i < myArrayLength; i++) {
			if (myArray[i] != -999999999) {
				counter++;
			}
		}
		return counter;
	}
	return 0;
}

//Working ish?
//PART 1 WORKING
//PART 2 WORKING
//PART 3 WORKING
bool QS::addToArray(int value) {
	for (int i = 0; i < myArrayLength; i++) {
		if (myArray[i] == -999999999) {
			myArray[i] = value;
			return true;
		}
	}
	return false;
}

//should be working
//PART 1 WORKING
//PART 2 WORKING
//PART 3 WORKING
bool QS::createArray(int capacity) {
	//check for valid entry of capacity
	if (capacity <= 0) {
		return false;
	}

	//if there is already an array, then get rid of it
	clear();

	//add a new array with the input capacity
	myArray = new int[capacity];
	myArrayLength = capacity;

	//fill array with NULLs
	for (int i = 0; i < capacity; i++) {
		myArray[i] = -999999999;
	}

	return true;
}

//should be working
//PART 1 WORKING
//PART 2 WORKING
//PART 3 WORKING
void QS::clear() {
	int* temp = myArray;
	myArray = nullptr;

	//if (myArray != nullptr) {
	delete[] temp;
	myArrayLength = 0;
	//}
	return;
}