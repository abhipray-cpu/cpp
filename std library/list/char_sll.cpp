#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class charList
{
    public:
    list <char> ch;
    void show_list(list <char> ch);
    
};
void charList::show_list(list <char> ch)
{
    list <char>::iterator it;
    for(it=ch.begin();it!=ch.end();it++)
{
               cout<<'\t'<<*it;
               cout<<'\n';
}
}

int main()
{
    charList A;
    charList B;
    A.ch.push_back('a');
    A.ch.push_back('b');
    A.ch.push_back('c');
    A.ch.push_back('d');
    A.ch.push_back('e');
    A.ch.push_back('f');
    A.ch.push_back('g');
    A.ch.push_back('h');
    A.ch.push_back('i');
    A.ch.push_back('j');
    A.ch.push_back('k');
    A.ch.push_back('l');
    A.ch.push_back('m');
    A.ch.push_back('n');
    A.ch.push_back('o');
    A.ch.push_back('p');
    A.ch.push_back('q');
    A.ch.push_back('r');
    A.ch.push_back('s');
    A.ch.push_back('t');
    A.ch.push_back('u');
    A.ch.push_back('v');
    A.ch.push_back('w');
    A.ch.push_back('x');
    A.ch.push_back('y');
    A.ch.push_back('z');

    B.ch.push_front('A');
    B.ch.push_front('B');
    B.ch.push_front('H');
    B.ch.push_front('I');
    B.ch.push_front('P');
    B.ch.push_front('R');
    B.ch.push_front('Y');
    B.ch.push_front('D');
    B.ch.push_front('U');
    B.ch.push_front('M');
    B.ch.push_front('K');
    B.ch.push_front('A');
    B.ch.push_front('T');
    B.ch.push_front('H');
    B.ch.push_front('E');
    B.ch.push_front('G');
    B.ch.push_front('R');
    B.ch.push_front('E');
    B.ch.push_front('A');
    B.ch.push_front('T');

    A.show_list(A.ch);
    cout<<"This is the second list "<<'/n';
    B.show_list(B.ch);
    A.ch.reverse();
    B.ch.reverse();
    cout<<" /n The reverse order lists are /n";
    A.show_list(A.ch);
    cout<<"/n";
    B.show_list(B.ch);

      //all the functions available in this list container
      /*Functions used with List:

front() – Returns the value of the first element in the list.
back() – Returns the value of the last element in the list .
push_front(g) – Adds a new element ‘g’ at the beginning of the list .
push_back(g) – Adds a new element ‘g’ at the end of the list.
pop_front() – Removes the first element of the list, and reduces size of the list by 1.
pop_back() – Removes the last element of the list, and reduces size of the list by 1
list::begin() and list::end() in C++ STL– begin() function returns an iterator pointing to the first element of the list
end()– end() function returns an iterator pointing to the theoretical last element which follows the last element.
list rbegin() and rend() function in C++ STL– rbegin() returns a reverse iterator which points to the last element of the list. rend() returns a reverse iterator which points to the position before the beginning of the list.
list cbegin() and cend() function in C++ STL– cbegin() returns a constant random access iterator which points to the beginning of the list. cend() returns a constant random access iterator which points to the end of the list.
list crbegin() and crend() function in C++ STL– crbegin() returns a constant reverse iterator which points to the last element of the list i.e reversed beginning of container. crend() returns a constant reverse iterator which points to the theoretical element preceding the first element in the list i.e. the reverse end of the list.
empty() – Returns whether the list is empty(1) or not(0).
insert() – Inserts new elements in the list before the element at a specified position.
erase() – Removes a single element or a range of elements from the list.
assign() – Assigns new elements to list by replacing current elements and resizes the list.
remove() – Removes all the elements from the list, which are equal to given element.
list::remove_if() in C++ STL– Used to remove all the values from the list that correspond true to the predicate or condition given as parameter to the function.
reverse() – Reverses the list.
size() – Returns the number of elements in the list.
list resize()function in C++ STL– Used to resize a list container.
sort() – Sorts the list in increasing order.
list max_size() function in C++ STL– Returns the maximum number of elements a list container can hold.
list unique() in C++ STL– Removes all duplicate consecutive elements from the list.
list::emplace_front() and list::emplace_back() in C++ STL– emplace_front() function is used to insert a new element into the list container, the new element is added to the beginning of the list. emplace_back() function is used to insert a new element into the list container, the new element is added to the end of the list.
list::clear() in C++ STL– clear() function is used to remove all the elements of the list container, thus making it size 0.
list::operator= in C++ STL– This operator is used to assign new contents to the container by replacing the existing contents.
list::swap() in C++ STL– This function is used to swap the contents of one list with another list of same type and size.
list splice() function in C++ STL– Used to transfer elements from one list to another.
list merge() function in C++ STL– Merges two sorted lists into one
list emplace() function in C++ STL– Extends list by inserting new element at a given position.*/

cout<<A.ch.front()<<endl;
cout<<B.ch.back()<<endl;
B.ch.unique();
cout<<"/n swapping both the list /n";
A.ch.swap(B.ch);
A.show_list(A.ch);
cout<<"/n";
B.show_list(B.ch);
cout<<"/n merging the two lists /n";
A.ch.merge(B.ch);
cout<<"The merged list is /n";
A.show_list(A.ch);

//splice function
B.ch.splice(B.ch.begin(),A.ch);//transfers all elements of A to C
cout<<"The size of list C is = "<<B.ch.size()<<"/n";
B.show_list(B.ch);



    
    return 0;




}