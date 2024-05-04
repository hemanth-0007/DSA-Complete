//maximun sum of the non-adjacent elemnts from  a
// subsequence in an array 
#include<bits/stdc++.h>
using namespace std;
int maxAdjSum(int ind , vector<int> a){
    //base cases 
    if(ind == 0){
        return a[0];
    }
    // for out off bound return 0
    if(ind < 0){
        return 0;
    }

    int pick = a[ind] + maxAdjSum(ind -2 , a);
    int notPick = 0 + maxAdjSum(ind -1, a);

    return max(pick , notPick);

}
int main()
{
vector<int> a = {2,1,4, 9};
int n = a.size();
cout<<maxAdjSum(n-1 , a);
return 0;
}