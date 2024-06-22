#include <bits/stdc++.h>
using namespace std;

int longestSubstrLen(string s)
{
    int n = s.size();
    if(n == 0) return 0;
    int i = 0, j = 0;
    int maxLen = 1;
    unordered_set<char> st;
    while (i <= j && j < n && i < n)
    {
        if(st.find(s[j]) != st.end()){
            while(i < n && i < j && st.find(s[j]) != st.end() ){
                 st.erase(s[i]);
                 i++;
            }
        }
        int len = j - i + 1;
        // cout << i << " " << j << " " << len << endl;
        maxLen = max(maxLen, len);
        st.insert(s[j]);
        j++;
    }
    return maxLen;
}

string longestSubstr(string s)
{
    int n = s.size();
    if(n == 0) return "";
    int i = 0, j = 0;
    int maxLen = 1;
    string ans = "";
    unordered_set<char> st;
    while (i <= j && j < n && i < n)
    {
        if(st.find(s[j]) != st.end()){
            while(i < n && i < j && st.find(s[j]) != st.end() ){
                 st.erase(s[i]);
                 i++;
            }
        }
        int len = j - i + 1;
        // cout << i << " " << j << " " << len << endl;
        if(len >= maxLen){
            ans = s.substr(i , len);
            maxLen = len;
        }
        st.insert(s[j]);
        j++;
    }
    return ans;
}



int longestSubstrLenOp(string s)
{
    int n = s.size();
    int left = 0, right = 0;
    int maxLen = 0;
    vector<int> mp(256, -1);
    while (left <= right && right < n && left < n)
    {
        if(mp[s[right]] != -1) 
            left = max(mp[s[right]] + 1, left); // this is the correct becoz left may move left side which is a voilation
            // left = mp[s[right]] +1;
        
        mp[s[right]] = right;
        int len = right - left + 1;
        cout << left << " " << right << " " << len << endl;
        maxLen = max(maxLen, len);
        right++;
    }
    return maxLen;
}

int main()
{
    string s;
    // cout << "Hello" << endl;
    cin >> s;
    // cout << s << endl;
    cout << longestSubstrLen(s)<<endl;
    cout << longestSubstrLenOp(s)<<endl;
    cout << longestSubstr(s)<<endl;
    return 0;
}