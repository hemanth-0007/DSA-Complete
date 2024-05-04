//  subsequence of the array 
#include<bits/stdc++.h>
using namespace std;


int sum(vector<int>  vec){
    int sm = 0;
    for(auto num : vec){
        sm += num;
    }
    return sm;
}
void print(vector<int>  vec){
    
    for(auto num : vec){
        cout<<num<<" ";
    }
    cout<<endl;
}

void printSub(vector<int> v , int n , 
int ind, vector<int> &res, int k)
{
    if(ind >= n){ 
     if (sum(res) == k)
        print(res);
        return;
    }
    res.push_back(v[ind]);
    printSub(v, n, ind +1, res, k);
    res.pop_back();
    printSub(v,n , ind+1 , res, k);
}
 
int main()
{
    vector<int> v = {7,8,9};
    vector<int> vec;
 
    printSub(v,3, 0 , vec,8);

return 0;
}