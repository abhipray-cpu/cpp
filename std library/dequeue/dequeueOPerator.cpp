// // CPP program to illustrate 
// // Implementation of = operator 
// // = operator
// #include <deque> 
// #include <iostream> 
// using namespace std; 

// int main() 
// { 
// 	deque<int> mydeque1{ 1, 2, 3 }; 
// 	deque<int> mydeque2{ 3, 2, 1, 4 }; 
// 	mydeque1 = mydeque2; 
// 	cout << "mydeque1 = "; 
// 	for (auto it = mydeque1.begin(); it != mydeque1.end(); ++it) 
// 		cout << ' ' << *it; 
// 	return 0; 
// } 

//[] operator
// CPP program to illustrate 
// Implementation of [] operator 
// #include <deque> 
// #include <iostream> 
// using namespace std; 

// int main() 
// { 
// 	deque<int> mydeque; 
// 	mydeque.push_back(3); 
// 	mydeque.push_back(4); 
// 	mydeque.push_back(1); 
// 	mydeque.push_back(7); 
// 	mydeque.push_back(3); 
// 	cout << mydeque[3]; 
// 	return 0; 
// } 

#include <deque> 
#include <iostream> 
using namespace std; 
  
int main() 
{ 
    deque<int> mydeque; 
    mydeque.push_back(1); 
    mydeque.push_back(2); 
    mydeque.push_back(3); 
    mydeque.push_back(4); 
    mydeque.push_back(5); 
    mydeque.push_back(6); 
    mydeque.push_back(7); 
    mydeque.push_back(8); 
    mydeque.push_back(9); 
    mydeque.push_front(69);
    // Deque becomes 1, 2, 3, 4, 5, 6, 7, 8, 9 
  
    for (int i = 0; i < mydeque.size(); ++i) { 
        if (i % 2 == 0) { 
            cout << mydeque[i]; 
            cout << " "; ;
        } 
    } 
    for(int i=0;i<mydeque.size();i++)
    {
        cout<<mydeque[i]<<" ";
        cout<<endl;
    }
    return 0; 
} 