#include<bits/stdc++.h>
using namespace std;

int totalFruits(int n, vector<int> &arr) {
        int left = 0 , right = 0;
        int maxi = 0;
        unordered_map<int,int> mp;
        while(right < n){
            mp[arr[right]]++;
            if(mp.size() > 2){
                while(left < n && mp.size() > 2){
                    mp[arr[left]]--;
                    if(mp[arr[left]] == 0) mp.erase(arr[left]);
                    left++;
                }
            }
            int len = 0;
            for(auto it : mp) len += it.second; 
            // cout<<left<<" "<<right<<" "<<len<<endl;
            maxi = max(maxi , len);
            right++;
        }
        return maxi;
}


int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i =0; i < n ; i++) cin>>arr[i];
    cout<<totalFruits(n , arr);

return 0;
}