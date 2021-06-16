// CPP program to illustrate 
// Implementation of erase_after() function 
#include <forward_list> 
#include <iostream> 
using namespace std; 

int main() 
{ 
	forward_list<int> myflist{ 1, 2, 3, 4, 5 }; 
	forward_list<int>::iterator it; 

	it = myflist.begin(); 
	myflist.erase_after(it); 

	// Printing the forward list 
	for (auto it = myflist.begin(); it != myflist.end(); ++it) 
		cout << ' ' << *it; 
	return 0; 
} 
//erases the element afterr a given iterator position