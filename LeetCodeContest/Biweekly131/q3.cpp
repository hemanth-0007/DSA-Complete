#include<bits/stdc++.h>
using namespace std;

vector<int> queryResults(int limit, vector<vector<int>>& queries) {
    int n = queries.size();
    vector<int> ans;
    // node , color it painted
    unordered_map<int, int> mp;
    unordered_map<int, int> mc;
    for (int i = 0; i < n; i++)
    {
        int node = queries[i][0];
        int color = queries[i][1];
        if(mp.find(node) != mp.end()){
            if(mc[mp[node]] != color){
                if(mc[mp[color]] == 1 ) mc.erase(mp[color]);
                else mc[color]--;
            }
            else mc[color]--;
        }
        mp[node] = color;
        mc[color]++;
        ans.push_back(mc.size());
    }
    return ans;
}


int main()
{

return 0;
}