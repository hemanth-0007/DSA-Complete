// Finding the two non repeating numbers in the array of evenly repeating numbers
//using maps
#include<bits/stdc++.h>
using namespace std;

 


int main()
{
int arr[] ={2,3,1,1,5,5,6,6};
int n = sizeof(arr)/sizeof(int);
 
unordered_map<int , int > mp;

for (int i = 0; i < n; i++)
    mp[arr[i]]++; 


for(auto itr : mp){
    if(itr.second == 1){
        cout<<itr.first<<" ";
    }
}

return 0;
}