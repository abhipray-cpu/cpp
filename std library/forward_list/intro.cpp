/*Forward list in STL implements singly linked list.
 Introduced from C++11, forward list are more useful
  than other containers in insertion, removal and moving 
  operations (like sort) and allows time constant insertion and removal of elements. 
It differs from list by the fact that forward list keeps
 track of location of only next element while list keeps
  track to both next and previous elements, thus increasing
   the storage space required to store each element. The drawback 
   of forward list is that it cannot be iterated backwards and 
   its individual elements cannot be accessed directly. 
Forward List is preferred over list when only forward traversal 
is required (same as singly linked list is preferred over doubly 
linked list) as we can save space. Some example cases are, chaining
 in hashing, adjacency list representation of graph, etc*/