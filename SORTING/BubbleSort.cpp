// #include<iostream>
// using namespace std;

// class BubbleSorting
// {
//     public:
//     int arr[1000];
//     void sort();
// };

// void BubbleSorting::sort()
// {
//      int size=1000;
//      for(int i=0;i<size;i++)
//      {
//          for(int j=i+1;j<size;j++)
//          {
//              if(arr[i] > arr[j])
//              {
//                  int temp=arr[i];
//                  arr[i]=arr[j];
//                  arr[j]=temp;
//              }
//          }
//      }   
// }
// int main()
// {
//     BubbleSorting Sort;
//     for(int i=0;i<1000;i++)
//     {
//         Sort.arr[i]=rand();
//     }

//     cout<<"The array before sorting is"<<endl;
//     for(int i=0;i<1000;i++)
//     {
//         cout<<Sort.arr[i]<<" ";
//     }
//     Sort.sort();
//     cout<<endl<<endl<<endl;
//     cout<<"The array after sorting is"<<endl;
//       for(int i=0;i<1000;i++)
//     {
//         cout<<Sort.arr[i]<<" ";
//     }
//     return 0;
// }

    

  //Bubble sort can also be used to find whether an array is already sorted or not?
  /*use a swap=0 variable and increment it if any swap occurs if value !=0 than thea 
  array is not sorted*/

//   #include<iostream>
//   #define MAX 1000
//   using namespace std;

//   class Sorted
//   {
//       public:
//       int arr[MAX];
//       bool isSorted();
//   };

//   bool Sorted::isSorted()
//   {
//       int swap=0;
//        for(int i=0;i<MAX;i++)
//      {
//          for(int j=i+1;j<MAX;j++)
//          {
//              if(arr[i] > arr[j])
//              {
//                  int temp=arr[i];
//                  arr[i]=arr[j];
//                  arr[j]=temp;
//                  ++swap;
//              }
//              if(swap !=0)
//              break;
//          }
//          if(swap !=0)
//          break;
//      } 
//     if(swap != 0)
//     {
//          return false;
//     }
//     else
//     return true;
//   }

//   int main()
//   {
//       Sorted Sort1;
//       Sorted Sort2;
//       for(int i=0;i<1000;i++)
//       {
//           Sort1.arr[i]=i;
//           Sort2.arr[i]=rand();
//       }
//       bool val1=Sort1.isSorted();
//       bool val2=Sort2.isSorted();
//       cout<<val1<<endl<<val2<<endl;
//       return 0;
//   }

  
  //This is the modified version
  
  #include<iostream>
  #define MAX 1000
  using namespace std;

  class Sorted
  {
      public:
      int arr[MAX];
      bool isSorted();
  };

  bool Sorted::isSorted()
  {
  
  int pass,i,temp,swapped=1;

  for(pass=1000-1;pass>=0&&swapped;pass--)
  {
      swapped=0;
      for(i=0;i<=pass-1;i++)
      {
          if(arr[i]>arr[i+1])
          {
              temp=arr[i];
              arr[i]==arr[i+1];
              arr[i+1]=temp;
              swapped=1;
          }
      }
  }
  
  
  }




  int main()
  {
      Sorted Sort1;
      Sorted Sort2;
      for(int i=0;i<1000;i++)
      {
          Sort1.arr[i]=i;
          Sort2.arr[i]=rand();
      }
      Sort2.isSorted();
      for(int i=0;i<1000;i++)
      {
          cout<<Sort2.arr[i]<<" ";
      }
      return 0;
  }