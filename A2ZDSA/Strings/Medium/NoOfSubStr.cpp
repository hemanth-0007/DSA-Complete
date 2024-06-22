#include<bits/stdc++.h>
using namespace std;

long long int helper(string s, int k) {
    int n = s.size();
    unordered_map<char , int> mp;
    long long int cnt =0;
    int i = 0, j = 0;
    // i is the front pointer and j is the back pointer
    while(i<n && j<n && j <= i){
       mp[s[i]]++;
       while( j < n && j <= i && mp.size() > k){
            mp[s[j]]--;
            if(mp[s[j]] == 0) mp.erase(s[j]);
            j++;
       }
       if(mp.size() == k) cnt += (i - j + 1);
       i++;
    }
    return cnt;
}

long long int substrCount (string s, int k) {
    return helper(s, k) - helper(s, k-1);
}




long long int solve(string s, int k) {
        // using sliding window find total subarray having at most k distinct characters
        long long int ret = 0;
        int l = 0, r = 0, n = s.size();
        vector<int> f(26, 0);
        int distinct = 0;
        // using shrinkable window
        for(r; r < n; r++) {
            distinct += f[s[r] - 'a']++ == 0;
            while(distinct > k) {
                distinct -= f[s[l++] - 'a']-- == 1;
            }
            ret += (r - l + 1);
        }
        return ret;
    }
 
    long long int substrCount (string s, int k) {
        // subarray having k distinct characters = subarray having at most k distinct char - subarray having at most (k - 1) distinct characters
        return solve(s, k) - solve(s, k - 1);
    }

int main()
{
    string s = "abaaca";
    int k = 1;
    // string s = "aba";
    // int k = 2;
    cout<<substrCount(s, k);
return 0;
}