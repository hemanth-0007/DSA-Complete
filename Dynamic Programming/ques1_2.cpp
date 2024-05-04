// if the steps are of k steps atmost ?
// simple recursion code
#include<bits/stdc++.h>
using namespace std;
 
 int sumOfSteps(int ind, int k ){
    if(ind  == 0 ){
        return 1;
    }
    int sum = 0 ;
    for (int j = 1; j <= k; j++)
    {
        if((ind - j ) >= 0){
            sum += sumOfSteps(ind -j , k );
        }
    }
   return sum;
 }


int main()
{
 int n = 4, k = 3;
 cout<<sumOfSteps(n-1, k );



return 0;
}