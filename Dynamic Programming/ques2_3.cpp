// converting the ques 2 into dp such that there would be no 
// recomputing of the overlapping subproblems
// Memoization techniques 
 

#include<bits/stdc++.h>
using namespace std;

 // time complex O(N) * K 
 // space complexity O(N)--> array of dp 
 // cant optimised more than this

int minEnergy(vector<int> energy ,int ind, int k, vector<int> &dp){
        if(ind == 0){
            return dp[0] = 0;
        }
        int minStep = INT_MAX;
        for (int j = 1; j <= k; j++)
        {
            if((ind - j) >= 0){
                int step = minEnergy(energy ,ind-j, k, dp) + abs(energy[ind] - energy[ind-j]);
                minStep = min(step , minStep);
            }
            
        }
 
        return dp[ind] = minStep;

}


int main()
{
int n = 4;
int k = 2;
vector<int> energy = {10, 20 , 10, 40};
//using this array to stored the computed things 
vector<int> dp(n,-1);

cout<<minEnergy(energy , n-1, k, dp)<<endl;
return 0;
}