//priority queue is used when a prioority is associated with an element
//element with highers priority is always at fron of queue i.e all the operations on queue are performed as per the priority of element

//std library allow two priority
/*
maxHeap:the descending ie largest element is given the higherst priority
minHeap:ascending order i.e the smallest element is given the highest priority*/

//maxHeap
// Note that by default C++ creates a max-heap
// for priority queue
// #include <iostream>
// #include <queue>

// using namespace std;

// void showpq(priority_queue<int> gq)
// {
// 	priority_queue<int> g = gq;
// 	while (!g.empty()) {
// 		cout << '\t' << g.top();
// 		g.pop();
// 	}
// 	cout << '\n';
// }

// int main()
// {
// 	priority_queue<int> gquiz;
// 	gquiz.push(10);
// 	gquiz.push(30);
// 	gquiz.push(20);
// 	gquiz.push(5);
// 	gquiz.push(1);

// 	cout << "The priority queue gquiz is : ";
// 	showpq(gquiz);

// 	cout << "\ngquiz.size() : " << gquiz.size();
// 	cout << "\ngquiz.top() : " << gquiz.top();

// 	cout << "\ngquiz.pop() : ";
// 	gquiz.pop();
// 	showpq(gquiz);

// 	return 0;
// }

//minHeap
//this is the syntax to create a min heap
//priority_queue <int, vector<int>, greater<int>> g = gq;  

// C++ program to demonstrate min heap
#include <iostream>
#include <queue>

using namespace std;

void showpq(
	priority_queue<int, vector<int>, greater<int> > gq)
{
	priority_queue<int, vector<int>, 
								greater<int> > g = gq;
	while (!g.empty()) {
		cout << '\t' << g.top();
		g.pop();
	}
	cout << '\n';
}

int main()
{
	priority_queue<int, vector<int>, 
					greater<int> > gquiz;
	gquiz.push(10);
	gquiz.push(30);
	gquiz.push(20);
	gquiz.push(5);
	gquiz.push(1);

	cout << "The priority queue gquiz is : ";
	showpq(gquiz);

	cout << "\ngquiz.size() : " << gquiz.size();
	cout << "\ngquiz.top() : " << gquiz.top();

	cout << "\ngquiz.pop() : ";
	gquiz.pop();
	showpq(gquiz);

	return 0;
}


