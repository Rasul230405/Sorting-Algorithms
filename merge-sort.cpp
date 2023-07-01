
/* 
	This file contains implementation of merge sort
	Merge sort:							    How to merge:
		4 2 7 6 5 8							4 2 7 6 5 8					
		/        \							/        \
	  4 2 7     6 5 8					  2 4 7     5 6 8
	  /   \     /   \					Select the first unpicked element from both arrays
     4   2 7   6    5 8					Compare them and put lesser value to the main array
	     / \        /  \				Iterate steps above until there is no unpicked element in both arrays
		2   7      5    8		
*/

#include <iostream>
using namespace std;

void merge(int A[], int left[], int l1, int right[], int l2)
{
	int i = 0;  // keep track of index of left
	int j = 0;	// keep track of index of right	
	int k = 0;	// keep track of index of A

	while (i < l1 && j < l2) {
		if (left[i] <= right[j]) {
			A[k] = left[i];
			++i;
		}
		else {
			A[k] = right[j];
			++j;
		}
		++k;
	}

	while (i < l1) {
		A[k] = left[i];
		++i;
		++k;
	}
	while (j < l2) {
		A[k] = right[j];
		++j;
		++k;
	}
}

void merge_sort(int A[], int length)
{
	if (length < 2) return;
	int middle = length / 2;
	int* left = new int[middle];
	int* right = new int[length - middle];

	for (int i = 0; i < middle; ++i) left[i] = A[i];
	for (int i = middle; i < length; ++i) right[i - middle] = A[i];

	merge_sort(left, middle);
	merge_sort(right, length - middle);
	merge(A, left, middle, right, length - middle);
}

int main()
{
	int A[5] = { 4, 2, 7, 5, 8 };
	merge_sort(A, 5);
	for (int i = 0; i < 5; ++i) cout << A[i] << " ";
}


