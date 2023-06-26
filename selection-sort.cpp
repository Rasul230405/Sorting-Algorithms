// selection-sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
using namespace std;

void selection_sort(int A[], int n)
{
    for (int i = 0; i < n - 1; ++i) {
        int min = i;
        for (int j = i + 1; j < n; ++j) {
            if (A[j] < A[min]) min = j;
        }
        swap(A[i], A[min]);
    }
}

int main()
{
    int A[5] = { 3, 2, 6, 8, 11 };
    selection_sort(A, 5);
    for (int i = 0; i < 5; ++i) {
        cout << A[i] << " ";
    }
}

