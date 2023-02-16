// we use floyd warshall algorithm to find the shortest path of all the pairs
/*
This alogorithm is used for calculating all pair shortest path
we will be using a nXn matrice to strore the distances
A adjacency matrice is a better repersentation in this case
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int matrix[5][5];

// we are taking example for a non weighted graph
void adjacency_matrix()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            matrix[i][j] = 0;
        }
    }
}

void display_matrix()
{
    cout << "These is your initialzed matrix \n";
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

void generate_short_pairs()
{
    for (int k = 0; k < 5; k++)
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (matrix[i][k] + matrix[k][j] < matrix[i][j])
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
            }
        }
    }
}

int main()
{
    adjacency_matrix();
    matrix[0][2] = 3;
    matrix[0][3] = 7;
    matrix[0][4] = 2;
    matrix[0][1] = 5;
    matrix[1][2] = 3;
    matrix[1][3] = 7;
    matrix[1][4] = 2;
    matrix[1][0] = 5;
    matrix[2][0] = 3;
    matrix[2][3] = 7;
    matrix[2][4] = 2;
    matrix[2][1] = 5;
    matrix[3][2] = 3;
    matrix[3][0] = 7;
    matrix[3][4] = 2;
    matrix[3][1] = 5;
    matrix[4][2] = 3;
    matrix[4][3] = 7;
    matrix[4][0] = 2;
    matrix[4][1] = 5;

    cout << "This is the original adjacency matrix \n";
    display_matrix();
    cout << "This is the adjacency matrix with the shortest pair distance \n";
    generate_short_pairs();
    display_matrix();

    return 0;
}
