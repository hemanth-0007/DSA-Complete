// subsequence of the array 
#include<bits/stdc++.h>
using namespace std;

 
void print(vector<int>  vec){
    
    for(auto num : vec){
        cout<<num<<" ";
    }
    cout<<endl;
}

void printSub(vector<int> v , int n , 
int ind, vector<int> &res )
{
    // My Base Condition
    if(ind >= n){ 
        print(res);
        return;
    }
    
    res.push_back(v[ind]);
    printSub(v, n, ind +1, res );// pick 
    res.pop_back();
    printSub(v,n , ind+1 , res );// not pick
}
// 7 8 9 --> array
// 0 1 2 --> index

// _ _ _
// {}
// 8 9 
// 7 8
// 7 9
//7 8 9 
// 7 
// 8
// 9

// the subsequence is 
// 1. dont alter the sequence of the array 
// --> 2^n
// sum == 3 
//{}
//1
//2
//3
//2 1
//3 1
//3 2
//3 2 1




int main()
{
    vector<int> v = {7,8,9};
    vector<int> vec;
 
    printSub(v,3, 0 , vec );

return 0;
}