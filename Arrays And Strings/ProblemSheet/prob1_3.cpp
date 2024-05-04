// Finding the two non repeating numbers in the array of evenly repeating numbers
//using sets
#include<bits/stdc++.h>
using namespace std;

 


int main()
{
int arr[] ={2,3,1,1,5,5,6,6};
int n = sizeof(arr)/sizeof(int);
 
set<int> s;

 for (int i = 0; i < n; i++)
 {
    auto itr = s.find(arr[i]);

    if(itr != s.end()){
        s.erase(itr);
    }
    else{
        s.insert(arr[i]);
    }
 }
 
 for(auto it : s){
    cout<<it<<" ";
 }
 

return 0;
}