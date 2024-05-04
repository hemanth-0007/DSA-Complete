#include<bits/stdc++.h>
using namespace std;

#include <algorithm>

int maximumLength(string s) {
    int n = s.size();
    map<string, int> mp;
    for(int i = 0 ; i < n ; i++){
        for(int j = i ; j < n ; j++){
            mp[s.substr(i, j-i+1)]++;
        }
    }
    int max_len = -1;
    for(auto it : mp){
        // cout<<it.first<<" "<<it.second<<endl;
        if(it.second >= 3){
            string myString;
            myString.append(it.first.size(), it.first[0]);
            if(myString == it.first)
                max_len = max(max_len, (int)myString.size());
        }
    }
    return max_len;
}


int main()
{
    // string s = "fafff";
    // string s = "aaaa";
    string s = "cccerrrecdcdccedecdcccddeeeddcdcddedccdceeedccecde";
    cout<<maximumLength(s)<<endl;

return 0;
}