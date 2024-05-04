#include<bits/stdc++.h>
using namespace std;

bool isThereExistJ(string s , string b, int i, int k){

    for (int j = 0; j <= s.size() - b.size(); j++)
        if(s.substr(j,b.size()) == b && abs(j-i) <= k) return true;
    
    return false;
    
}




vector<int> beautifulIndices(string s, string a, string b, int k) {
        int n = s.size();
        vector<int> beautyIndex;
        for (int i = 0; i <= n - a.size(); i++)
        {
            if(a != s.substr(i, a.size())) continue;
            if(isThereExistJ(s,b,i,k)) beautyIndex.push_back(i);
        }
        sort(beautyIndex.begin(), beautyIndex.end());
        return beautyIndex;
        
}

int main()
{
    string s = "isawsquirrelnearmysquirrelhouseohmy";
    string a = "my";
    string b = "squirrel";
    int k = 15;
    vector<int> res = beautifulIndices(s,a,b,k);
    for(auto num : res) cout<<num<<" ";

return 0;
}