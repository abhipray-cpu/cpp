/*In this method we divide the entire list into two parts
one conataining all the elements smaller than the the selected node
and other part containing all the nodes greater than the selcted node
we sort these tow lists seprately and then merge them

Best for sorting linked list
1)Divide the array into two parts
2)sort them 
3)merge them

This algo is not stable

*/

//We use merge function to merge the 2 halves
/*
MergeSort(arr[], l,  r)
If r > l
     1. Find the middle point to divide the array into two halves:  
             middle m = (l+r)/2
     2. Call mergeSort for first half:   
             Call mergeSort(arr, l, m)
     3. Call mergeSort for second half:
             Call mergeSort(arr, m+1, r)
     4. Merge the two halves sorted in step 2 and 3:
             Call merge(arr, l, m, r)
             */


#include<iostream>
using namespace std;
#define MAX 1000

class Mergesort
{
   public:
   int arr[MAX];
   void mergeSort(int l,int r);
   void merge(int l,int m,int r);
   void printArray();
   };


void Mergesort::mergeSort(int l,int r)
{
    if(l>=r)
    {
        return;
    }
    int m=(l+r)/2;
    mergeSort(l,m);//lowe half
    mergeSort(m+1,r);//greater half
    merge(l,m,r);//merging the 2 halfs
}

void Mergesort::merge(int l,int m,int r)
{
      int n1=m-l+1;//left half plus the mid element
      int n2=r-m;//the right of mid element
      int L[n1],R[n2];//these arrays are used to store values coressponding to halfs in which we are dividing the values based on the middle values

      //copying the elements into the container
      for(int i=0;i<n1;i++)
      {
          L[i]=arr[i+l];//we are storing values of lower half in L
      }
      for(int j=0;j<n2;j++)
      {
          R[j]=arr[m+1+j];//we are storing value of upper half in R
      }

      int i=0;//initial index of left array
      int j=0;//initial indec of right array
      int k=l;//initial index of subarray

       while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
//copy the remaining elements of left array
// as remaining lower half is for sure to contain values less than remaining upper half
while(i<n1)
{
    arr[k]=L[i];
    k++;
    i++;
}

//copy the remaining elements of right array
//finally we will be copying the remaining values from upper half

while(j<n2)
{
    arr[k]=R[j];
    k++;
    j++;
}

}

void Mergesort::printArray()
{
    for(int i=0;i<MAX;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    Mergesort MS;
    for(int i=0;i<MAX;i++)
    {
        MS.arr[i]=rand();
    }

    MS.mergeSort(0,MAX-1);
    MS.printArray();
    return 0;

}


