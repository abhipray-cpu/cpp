//min to max heap
// A C++ program to convert min Heap to max Heap
#include<bits/stdc++.h>
using namespace std;

// to heapify a subtree with root at given index
void MaxHeapify(int arr[], int i, int n)
{
	int l = 2*i + 1;
	int r = 2*i + 2;
	int largest = i;
	if (l < n && arr[l] > arr[i])
		largest = l;
	if (r < n && arr[r] > arr[largest])
		largest = r;
	if (largest != i)
	{
		swap(arr[i], arr[largest]);
		MaxHeapify(arr, largest, n);
	}
}

// This function basically builds max heap
void convertMaxHeap(int arr[], int n)
{
	// Start from bottommost and rightmost
	// internal mode and heapify all internal
	// modes in bottom up way
	for (int i = (n-2)/2; i >= 0; --i)
		MaxHeapify(arr, i, n);
}

void MinHeapify(int arr[], int i, int n)
{
	int l = 2*i + 1;
	int r = 2*i + 2;
	int largest = i;
	if (l < n && arr[l] < arr[i])
		largest = l;
	if (r < n && arr[r] < arr[largest])
		largest = r;
	if (largest != i)
	{
		swap(arr[i], arr[largest]);
		MinHeapify(arr, largest, n);
	}
}

// This function basically builds max heap
void convertMinHeap(int arr[], int n)
{
	// Start from bottommost and rightmost
	// internal mode and heapify all internal
	// modes in bottom up way
	for (int i = (n-2)/2; i >= 0; --i)
		MinHeapify(arr, i, n);
}


// A utility function to print a given array
// of given size
void printArray(int* arr, int size)
{
	for (int i = 0; i < size; ++i)
		printf("%d ", arr[i]);
}

// Driver program to test above functions
int main()
{
	// array representing Min Heap
	int arr1[] = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9};
	int n1 = sizeof(arr1)/sizeof(arr1[0]);

	printf("Min Heap array : ");
	printArray(arr1, n1);

	convertMaxHeap(arr1, n1);

	printf("\nMax Heap array : ");
	printArray(arr1, n1);
    int arr2[] = {20,18,10,12,9,9,3,5,6,8};
	int n2 = sizeof(arr2)/sizeof(arr2[0]);

	printf("\nMax Heap array : ");
	printArray(arr2, n2);

	convertMinHeap(arr2, n2);

	printf("\nMin Heap array : ");
	printArray(arr2, n2);

	return 0;
}
