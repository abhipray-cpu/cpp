/*Counting sort is a linear time sorting algorithm that sort in O(n+k) 
time when elements are in the range from 1 to k.

What if the elements are in the range from 1 to n2? 
We can’t use counting sort because counting sort will take O(n2) 
which is worse than comparison-based sorting algorithms. Can we sort such an array in linear time? 

Radix Sort is the answer. The idea of Radix Sort is to do digit by digit
 sort starting from least significant digit to most significant digit. 
 Radix sort uses counting sort as a subroutine to sort.*/

 /*Original, unsorted list:
170, 45, 75, 90, 802, 24, 2, 66

Sorting by least significant digit (1s place) gives: 
[*Notice that we keep 802 before 2, because 802 occurred 
before 2 in the original list, and similarly for pairs 
170 & 90 and 45 & 75.]

Sorting by next digit (10s place) gives: 
[*Notice that 802 again comes before 2 as 802 comes before 
2 in the previous list.]

802, 2, 24, 45, 66, 170, 75, 90

Sorting by the most significant digit (100s place) gives:
2, 24, 45, 66, 75, 90, 170, 802*/

#include<iostream>
#define goal 69
using namespace std;

class radixSort
{
    public:
    int arr[goal];
    int get_max(int n);
    void count_sort(int n,int exp);
    void sort_it(int n);
    void print_array();
};

void radixSort::print_array()
{
    for(int i=0;i<goal;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void radixSort::sort_it(int n)
{
   // Find the maximum number to know number of digits 
    int m = get_max(n); 
  
    // Do counting sort for every digit. Note that instead 
    // of passing digit number, exp is passed. exp is 10^i 
    // where i is current digit number 
    for (int exp = 1; m / exp > 0; exp *= 10) 
        count_sort(n,exp);
}

void radixSort::count_sort(int n,int exp)
{
   int output[n]; // output array 
    int i, count[10] = { 0 }; 
  
    // Store count of occurrences in count[] 
    for (i = 0; i < n; i++) 
        count[(arr[i] / exp) % 10]++; 
  
    // Change count[i] so that count[i] now contains actual 
    //  position of this digit in output[] 
    for (i = 1; i < 10; i++) 
        count[i] += count[i - 1]; 
  
    // Build the output array 
    for (i = n - 1; i >= 0; i--) { 
        output[count[(arr[i] / exp) % 10] - 1] = arr[i]; 
        count[(arr[i] / exp) % 10]--; 
    } 
  
    // Copy the output array to arr[], so that arr[] now 
    // contains sorted numbers according to current digit 
    for (i = 0; i < n; i++) 
        arr[i] = output[i];
}

int radixSort::get_max(int n)
{
    int mx = arr[0]; 
    for (int i = 1; i < n; i++) 
        if (arr[i] > mx) 
            mx = arr[i]; 
    return mx; 
}

int main()
{
    radixSort rs;
    for(int i=0;i<goal;i++)
    {
        rs.arr[i]=rand();
    }
    rs.sort_it(goal);
    rs.print_array();
    return 0;
}
