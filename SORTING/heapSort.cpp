/*Well implemented quicksort is faster in practical case
it has and advantage over quicksort of worst case O(nlogn) run time
this is not a stable algorithm*/

/*Heap sort is a comparison based sorting technique based on Binary 
Heap data structure. It is similar to selection sort where we first
 find the maximum element and place the maximum element at the end.
  We repeat the same process for the remaining elements.*/

  //sorting in ascending order
/*
1. Build a max heap from the input data. 

2. At this point, the largest item is stored at the 
root of the heap. Replace it with the last item of
 the heap followed by reducing the size of heap by 1.
  Finally, heapify the root of the tree. 


3. Repeat step 2 while size of heap is greater than 1.*/

/*Building a heap:

Heapify procedure can be applied to a node only if
 its children nodes are heapified. So the heapification
  must be performed in the bottom-up order.
Lets understand with the help of an example:
*/

//here is an example for heapification of tree
              /*Input data: 4, 10, 3, 5, 1
         4(0)
        /   \
     10(1)   3(2)
    /   \
 5(3)    1(4)

The numbers in bracket represent the indices in the array 
representation of data.

Applying heapify procedure to index 1:
         4(0)
        /   \
    10(1)    3(2)
    /   \
5(3)    1(4)

Applying heapify procedure to index 0:
        10(0)
        /  \
     5(1)  3(2)
    /   \
 4(3)    1(4)
The heapify procedure calls itself recursively to build heap
 in top down manner.*/

 #include<iostream>
 #define MAX 100
 using namespace std;

 class HeapSort
 {
     public:
     int arr[MAX];
     void heapify(int i,int n);
     void heapSort(int n);
     void printArray();
 };

 void HeapSort::printArray()
 {
     for(int i=0;i<MAX;i++)
     {
         cout<<arr[i]<<" ";
     }
     cout<<endl;
 }
 //this function is the one used to build the heap
 void HeapSort::heapify(int i,int n)
 {
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;
     // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

   // if largest is not
   if(largest!=i)
   {
       swap(arr[i],arr[largest]);
       heapify(largest,n);
   }


 }
//this function is the one doing sorting
 void HeapSort::heapSort(int n)
 {
       //building the heap i.e rearanging the elements
       for(int i=n/2-1;i>=0;i--)
       {
           heapify(i,n);
       }
       //extarcting elmentst from the heap
       for(int i=n-1;i>0;i--)
       {
           swap(arr[0],arr[i]);
           heapify(0,i);
       }

 }

 int main()
 {
     HeapSort HS;
     for(int i=0;i<MAX;i++)
     {
         HS.arr[i]=rand();
     }
     HS.heapSort(MAX);
     HS.printArray();
     return 0;
 }