//we can sort the array before implementing the same logic in that duplicate elements can be grouped near each other
#include<bits/stdc++.h>
using namespace std;
#define MAX_SIZE 1000
int test[MAX_SIZE];
int counter =0;
void initializeArr(int  size)
{
 for(int i=0;i<size;i++)
 {
     test[i] = rand();
 }
}
void displayArray(int size)
{
    for(int i=0;i<size;i++)
    {
          cout<<test[i]<<"\t";
    }
}
//in this simple approach of O(n2) complexit we will check each element for each element and then remove it
void removeDuplicates(int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=i+1;j<size;j++)
         {
              if(test[i] == test[j])//in this case we have a found a duplicate
              {
                  //moving it to the last position and incrementing the end counter
                  ++counter;
                  int temp = test[j];
                  test[j] = test[size-1];
                  test[size-1] = temp;
              }
        }
    }
    //in this case we will discard all elements from size-counter to size-1
    for(int j=size-counter+1; j<size; j++) {
        test[j]=0;//since these elements will be duplicate
    }

}
void sortElements(int size)
{
   //using simple linear shorts
   for(int i=0; i<size; i++) {
         for(int j=i+1;j<size;j++)
          {
              if(test[j]<test[i])
              {
                  int temp = test[j];
                  test[j]=test[i];
                  test[i]=temp;
              }
          }
   }
}
int main()
{    
   initializeArr(100);
   cout<<"This is the original array which might contain duplicates."<<endl;
   displayArray(100);
   test[6]=41;
   sortElements(100);
   removeDuplicates(100);
   cout<<"This is the same array after removing the duplicate elemetns \n";
   displayArray(100);
     return 0;
}