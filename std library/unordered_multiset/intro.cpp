//unordered_set + multi_set=unordered_multi_set
// C++ program to demonstrate various function 
// of unordered_multiset 
#include <bits/stdc++.h> 
using namespace std; 

// making typedef for short declaration 
typedef unordered_multiset<int>::iterator umit; 

// Utility function to print unordered_multiset 
void printUset(unordered_multiset<int> ums) 
{ 
	// begin() returns iterator to first element of set 
	umit it = ums.begin(); 
	for (; it != ums.end(); it++) 
		cout << *it << " "; 
	cout << endl; 
} 

// Driver program to check all function 
int main() 
{ 
	// empty initialization 
	unordered_multiset<int> ums1; 

	// Initialization by intializer list 
	unordered_multiset<int> ums2 ({1, 3, 1, 7, 2, 3, 
								4, 1, 6}); 

	// Initialization by assignment 
	ums1 = {2, 7, 2, 5, 0, 3, 7, 5}; 

	// empty() function return true if set is empty 
	// otherwise false 
	if (ums1.empty()) 
		cout << "unordered multiset 1 is empty\n"; 
	else
		cout << "unordered multiset 1 is not empty\n"; 

	// size() function returns total number of elements 
	// in data structure 
	cout << "The size of unordered multiset 2 is : "
		<< ums2.size() << endl; 

	printUset(ums1); 

	ums1.insert(7); 

	printUset(ums1); 

	int val = 3; 

	// find function returns iterator to first position 
	// of val, if exist otherwise it returns iterator 
	// to end 
	if (ums1.find(val) != ums1.end()) 
		cout << "unordered multiset 1 contains "
			<< val << endl; 
	else
		cout << "unordered multiset 1 does not contains "
			<< val << endl; 

	// count function returns total number of occurrence in set 
	val = 5; 
	int cnt = ums1.count(val); 
	cout << val << " appears " << cnt 
		<< " times in unordered multiset 1 \n"; 

	val = 9; 

	// if count return >0 value then element exist otherwise not 
	if (ums1.count(val)) 
		cout << "unordered multiset 1 contains "
			<< val << endl; 
	else
		cout << "unordered multiset 1 does not contains "
			<< val << endl; 

	val = 1; 

	// equal_range returns a pair, where first is iterator 
	// to first position of val and second it iterator to 
	// last position to val 
	pair<umit, umit> erange_it = ums2.equal_range(val); 
	if (erange_it.first != erange_it.second) 
		cout << val << " appeared atleast once in "
						"unoredered_multiset \n"; 


	printUset(ums2); 

	// erase function deletes all instances of val 
	ums2.erase(val); 

	printUset(ums2); 

	// clear function deletes all entries from set 
	ums1.clear(); 
	ums2.clear(); 

	if (ums1.empty()) 
		cout << "unordered multiset 1 is empty\n"; 
	else
		cout << "unordered multiset 1 is not empty\n"; 
} 
//List of all the availabel methods
/*insert()– Inserts new elements in the unordered_multiset. Thus increases the container size.
begin()– Returns an iterator pointing to the first element in the container or to the first element in one of its bucket.
end()– Returns an iterator pointing to the position immediately after the last element in the container or to the position immediately after the last element in one of its bucket.
empty()– It returns true if the unordered_multiset container is empty. Otherwise, it returns false.
find()– Returns an iterator which points to the position which has the element val.
cbegin()– Returns a constant iterator pointing to the first element in the container or to the first element in one of its bucket.
cend()– Returns a constant iterator pointing to the position immediately after the last element in the container or to the position immediately after the last element in one of its bucket.
equal_range()– Returns the range in which all the elements are equal to a given value.
emplace()– Inserts a new element in the unordered_multiset container.
clear()– Clears the contents of the unordered_multiset container.
count()– Returns the count of elements in the unordered_multiset container which is equal to a given value.
size()– The size() method of unordered_multiset is used to count the number of elements of unordered_set it is called with.
max_size– The max_size() of unordered_multiset takes the maximum number of elements that the unordered_multiset container is able to hold.
swap()– Swaps the contents of two unordered_multiset containers.
erase() – Used to remove either a single element or, all elements with a definite value or, a range of elements ranging from start(inclusive) to end(exclusive).
bucket()– Returns the bucket number in which a given element is. Bucket size varies from 0 to bucket_count-1.
bucket_size()– Returns the number of elements in the bucket which has the element val.
reserve()– The reverse() function of unordered_multiset sets the number of buckets in the container (bucket_count) to the most appropriate to contain at least n elements.
max_bucket_count()– Returns the maximum number of buckets that the unordered multiset container can have.
load_factor()– Returns the current load factor in the unordered_multiset container.
max_load_factor()– Returns the maximum load factor of the unordered_multiset container.
bucket_count()– Returns the total number of buckets in the unordered_multiset container.
hash_function()– This hash function is a unary function which takes a single argument only and returns a unique value of type size_t based on it.
rehash()– Sets the number of buckets in the container to N or more.
key_eq()– Returns a boolean value according to the comparison.
emplace_hint()– Inserts a new element in the unordered_multiset container.
get_allocator– This function gets the stored allocator object and returns the allocator object which is used to construct the container.
operator =– The ‘=’ is an operator in C++ STL which copies (or moves) an unordered_multiset to another unordered_multiset and unordered_multiset::operator= is the corresponding operator function.*/