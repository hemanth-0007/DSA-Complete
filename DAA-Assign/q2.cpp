#include<bits/stdc++.h>
using namespace std;


int helper(int i , int j, bool myTurn, vector<int>& nums){
    if(i > j) return 0;
    if(i == j){
        if(myTurn) return nums[i];
        else return 0;
    }

    int takeFirst = 0, takeLast = 0;
    if(myTurn){
        cout<<"executing my turn "<<i <<" "<<j<<endl;
        takeFirst = nums[i] + helper(i+1, j , !myTurn, nums);
        takeLast = nums[j] + helper(i , j-1, !myTurn, nums);
    }
    else{
        cout<<"not my turn "<<i<<" "<<j<<endl;
        takeFirst = helper(i+1, j , !myTurn, nums);
        takeLast = helper(i, j-1, !myTurn, nums);
    }
    return max(takeFirst, takeLast);
}


int maxFirstTurn(vector<int> & nums){
    int n = nums.size();
    return helper(0, n-1, true,nums );
}




int main()
{
    vector<int> nums = {2,3,8,5};
    cout<<maxFirstTurn(nums)<<endl;

return 0;
}