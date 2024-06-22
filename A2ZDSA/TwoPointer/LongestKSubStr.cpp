#include<bits/stdc++.h>
using namespace std;
int longestKSubstr(string s, int k) {
    int n = s.size();
    int left = 0, right = 0, maxLen = 0;
    // here instead of an unordered map a vector<int> mp(26, 0) can be used for maintaining the frequncies
    unordered_map<char, int> mp;
    while(right < n){
        mp[s[right]]++;        
        if(mp.size() > k){
            while(left < n && mp.size() > k){
                mp[s[left]]--;
                if(mp[s[left]] == 0) mp.erase(s[left]);
                left++;
            }
        }
        if(mp.size() == k) maxLen = max(maxLen, (right - left + 1));
        right++;    
    }
    return maxLen;
}

int main()
{
    string s;
    cin>>s;
    int k;
    cin>>k;
    cout<<longestKSubstr(s, k);

return 0;
}