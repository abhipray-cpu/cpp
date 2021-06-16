// C++ program to illustrate the 
// forward_list::emplace_after() function 
#include <forward_list> 
#include <iostream> 

using namespace std; 

int main() 
{ 

	forward_list<int> fwlist = { 1, 2, 3, 4, 5 }; 

	auto it_new = fwlist.before_begin(); 

	// use of emplace_after function 
	// inserts elements at positions 
	it_new = fwlist.emplace_after(it_new, 8); 
	it_new = fwlist.emplace_after(it_new, 10); 

	// cout << "The elements are: " 
	for (auto it = fwlist.cbegin(); it != fwlist.cend(); it++) { 
		cout << *it << " "; 
	} 

	return 0; 
} 
