/*forward_list_name.insert_after(iterator position, element)

or,

forward_list_name.insert_after(iterator position, n, element)

or,

forward_list_name.insert_after(iterator position, itr1, itr2)

or,

forward_list_name.insert_after(iterator position, list)*/

// C++ program to illustrate the 
// forward_list::insert_after() function 
#include <forward_list> 
#include <iostream> 
#include <list> 

using namespace std; 

int main() 
{ 

	forward_list<int> fwlist = { 1, 2, 3, 4, 5 }; 
	list<int> sampleList = { 8, 9, 10 }; 

	// This iterator points to the first element 
	auto it_new = fwlist.begin(); 

	// New element to be inserted 
	int element = 20; 

	/******************************/
	/** IMPLEMENTING SYNTAX 1 *****/
	/******************************/
	it_new = fwlist.insert_after(it_new, element); 

	cout << "After Syntax 1: "; 
	for (auto it = fwlist.cbegin(); it != fwlist.cend(); it++) { 
		cout << *it << " "; 
	} 

	// it_new points to new element inserted which is 20 
	// Make it to point to next element 
	it_new++; 

	/******************************/
	/** IMPLEMENTING SYNTAX 2 *****/
	/******************************/
	it_new = fwlist.insert_after(it_new, 3, element); 

	cout << "\n\nAfter Syntax 2: "; 
	for (auto it = fwlist.cbegin(); it != fwlist.cend(); it++) { 
		cout << *it << " "; 
	} 

	/******************************/
	/** IMPLEMENTING SYNTAX 3 *****/
	/******************************/
	it_new = fwlist.insert_after(it_new, sampleList.begin(), 
								sampleList.end()); 

	cout << "\n\nAfter Syntax 3: "; 
	for (auto it = fwlist.cbegin(); it != fwlist.cend(); it++) { 
		cout << *it << " "; 
	} 

	/******************************/
	/** IMPLEMENTING SYNTAX 4 *****/
	/******************************/
	it_new = fwlist.insert_after(it_new, { 50, 60 }); 

	cout << "\n\nAfter Syntax 4: "; 
	for (auto it = fwlist.cbegin(); it != fwlist.cend(); it++) { 
		cout << *it << " "; 
	} 

	return 0; 
} 
