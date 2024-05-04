#include<bits/stdc++.h>
using namespace std;

int helper(int ind, vector<int>& v, int n, int key){
    if(ind == n) return -1;
    if(v[ind] == key) return ind;
    return helper(ind+1, v, n, key);
}





int linear_search(vector<int>& v, int key)
{
   int n = v.size();
   return helper(0, v, n, key);
}



int main()
{
    vector<int> v = {1,2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout<<linear_search(v, 5);

return 0;
}