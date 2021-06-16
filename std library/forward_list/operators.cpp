#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
       forward_list<int>FL;
       for(int i=0;i<69;i++)
       {
           FL.push_front(i);
       }
       for(int i=0;i<69;i++)
       {
           FL.emplace_front(rand());//note this is same as push operation but the value to be insertes should be unique
       }
       forward_list<int>::iterator it;
       for(it=FL.begin();it!=FL.end();it++)
       {
           cout<<*it<<" ";
       }
       cout<<endl;
       for(int i=0;i<23;i++)
       {
           FL.pop_front();
       }
                   FL.assign({56,46,76,34,23,54,27});
                   //multiple different values
                   for(it=FL.begin();it!=FL.end();it++)
       {
           cout<<*it<<" ";
       }
       
                 FL.assign(23,69);//assign can be used to insert multiple elments at once//same element
                            for(it=FL.begin();it!=FL.end();it++)
       {
           cout<<*it<<" ";
       }
       FL.remove(69);//removes the particular element
       //assign inserts the element at end of list
       
             
}

//assign :position plus value
/*2. push_front() :- This function is used to insert the element at the first position on forward list.
 The value from this function is copied to the space before first element in the container. The size of forward list increases by 1.

3. emplace_front() :- This function is similar to the previous function but in 
this no copying operation occurs, the element is created directly at the memory before the first element of the forward list.

4. pop_front() :- This function is used to delete the first element of list. */

/*4. insert_after() This function gives us a choice to insert elements at any position in
 forward list. The arguments in this function are copied at the desired position.

5. emplace_after() This function also does the same operation as above function but the
 elements are directly made without any copy operation.

6. erase_after() This function is used to erase elements from a particular position in the forward list.*/

/*
7. remove() :- This function removes the particular element from the forward list mentioned in its argument.

8. remove_if() :- This function removes according to the condition in its argument.*/

//9. splice_after() :- This function transfers elements from one forward list to other. 
