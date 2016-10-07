/*
 * Project name: Remove Duplicates from Sorted Array
 * Description: Given a sorted array, remove the duplicates in place such that each element appear only once
 *		and return the new length. Do not allocate extra space for another array, you must do this in place with constant memory.
 *		For example, Given input array A = [1,1,2], Your function should return length = 2, and A is now [1,2].
 * Author: Adam Yu Wen
 */
#include <iostream>

using namespace std;

int removeDuplicates(int arr[], int size) {
	// case 1: the size is 0, it means that there is nothing in the array
	if (size == 0) {
		return 0;
	}
	// case 2: the size is not 0
	else {
		int index = 0;
		for (int i = 1; i < size; i++) {
			if (arr[index] != arr[i]) {
				arr[++index] = arr[i];
			}
		}
		// because the number of size starts from 1
		return index + 1;
	}
}

int main() {
	// Create an array
	int A[3] = { 1, 1, 2 };
	
	// Show out the array
	cout << "The original array is ";
	for (int i = 0; i < 3; i++) {
		cout << A[i] << " ";
	}
	cout << endl;

	// Get the new size of the array
	int newSize = removeDuplicates(A, 3);

	// Show out the new array
	cout << "The newSize is " << newSize << endl;
	cout << "The new array is ";
	for (int i = 0; i < newSize; i++) {
		cout << A[i] << " ";
	}
	cout << endl;

	return 0;
}
