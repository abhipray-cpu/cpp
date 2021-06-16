// // CPP program to illustrate 
// // Implementation of remove_if() function 
// #include <forward_list> 
// #include <iostream> 
// using namespace std; 
  
// // Predicate implemented as a function 
// bool even(const int& value) { return (value % 2) == 0; } 
  
// // Main function 
// int main() 
// { 
//     forward_list<int> myforwardlist{ 1, 2, 2, 2, 5, 6, 7 }; 
//     myforwardlist.remove_if(even); 
//     for (auto it = myforwardlist.begin(); it != myforwardlist.end(); ++it) 
//         cout << ' ' << *it; 
// } 

// a condition should be fulfilled first in order to remove the element

// CPP program to illustrate 
// Application of remove_if() function 
#include <forward_list> 
#include <iostream> 
using namespace std; 

// Predicate implemented as a function 
bool prime(const int& value) 
{ 
	int i; 
	for (i = 2; i < value; i++) { 
		if (value % i == 0) { 
			return false; 
			; 
			break; 
		} 
	} 
	if (value == i) { 
		return true; 
		; 
	} 
} 

// Main function 
int main() 
{ 
	forward_list<int> myforwardlist{ 2, 4, 6, 7, 9, 11, 13 }; 
	myforwardlist.remove_if(prime); 
	for (auto it = myforwardlist.begin(); it != myforwardlist.end(); ++it) 
		cout << ' ' << *it; 
} 

