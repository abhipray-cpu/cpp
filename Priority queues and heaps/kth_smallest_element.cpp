// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;

// Function to find kth smallest array element
int kthSmallest(vector<int>& v, int N, int K)//max heap in this case
{
	// Implement Max Heap using
	// a Priority Queue
	priority_queue<int> heap1;

	for (int i = 0; i < N; ++i) {

		// Insert elements into
		// the priority queue
		heap1.push(v[i]);

		// If size of the priority
		// queue exceeds k
		if (heap1.size() > K) {
			heap1.pop();
		}
	}

	// Print the k-th smallest element
	return heap1.top();
}
int kthLargest(vector<int>& v, int N, int K)//min heap in this case
{
	// Implement Max Heap using
	// a Priority Queue
	priority_queue<int,vector<int>,greater<int>> heap1;

	for (int i = 0; i < N; ++i) {

		// Insert elements into
		// the priority queue
		heap1.push(v[i]);

		// If size of the priority
		// queue exceeds k
		if (heap1.size() > K) {
			heap1.pop();
		}
	}

	// Print the k-th smallest element
	return heap1.top();
}

// Driver code
int main()
{
	// Given array
	vector<int> vec={ 5, 20, 10, 7, 1 };

	// Size of array
	int N = vec.size();

	// Given K
	int K = 2;

	// Function Call
	cout<<kthSmallest(vec, N, K % N)<<endl;
    cout<<kthLargest(vec,N,K % N);

	return 0;
}
