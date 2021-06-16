// C++ program for implementation of Heap Sort
#include <iostream>

using namespace std;

// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void Maxheapify(int arr[], int n, int i)
{
	int largest = i; // Initialize largest as root
	int l = 2 * i + 1; // left = 2*i + 1
	int r = 2 * i + 2; // right = 2*i + 2

	// If left child is larger than root
	if (l < n && arr[l] > arr[largest])
		largest = l;

	// If right child is larger than largest so far
	if (r < n && arr[r] > arr[largest])
		largest = r;

	// If largest is not root
	if (largest != i) {
		swap(arr[i], arr[largest]);

		// Recursively heapify the affected sub-tree
		Maxheapify(arr, n, largest);
	}
}
void Minheapify(int arr[], int n, int i)
{
	int smallest = i; // Initialize largest as root
	int l = 2 * i + 1; // left = 2*i + 1
	int r = 2 * i + 2; // right = 2*i + 2

	// If left child is larger than root
	if (l < n && arr[l] < arr[smallest])
		smallest = l;

	// If right child is larger than largest so far
	if (r < n && arr[r] < arr[smallest])
		smallest = r;

	// If largest is not root
	if (smallest != i) {
		swap(arr[i], arr[smallest]);

		// Recursively heapify the affected sub-tree
		Minheapify(arr, n, smallest);
	}
}

// main function to do heap sort
void heapSort(int arr[], int n,int type)
{
	if(type==1)//ascending order
    {
        // Build heap (rearrange array)
	for (int i = n / 2 - 1; i >= 0; i--)
		Maxheapify(arr, n, i);

	// One by one extract an element from heap
	for (int i = n - 1; i > 0; i--) {
		// Move current root to end
		swap(arr[0], arr[i]);

		// call max heapify on the reduced heap
		Maxheapify(arr, i, 0);
	}
    }
    else if(type == 0)//descending order min heap
    {
          // Build heap (rearrange array)
	for (int i = n / 2 - 1; i >= 0; i--)
		Minheapify(arr, n, i);

	// One by one extract an element from heap
	for (int i = n - 1; i > 0; i--) {
		// Move current root to end
		swap(arr[0], arr[i]);

		// call max heapify on the reduced heap
		Minheapify(arr, i, 0);
	} 
    }
}

/* A utility function to print array of size n */
void printArray(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}

// Driver code
int main()
{
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	int n = sizeof(arr) / sizeof(arr[0]);
   int type;
   cout<<"Enter one of the following options \n 1 for Ascending Sort \n 0 for descending Sort \n";
   cin >> type;
	heapSort(arr, n,type);

	cout << "Sorted array is \n";
	printArray(arr, n);
}
