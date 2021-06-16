/*Counting sort is a sorting technique based on keys between a specific range.
It works by counting the number of objects having distinct key values
(kind of hashing). Then doing some arithmetic
 to calculate the position of each object in the output sequence.*/

/*For simplicity, consider the data in the range 0 to 9. 
Input data: 1, 4, 1, 2, 7, 5, 2
  1) Take a count array to store the count of each unique object.
  Index:     0  1  2  3  4  5  6  7  8  9
  Count:     0  2  2  0   1  1  0  1  0  0

  2) Modify the count array such that each element at each index 
  stores the sum of previous counts. 
  Index:     0  1  2  3  4  5  6  7  8  9
  Count:     0  2  4  4  5  6  6  7  7  7

The modified count array indicates the position of each object in 
the output sequence.
 
  3) Output each object from the input sequence followed by 
  decreasing its count by 1.
  Process the input data: 1, 4, 1, 2, 7, 5, 2. Position of 1 is 2.
  Put data 1 at index 2 in output. Decrease count by 1 to place 
  next data 1 at an index 1 smaller than this index.*/


//   #include<bits/stdc++.h>
//   #include<string.h>
//   #define range 255 // as there are 255 possible characters we can encounter while sorting
//   using namespace std;

// class CountingSort
// {
//     public:
//     string str;
//     void sortPLZ();
//     void printPLZ();
// };

// void CountingSort::sortPLZ()
// {
//     char output[sizeof(str)];//we will be using to store the elements while sorting process
//     int count[range+1],i;//to keep count of occurence of elements
//     memset(count,0,sizeof(count));

//     //storing the count of each element
//     for(i=0;str[i];i++)
//     {
//       ++count[str[i]];
//     }
//     //change the count array so that the array stores the actual index of the coressponding character
//     for(i=1;i<=range;i++)
//     {
//         count[i]+=count[i-1];
//     }

//     //building the output array to store the elements in sorted order
//     for (i = sizeof(str)-1; i>=0; --i)  
//     {  
//         output[count[str[i]]-1] = str[i];  
//         --count[str[i]];  
//     }  
//        for (i = 0; str[i]; ++i) 
//         str[i] = output[i]; 

// }

// void CountingSort::printPLZ()
// {
//     for(int i=0;i<sizeof(str);i++)
//     {
//         cout<<str[i]<<" ";
//     }
//     cout<<endl;
// }

// int main()
// {
//     CountingSort CS;
//     cout<<"Plz enter your string to be sorted without any spaces"<<endl;
//     cin>>CS.str;
//     cout<<"Hey mate this is your string"<<endl;
//     CS.printPLZ();
//     cout<<"Lets see your string after sorting it"<<endl;
//     CS.sortPLZ();
//     CS.printPLZ();
//     return 0;

// }

// C++ Program for counting sort 
#include <bits/stdc++.h> 
#include <string.h> 
using namespace std; 
#define RANGE 255 

// The main function that sort 
// the given string arr[] in 
// alphabatical order 
void countSort(char arr[]) 
{ 
	// The output character array 
	// that will have sorted arr 
	char output[strlen(arr)]; 

	// Create a count array to store count of inidividul 
	// characters and initialize count array as 0 
	int count[RANGE + 1], i; 
	memset(count, 0, sizeof(count)); 

	// Store count of each character 
	for (i = 0; arr[i]; ++i) 
		++count[arr[i]]; 

	// Change count[i] so that count[i] now contains actual 
	// position of this character in output array 
	for (i = 1; i <= RANGE; ++i) 
		count[i] += count[i - 1]; 

	// Build the output character array 
	for (i = 0; arr[i]; ++i) { 
		output[count[arr[i]] - 1] = arr[i]; 
		--count[arr[i]]; 
	} 

	/* 
	For Stable algorithm 
	for (i = sizeof(arr)-1; i>=0; --i) 
	{ 
		output[count[arr[i]]-1] = arr[i]; 
		--count[arr[i]]; 
	} 
	
	For Logic : See implementation 
	*/

	// Copy the output array to arr, so that arr now 
	// contains sorted characters 
	for (i = 0; arr[i]; ++i) 
		arr[i] = output[i]; 
} 

// Driver code 
int main() 
{ 
	char arr[] = "geeksforgeeks"; 

	countSort(arr); 

	cout << "Sorted character array is " << arr; 
	return 0; 
} 

// This code is contributed by rathbhupendra 
