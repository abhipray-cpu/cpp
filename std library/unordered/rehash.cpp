/*The unordered_set::rehash() is a built-in function in C++ STL which is 
used to set the number of buckets in the container of unordered_set to given 
size or more. If size is greater than the current size of the container, 
then rehash is called. If it is lower than the current size, then the function has no effect on bucket count of hash.

Syntax:

unordered_set_name.rehash(size_type n)
Parameter: The function accepts a mandatory parameter n which specifies the minimum number of buckets for the container.

Return Value: This function doesn’t returns anything.

Below programs illustrate the unordered_set::rehash() function:*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    unordered_set<string>S;
    S.rehash(69);
    S.insert("Teri maa ki chut");
    S.insert("Teri bahin ki chut");
    S.insert("Teri maa ka bhosda");
    S.insert("Ikri bahin ka burr");
    S.insert("Tum bsdwale");
    S.insert("Tumhare papa bsdwale");
    S.insert("Tumhare dada bsdwale");
    S.insert("Tumhaer nana bsdwale");
    S.insert("Bsdk nana ke baare mei khcuch matt kehna");
    S.insert("Mummy bahut decent famile se thi humari");
    cout<<"The bucket count of the ste is"<<S.bucket_count()<<end;
    return 0;
}