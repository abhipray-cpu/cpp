#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *link;
};
class stack
{
    private:
    Node *top;
    public:
    stack()
    {
        top=NULL;
    }
    void push(int data)
    {
        Node *newNode = new Node;
        newNode->data=data;
        newNode->link=top;
        top=newNode;
    }
    void pop()
    {
        if(top == NULL)
        cout<<"Stack Underflow"<<endl;
        else
        {
            Node *temp=top;
            top=top->link;
            delete(temp);
        }
        
    }
    void show()
    {
        Node *temp=top;
        while (temp != NULL)
        {
            cout<<temp->data<<endl;
            temp=temp->link;

        }
        cout<<endl;
    }
    bool is_empty()
    {
       if(top == NULL)
       return true;
       else
       {
           false;
       }
        
    }
    int get_top()
    {
        return top->data;
    }
    int getsize()
    {
        int counter=0;
        Node *temp=top;
        while (temp != NULL)
        {
          ++counter;
          temp=temp->link;
        }
        return counter;
    }

};

int main()
{
    stack s1;
    stack s2;
    for(int i=0;i<1000;i++)
    {
        s1.push(i);
    }
    for(int i=1001;i<=2000;i++)
    {
        s2.push(i);
    }
    cout<<"This is the first lits"<<endl;
    s1.show();
    cout<<endl;
    cout<<"This is the second list"<<endl;
    s2.show();
    cout<<endl;
    cout<<"The size of second list is = "<<s2.getsize()<<endl;
    cout<<"The size of first list is = "<<s1.getsize()<<endl;
}