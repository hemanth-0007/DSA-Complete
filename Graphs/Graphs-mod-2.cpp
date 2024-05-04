#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;

/*
  Implementing graphs using the
  adjacency matrix 

*/
 

int main()
{
    int v,e;
    cin>>v;
    int adjMtrx[v][v];

for (int i = 0; i < v; i++)
{
    for (int j = 0; j < v; j++)
    {
        cin>>adjMtrx[i][j];
    }
    
}

// Here it just prints the adjacency list from a 
// adjacency matrix 
for (int i = 0; i < v; i++)
{
     cout<<i<<" ";
        for (int j = 0; j < v; j++)
        {
            if(adjMtrx[i][j] == 1)
            cout<<j<<" ";
        }
    cout<<endl;
}


return 0;
}