// C++ program to implement find and erase for specific
// key-value pair for unordered_multimap
#include <bits/stdc++.h>
using namespace std;

// making typedef for short declaration
typedef unordered_multimap<string, int>::iterator umit;

// function to check whether p is there in map or not
bool find_kv(unordered_multimap<string, int>& umm,
			pair<string, int> p)
{
	// equal_range returns pair of iterator of first and
	// last position associated with key
	pair<umit, umit> it = umm.equal_range(p.first);
	umit it1 = it.first;

	pair<string, int> tmp;

	// looping over all values associated with key
	while (it1 != it.second) 
	{
		tmp = *it1;
		if (tmp == p)
			return true;
		it1++;
	}
	return false;
}

// function to delete one copy of pair p from map umm
void erase_kv(unordered_multimap<string, int>& umm,
			pair<string, int> p)
{
	// equal_range returns pair of iterator of first and
	// last position associated with key
	pair<umit, umit> it = umm.equal_range(p.first);
	umit it1 = it.first;
	pair<string, int> tmp;

	// looping over all values associated with key
	while (it1 != it.second) 
	{
		tmp = *it1;
		if (tmp == p)
		{
			// iterator version of erase : deletes pair
			// at that position only
			umm.erase(it1);
			break;
		}
		it1++;
	}
}

// Utility function to print unordered_multimap
void printUmm(unordered_multimap<string, int> umm)
{
	// begin() returns iterator to first element of map
	umit it = umm.begin();
	for (; it != umm.end(); it++)
		cout << "<" << it->first << ", " << it->second
			<< "> ";
	cout << endl;
}

// Driver code
int main()
{
	// initializing multimap by initializer list
	unordered_multimap<string, int> umm({ { "apple", 1 },
										{ "ball", 2 },
										{ "apple", 10 },
										{ "cat", 7 },
										{ "dog", 9 },
										{ "cat", 6 },
										{ "apple", 1 } });

	cout << "Initial content\n";
	printUmm(umm);
	pair<string, int> kv = make_pair("apple", 1);

	// inserting one more <apple, 1> pair
	umm.insert({ "apple", 1 });
	cout << "\nAfter insertion of one more <apple, 1>\n";
	printUmm(umm);

	if (find_kv(umm, kv))
		erase_kv(umm, kv);
	else
		cout << "key-value pair is not there in unordered "
				"multimap\n";

	cout << "\nAfter deletion one occurrence of <apple, "
			"1>\n";
	printUmm(umm);
}
