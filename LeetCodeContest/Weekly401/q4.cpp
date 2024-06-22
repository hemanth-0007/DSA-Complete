#include<bits/stdc++.h>
using namespace std;




int maxTotalReward(vector<int>& arr) {
    int n = arr.size();       
    sort(arr.begin(), arr.end());
    // mask is to mask the sums only below the cur number (given condition)
    // dp keeps track of the sums till the index i 
    // validSum represents the set of sums that are valid for the cur number
    bitset<100001> mask, dp, validSum;

    int maskId = 0;
    dp[0] = 1;
    for(auto val : arr){
        while(maskId < val) mask[maskId++] = 1;
        validSum = (dp & mask);
        dp |= (validSum << val);
    }

    int res = 1e5;
    while(!dp[res]) res--;
    return res;
}



int main()
{
    bitset<8> mask;
    cout<<mask[0]<<" "<<mask[1]<<" "<<mask[2]<<endl;
    int maskId = 0;
    while(maskId < 2) mask[maskId++] = 1;
    cout<<mask<<endl;
return 0;
}