//creating a min heap using priority queue
// #include<iostream>
// #include<queue>

// using namespace std;

// class MinHeap
// {
//     public:
//     priority_queue<int,vector<int>,greater<int>> gq;
//     void display();
// };

// void MinHeap::display()
// {
//      priority_queue<int> temp=gq;
//      while (!temp.empty())
//      {
//          cout<<temp.top()<<" ";
//          temp.pop();
//      }
// cout<<endl;
// }

// int main()
// {
//     MinHeap Hp;
//     for(int i=0;i<100000;i++)
//     {
//         Hp.gq.push(rand());
//     }

//     cout<<"The priority queue is:"<<endl;

//     Hp.display();
//     return 0;
// }


//max heap

// #include<iostream>
// #include<queue>

// using namespace std;

// class MinHeap
// {
//     public:
//     priority_queue<int> gq;
//     void display();
// };

// void MinHeap::display()
// {
//      priority_queue<int> temp=gq;
//      while (!temp.empty())
//      {
//          cout<<temp.top()<<" ";
//          temp.pop();
//      }
// cout<<endl;
// }

// int main()
// {
//     MinHeap Hp;
//     for(int i=0;i<100000;i++)
//     {
//         Hp.gq.push(rand());
//     }

//     //cout<<"The priority queue is:"<<endl;
//    //Hp.display();
     
//      for(int i=0;i<23;i++)
//      {
//          cout<<endl;
//      }
//      cout<<"The size of list is"<<Hp.gq.size()<<endl;
//     return 0;
// }

//similarly sorting a string text

#include<iostream>
#include<queue>
#include<bits/stdc++.h>

using namespace std;

class sorter
{
    public:
    priority_queue<char,vector<char>,greater<char>>CH;
    void show();
};

void sorter::show()
{ priority_queue<char,vector<char>,greater<char>>CH1=CH;
    while(!CH1.empty())
    {
        cout<<CH1.top()<<" -->";
        CH1.pop();
    }
    cout<<endl;
}



int main()
{
    sorter S;
    string str="Humara professor kaisa ho bahubali jaisa ho";
    for(int i=0;i<str.length();i++)
    {
        S.CH.push(str[i]);
    }
     S.show();


     return 0;
}
