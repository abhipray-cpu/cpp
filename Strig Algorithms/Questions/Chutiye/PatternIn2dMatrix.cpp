//copy mei code likha hai dekhlena mei nhi kar rha yei faltu ka chutiya hai
//and we can use map<pair<row,col>,bool> to keep record whether the
//cell was visited or not

#include<bits/stdc++.h>
using namespace std;
#define MAX 5
class PatternMatch
{
    public:
    string pattern;
    char Mat [MAX][MAX]; //this is the 2d matrix which we are going to use
    map<pair<int,int>,char>Track;//this is the map which will keep track of the visited cells
    map<char,pair<int,int>>Store; //this will keep the record of the pattern visited so for
    void initializeMat();//this function will initialize the 2d array
    void search(string pattern,int counter,int row,int col); //this will
    void searchUtil(string pattern,int counter,int row,int col);//this is the search util function
    void displayMat();//this will display the matrix
    void showDetails();//this function will be fired only when the pattern is found in the string
};

void PatternMatch::initializeMat()
{
    for(int i=0;i<MAX;i++)
    {
        for(int j=0;j<MAX;j++)
        {
            Mat[i][j]='a'+rand() % 26;
            Track[make_pair(i,j)]=false;
        }
    }
}
void PatternMatch::displayMat()
{
    for(int i=0;i<MAX;i++)
    {
        for(int j=0;j<MAX;j++)
        {
            cout<<Mat[i][j]<<"\t";
        }
        cout<<endl;
}
}
void PatternMatch::search(string pattern,int counter,int row,int col)
{
    char ch=pattern[counter];
   if(counter == pattern.size()-1)
   {
       cout<<"The pattern is found in the grid here are the details \n";
       showDetails();
   }
    else
    {
        if(Mat[row][col]==ch && Track[make_pair(row,col)]==false)
    {
        Track[make_pair(row,col)]=false;
        Store[ch]=make_pair(row,col);
        searchUtil(pattern,counter+1,row,col);
    }
    else if(Mat[row][col]==ch && Track[make_pair(row,col)]==true)
    {
        cout<<"The pattern is not present in the grid since an already visted node is visited \n";
    }
    else
    {  
        searchUtil(pattern,counter,row,col);
    }
    }
}
void PatternMatch::searchUtil(string pattern,int counter,int row,int col)
{
    if(row == MAX-1 && col != MAX-1)
    {
        search(pattern,counter,0,col+1);
    }
    else if(row == MAX-1 && col == MAX-1)
    {
        search(pattern,counter,0,0);
    }
    else
    {
        search(pattern,counter,row+1,col);
    }
}
void PatternMatch::showDetails()
{
    cout<<"Character \t Row \t Column"<<endl;
    for(int i=0;i<pattern.size();i++)
    {
        cout<<pattern[i]<<"\t \t \t "<<Store[pattern[i]].first<<"\t \t "<<Store[pattern[i]].second<<endl;
    }
}
int main()
{
    PatternMatch obj;
    obj.pattern="MICROSOFT";
    obj.initializeMat();
    obj.displayMat();
    cout<<"Updating the pattern to contain MICROSOFT..."<<endl;
    obj.Mat[3][3]='M';
    obj.Mat[4][3]='I';
    obj.Mat[1][4]='C';
    obj.Mat[0][3]='R';
    obj.Mat[2][1]='O';
    obj.Mat[1][1]='S';
    obj.Mat[1][2]='O';
    obj.Mat[3][2]='F';
    obj.Mat[4][4]='T';
    obj.displayMat();
    cout<<"Searching for MICROSOFT in this grid ... \n";
    obj.search("MICROSOFT",0,0,0);
    return 0;
}