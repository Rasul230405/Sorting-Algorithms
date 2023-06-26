// bubble_sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
using namespace std;

void bubble_sort(int A[], int n)
{
    for (int k = 1; k < n - 1; ++k) {
        bool flag = 0;
        for (int i = 0; i < n - k - 1; ++i) {
            if (A[i] > A[i + 1]) {
                swap(A[i], A[i + 1]);
                flag = 1;
            }
        }
        if (flag == 0) break;
    }
}

int main()
{
    int A[5] = { 3, 2, 6, 8, 11 };
    bubble_sort(A, 5);
    for (int i = 0; i < 5; ++i) {
        cout << A[i] << " ";
    }
}
