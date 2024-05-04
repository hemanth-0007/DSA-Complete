// Robber problem similar to last porb but
// first n last index are of adjacent ones
#include<bits/stdc++.h>
using namespace std;
 
int maxAdjSum(int ind ,int endInd, vector<int> a){
    //base cases 
    if(ind == endInd){
        return a[0];
    }
    // for out off bound return 0
    if(ind < endInd){
        return 0;
    }

    int pick = a[ind] + maxAdjSum(ind -2 ,endInd, a);
    int notPick = 0 + maxAdjSum(ind -1,endInd, a);

    return max(pick , notPick);

}


int main()
{
vector<int> a = {2, 3,6,9, 2};
int n = a.size();
 cout<<max(maxAdjSum(n-2,0, a), maxAdjSum(n-1 , 1 , a));
 
 
return 0;
}