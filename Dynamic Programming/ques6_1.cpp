// Counting the number of ways to reach a bottom right point from top left 
// suppose we have an n * m array
#include<bits/stdc++.h>
using namespace std;

int noOfWays(int i , int j ){
    if(i ==0 && j ==0 ) return 1;
    if( i < 0 || j < 0) return 0;

    int upStep = noOfWays( i  , j-1 );
    int leftStep = noOfWays( i-1 , j );

    return upStep + leftStep;
}



int main()
{
int n = 3;
int m = 3;

cout<<noOfWays( n-1, m-1);
return 0;
}
 