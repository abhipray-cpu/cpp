/*map insert() in C++ STL– Insert elements with a particular key in the map container. .
map count() function in C++ STL– Returns the number of matches to element with key value ‘g’ in the map.
map equal_range() in C++ STL– Returns an iterator of pairs. The pair refers to the bounds of a range that includes all the elements in the container which have a key equivalent to k.
map erase() function in C++ STL– Used to erase element from the container.
map rend() function in C++ STL– Returns a reverse iterator pointing to the theoretical element right before the first key-value pair in the map(which is considered its reverse end).
map rbegin() function in C++ STL– Returns a reverse iterator which points to the last element of the map.
map find() function in C++ STL– Returns an iterator to the element with key value ‘g’ in the map if found, else returns the iterator to end.
map crbegin() and crend() function in C++ STL– crbegin() returns a constant reverse iterator referring to the last element in the map container. crend() returns a constant reverse iterator pointing to the theoretical element before the first element in the map.
map cbegin() and cend() function in C++ STL– cbegin() returns a constant iterator referring to the first element in the map container. cend() returns a constant iterator pointing to the theoretical element that follows last element in the multimap.
map emplace() in C++ STL– Inserts the key and its element in the map container.
map max_size() in C++ STL– Returns the maximum number of elements a map container can hold.
map upper_bound() function in C++ STL– Returns an iterator to the first element that is equivalent to mapped value with key value ‘g’ or definitely will go after the element with key value ‘g’ in the map
map operator= in C++ STL– Assigns contents of a container to a different container, replacing its current content.
map lower_bound() function in C++ STL– Returns an iterator to the first element that is equivalent to mapped value with key value ‘g’ or definitely will not go before the element with key value ‘g’ in the map.
map emplace_hint() function in C++ STL– Inserts the key and its element in the map container with a given hint.
map value_comp() in C++ STL– Returns the object that determines how the elements in the map are ordered (‘<' by default).
map key_comp() function in C++ STL– Returns the object that determines how the elements in the map are ordered (‘<' by default).
map::size() in C++ STL– Returns the number of elements in the map.
map::empty() in C++ STL– Returns whether the map is empty.
map::begin() and end() in C++ STL– begin() returns an iterator to the first element in the map. end() returns an iterator to the theoretical element that follows last element in the map
map::operator[] in C++ STL– This operator is used to reference the element present at position given inside the operator.
map::clear() in C++ STL– Removes all the elements from the map.
map::at() and map::swap() in C++ STL– at() function is used to return the reference to the element associated with the key k. swap() function is used to exchange the contents of two maps but the maps must be of same type, although sizes may differ.
 */

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    map<int,char>babu;
    char ch='a';
    for(int i=0;i<27;i++)
    {
        babu.insert(pair<int,char>(i,ch));
        ch++;
    }

    map<int,char>::iterator it;
    cout<<"map :: key"<<endl;
    for(it=babu.begin();it!=babu.end();it++)
    {
        cout<<it->first<<" :: "<<it->second<<endl;
    }

    cout<<babu.count(2)<<endl;//gives the number of matches(for which the key matches the given key here 2 )
    /*The map::equal_range() is a built-in function in C++ STL
     which returns a pair of iterators. The pair refers to the
      bounds of a range that includes all the elements in the 
      container which have a key equivalent to k. Since the map
       container only contains unique key, hence the first iterator 
       in the pair returned thus points to the element and the second
        iterator in the pair points to the next key which comes after
         key K. If there are no matches with key K, the range returned 
         is of length 1 with both iterators pointing to the an element
          which has a key denoting the size of map and elements as 0.*/

          pair<map<int,char>::iterator,
          map<int,char>::iterator> P;
          P=babu.equal_range(2);
          cout<<"The lower bound is : "<<P.first->first<<":"<<P.first->second<<endl<<"The upper bound is"
          <<P.second->first<<":"<<P.second->second<<endl;

          babu.erase(3);//here the key is passed and the coressponding key:value pair is erased from the container
            for(it=babu.begin();it!=babu.end();it++)
    {
        cout<<it->first<<" :: "<<it->second<<endl;
    }
          map<int,char>::reverse_iterator rev;
          for(rev=babu.rbegin();rev!=babu.rend();rev++)//printing the map elements in reverse order
          {
              cout<<rev->first<<":"<<rev->second<<endl;
          }

          //find method this returns an iterattor to the element if found the only params it take is the key 
          it=babu.find(23);
          cout<<"The returned key:value pair is:"<<it->first<<":"<<it->second<<endl;

        //   cout<<"Printing the map in reverse order with constant iterators"<<endl;
        //   for(rev=babu.crbegin();rev!=babu.crend();rev++)
        //   {
        //        cout<<"Key ="<<rev->first<<"::"<<"Value ="<<rev->second<<endl;
        //   }

          //emplace
          //this method is used to enter a key:value pair but note if your key is repeating i,e already present the original value will be retained and the new value will not be inserted
          babu.emplace(pair<int,char>(69,'A'));
                 babu.emplace(pair<int,char>(68,'B'));
                        babu.emplace(pair<int,char>(67,'A'));//note that key should be unique but value can be same for different keys
                               babu.emplace(pair<int,char>(69,'F'));
                                      babu.emplace(pair<int,char>(68,'U'));
                                             babu.emplace(pair<int,char>(67,'K'));
                                             map<int,char>::iterator itr;
                                             for(itr=babu.begin();itr!=babu.end();itr++)
                                             {
                                                 cout<<itr->first<<":"<<itr->second<<endl;
                                             }

//note the last three elements will not be inserted since the key is not unique for them
 
cout<<"Aukaat of this container is:"<<babu.max_size()<<endl;
auto it1=babu.upper_bound(5);//return the next key:value pair coressponding to next higher key
auto it2=babu.upper_bound(6);
cout<<"The upper bound of 5 is:"<<it1->first<<":"<<it1->second<<endl;
cout<<"The upper bound of 6 is:"<<it2->first<<":"<<it2->second<<endl;
auto it3=babu.lower_bound(5);
auto it4=babu.lower_bound(6);//return the next key:value pair coressponding to the preceeding key
cout<<"The lower bound of 5 is:"<<it3->first<<":"<<it3->second<<endl;
cout<<"The lower bound of 6 is:"<<it4->first<<":"<<it4->second<<endl;

//emplace_hint
//it takes an additional args of position where you want to insert the element
babu.emplace_hint(babu.find(6),78,'D');
for(auto wala=babu.begin();wala!=babu.end();wala++)
{
    cout<<wala->first<<":"<<wala->second<<endl;
}

//value_comp
//key_comp chutiya cheez hai
cout<<"The size of container is"<<babu.size()<<endl;
cout<<"The statement that the container is empty is:"<<babu.empty()<<endl;

    return 0;


}