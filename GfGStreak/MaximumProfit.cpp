#include<bits/stdc++.h>
using namespace std;

long long maxTip(int n, int x, int y, vector<int> &arr, vector<int> &brr) {
    // value arr[i] - brr[i] arr[i] , brr[i]
    vector<pair<int, int>> diff;
    long long ans = 0;
    for(int i = 0; i < n ; i++)  diff.push_back({abs(arr[i] - brr[i]), i});
    sort(diff.rbegin(), diff.rend());
    
    for (int i = 0; i < n; i++)
    {
        int ind = diff[i].second;
        if((arr[ind] >=  brr[ind] && x > 0 ) || y <= 0){
            ans += arr[ind];
            x--;
        }
        else{
            ans += brr[ind];
            y--;
        }
    }
    return ans;
}



class Solution {
public:
    long long maxTip(int n, int x, int y, vector<int> &arr, vector<int> &brr) {
        vector<pair<int, int>> diffs(n);
        for (int i = 0; i < n; ++i) {
            diffs[i] = {abs(arr[i] - brr[i]), i};
        }
        
        sort(diffs.rbegin(), diffs.rend());
        
        long long totalTip = 0;
        int aOrders = 0, bOrders = 0;
        
        for (int i = 0; i < n; ++i) {
            int idx = diffs[i].second;
            if ((arr[idx] >= brr[idx] && aOrders < x) || bOrders >= y) {
                totalTip += arr[idx];
                ++aOrders;
            } else {
                totalTip += brr[idx];
                ++bOrders;
            }
        }
        
        return totalTip;
    }
};

int main()
{

return 0;
}