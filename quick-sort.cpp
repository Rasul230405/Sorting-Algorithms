/*
    This file contains implementation of quick sort

    Quick sort logic:           Partition logic:

      4 2 7 6 5 8				- Initialize p_index with starting index and select pivot element			
        /        \				- If element is lesser than pivot, swap it with the element in the p_index and increment p_index 			
      4 2 7     6 5 8			- Do steps above until you reach end element		 
      /   \     /   \			- Swap the element in p_index with pivot		
     4   2 7   6    5 8					
         / \        /  \				
        2   7      5    8
*/
#include <iostream>
#include <algorithm>
using namespace std;

int partition(int A[], int start, int end)
{
    int p_index = start;
    int pivot = A[end];
    for (int i = start; i < end; ++i) {
        if (A[i] <= pivot) {
            swap(A[i], A[p_index]);
            ++p_index;
        }
    }
    swap(A[p_index], A[end]);
    return p_index;
}

void quick_sort(int A[], int start, int end)
{
    if (start < end) {
        int p_index = partition(A, start, end);
        quick_sort(A, start, p_index - 1);
        quick_sort(A, p_index, end);
    }
}

int main()
{
   const int n = 5;
   int A[n] = { 4, 2, 7, 5, 6 };
   quick_sort(A, 0, n - 1);
   for (int i = 0; i < n; ++i) cout << A[i] << " ";
}

