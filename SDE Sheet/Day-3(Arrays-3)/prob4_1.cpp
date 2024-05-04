//  printing the triplets with sum equals to 0. 
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
// will cost time complexity == O(2^n)*n approximately
void printSub(vector<int> v , int n , 
int ind, vector<int> &res, int k)
{
    if(ind >= n){ 
     if (sum(res) == 0){
        int n = res.size();
        if(n == 3){
            print(res);
            return;
        }
        return;
     }
        
        return;
    }
    res.push_back(v[ind]);
    printSub(v, n, ind +1, res, k);
    res.pop_back();
    printSub(v,n , ind+1 , res, k);
}
 
int main()
{
    vector<int> v =  {-1,0,1,2,-1,-4};
    vector<int> vec;
    printSub(v,v.size(), 0 , vec,8);

return 0;
}