/*The unordered_set key_eq() is a built-in function in C++ STL which 
returns a boolean value according to the comparison. It returns the 
key equivalence comparison predicate used by the unordered_set.
 The key equivalence comparison is a predicate that takes two 
 arguments and returns a bool value indicating whether they are equal*/
 
 #include <iostream> 
#include <string> 
#include <unordered_set> 
using namespace std; 

int main() 
{ 

	// unordered_set mp is created 
	unordered_set<string> mp; 

	// the 2 strings are compared 
	bool
		r 
		= mp.key_eq()( 
			"1000 is a huge number", 
			"2000 is a huge number"); 

	cout << "strings are "; 

	if (r == 1) { 

		cout << "same"; 
	} 
	else { 

		// the strings are not same so r=0 
		cout << "not same"; 
	} 

	cout << "\n"; 

	return 0; 
} 
