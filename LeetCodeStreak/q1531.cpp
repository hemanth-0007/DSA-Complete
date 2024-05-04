#include<bits/stdc++.h>
using namespace std;

int getLengthOfOptimalCompression(string s, int k) {
       int n = s.size();
       map<char, int> mp;
       for (int i = 0; i < n; i++) mp[s[i]]++;
       for(auto it : mp) cout<<it.first<<" "<<it.second<<endl;
       return helper(n-1, k, s, mp);
       return 0; 
}




int main()
{
    string s = "baaacccd";
    int k = 2;
    cout<<getLengthOfOptimalCompression(s, k);

return 0;
}