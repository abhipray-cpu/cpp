//This is also a divide and conquer algorithm
/*It uses the recursive calls
for the sorting and is a famous comaprison
based algorithm
*/

//This is the algorithm that is followed:
/*

1)If there are one or none elements in the array to be sorted return.

2)Pick up an element in array to serve as pivot(usually the left most element is selected)

3)Split the array in two part one with elements smalller than pivot and one with elements larger than pivot

4)Recursive call the algorithm for both halves of the original array



*/

/*
Here is a pseudo code:
 low  --> Starting index,  high  --> Ending index 
quickSort(arr[], low, high)
{
    if (low < high)
    {
         pi is partitioning index, arr[pi] is now
           at right place 
        pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);  // Before pi
        quickSort(arr, pi + 1, high); // After pi
    }
}

*/

#include<iostream>
#include<bits/stdc++.h>
#define MAX 1000
using namespace std;


class QuickSort
{
    public:
    int arr[MAX];
    void swap(int *a,int *b);
    int partition(int low,int high);
    void printArray();
    void quicksort(int low,int high);

};

void QuickSort::swap(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}

void QuickSort::printArray()
{
  for(int i=0;i<MAX;i++)
  {
      cout<<arr[i]<<" ";
  }
  cout<<endl;
}

/* This function takes last element as pivot, places  
the pivot element at its correct position in sorted  
array, and places all smaller (smaller than pivot)  
to left of pivot and all greater elements to right  
of pivot */

int QuickSort::partition(int low,int high)
{
        
 int pivot = arr[high];    // pivot 
    int i = (low - 1);  // Index of smaller element 
  
    for (int j = low; j <= high-1; j++) 
    { 
        // If current element is smaller than the pivot 
        if (arr[j] < pivot) 
        { 
            i++;    // increment index of smaller element 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1);
}

void QuickSort::quicksort(int low,int high)
{    int parti;
      if(low<high)
      {
          parti=partition(low,high);
          quicksort(low,parti-1);//lower half is sorted here
      quicksort(parti+1,high);//higher half is sorted here
}
      }
      

int main()
{
    QuickSort QS;
    for(int i=0;i<MAX;i++)
    {
        QS.arr[i]=rand();
    }
    QS.quicksort(0,MAX-1);
    QS.printArray();
    return 0;
}

//partition demo

// arr[] = {10, 80, 30, 90, 40, 50, 70}
// Indexes:  0   1   2   3   4   5   6 

// low = 0, high =  6, pivot = arr[h] = 70
// Initialize index of smaller element, i = -1

// Traverse elements from j = low to high-1
// j = 0 : Since arr[j] <= pivot, do i++ and swap(arr[i], arr[j])
// i = 0 
// arr[] = {10, 80, 30, 90, 40, 50, 70} // No change as i and j 
                                     // are same

// j = 1 : Since arr[j] > pivot, do nothing
// // No change in i and arr[]

// j = 2 : Since arr[j] <= pivot, do i++ and swap(arr[i], arr[j])
// i = 1
// arr[] = {10, 30, 80, 90, 40, 50, 70} // We swap 80 and 30 

// j = 3 : Since arr[j] > pivot, do nothing
// No change in i and arr[]

// j = 4 : Since arr[j] <= pivot, do i++ and swap(arr[i], arr[j])
// i = 2
// arr[] = {10, 30, 40, 90, 80, 50, 70} // 80 and 40 Swapped
// j = 5 : Since arr[j] <= pivot, do i++ and swap arr[i] with arr[j] 
// i = 3 
// arr[] = {10, 30, 40, 50, 80, 90, 70} // 90 and 50 Swapped 

// We come out of loop because j is now equal to high-1.
// Finally we place pivot at correct position by swapping
// arr[i+1] and arr[high] (or pivot) 
// arr[] = {10, 30, 40, 50, 70, 90, 80} // 80 and 70 Swapped 

// Now 70 is at its correct place. All elements smaller than
// 70 are before it and all elements greater than 70 are after
// it.

/*so we are just partioning around a pivot point
to find the smallest unit in sorted order and then merging them back
we can select either point as pivot
leftmost
rightmost
median
or we can select a point at random

How to know whetehe an element is in sorting order or not
if all the elements to the left of that element are lessere than it and 
all the elements to the right are greater than it than the element is in
correct sorting order rest of the elements may or may not be in correct order  but it is

*/