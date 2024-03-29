/*unordered_map is an associated container that stores elements formed by
 combination of key value and a mapped value. The key value is used to uniquely identify the element 
and mapped value is the content associated with the key. Both key and value can be of any type predefined or user-defined.
Internally unordered_map is implemented using Hash Table, the key provided to map are hashed into indices of hash table that 
is why performance of data structure depends on hash function a lot but on an average the cost of search, insert and delete 
from hash table is O(1).*/
// C++ program to demonstrate functionality of unordered_map 
// #include <iostream> 
// #include <unordered_map> 
// using namespace std; 

// int main() 
// { 
// 	// Declaring umap to be of <string, double> type 
// 	// key will be of string type and mapped value will 
// 	// be of double type 
// 	unordered_map<string, double> umap; 

// 	// inserting values by using [] operator 
// 	umap["PI"] = 3.14; 
// 	umap["root2"] = 1.414; 
// 	umap["root3"] = 1.732; 
// 	umap["log10"] = 2.302; 
// 	umap["loge"] = 1.0; 

// 	// inserting value by insert function 
// 	umap.insert(make_pair("e", 2.718)); 

// 	string key = "PI"; 

// 	// If key not found in map iterator to end is returned 
// 	if (umap.find(key) == umap.end()) 
// 		cout << key << " not found\n\n"; 

// 	// If key found then iterator to that key is returned 
// 	else
// 		cout << "Found " << key << "\n\n"; 

// 	key = "lambda"; 
// 	if (umap.find(key) == umap.end()) 
// 		cout << key << " not found\n"; 
// 	else
// 		cout << "Found " << key << endl; 

// 	// iterating over all value of umap 
// 	unordered_map<string, double>:: iterator itr; 
// 	cout << "\nAll Elements : \n"; 
// 	for (itr = umap.begin(); itr != umap.end(); itr++) 
// 	{ 
// 		// itr works as a pointer to pair<string, double> 
// 		// type itr->first stores the key part and 
// 		// itr->second stroes the value part 
// 		cout << itr->first << " " << itr->second << endl; 
// 	} 
// } 

//A practical example of the problem is
// C++ program to find freq of every word using 
// unordered_map 
#include <bits/stdc++.h> 
using namespace std; 

// Prints frequencies of individual words in str 
void printFrequencies(const string &str) 
{ 
	// declaring map of <string, int> type, each word 
	// is mapped to its frequency 
	unordered_map<string, int> wordFreq; 

	// breaking input into word using string stream 
	stringstream ss(str); // Used for breaking words 
	string word; // To store individual words 
	while (ss >> word) 
		wordFreq[word]++; 

	// now iterating over word, freq pair and printing 
	// them in <, > format 
	unordered_map<string, int>:: iterator p; 
	for (p = wordFreq.begin(); p != wordFreq.end(); p++) 
		cout << "(" << p->first << ", " << p->second << ")\n"; 
} 

// Driver code 
int main() 
{ 
	string str = "geeks for geeks geeks quiz "
				"practice qa for"; 
	printFrequencies(str); 
	return 0; 
} 

