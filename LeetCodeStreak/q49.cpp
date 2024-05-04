#include<bits/stdc++.h>
using namespace std;

bool isAnagram(string s , string t, map<char, int> mp){
     for(auto ch : t)mp[ch]--;
     for(auto it : mp){
        if(it.second != 0) return false;
     }
     return true;
}
// WRITE FIND MAX CODE
// 1. Brute Force


vector<vector<string>> groupAnagrams(vector<string>& strs) {
    int n = strs.size();
    vector<bool>visited(n , false);
    vector<vector<string>> result;
    for (int i = 0; i < n; i++)
    {
        if(visited[i]) continue;
        // O(N)
        vector<string> temp;
        map<char ,int> mp;
        // O(N^2)
        for(auto ch : strs[i]) mp[ch]++;
        temp.push_back(strs[i]);
        visited[i] =  true;
        for(int j = i+1 ; j < n; j++){
            if(visited[j]) continue;
            if(isAnagram(strs[i], strs[j],mp)){
                visited[j] = true;
                temp.push_back(strs[j]);
            }
        }
        result.push_back(temp);
        }
    return result;
}


vector<vector<string>> groupAnagramsMethod2(vector<string>& strs) {
    int n = strs.size();
    unordered_map<string, vector<string>> group;
    vector<vector<string>> result;
    for (int i = 0; i < n; i++)
    {
        string temp = strs[i];
        sort(temp.begin(), temp.end());
        group[temp].push_back(strs[i]);
    }

    for(auto it : group) result.push_back(it.second);
    return result;
}

vector<vector<string>> groupAnagramsOptimized(vector<string>& strs) {
    int n = strs.size();
    vector<vector<string>> result;
    unordered_map<string, int> group_ind;
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        string temp = strs[i];
        sort(temp.begin(), temp.end());
        if(group_ind.find(temp) != group_ind.end()){
            result[group_ind[temp]].push_back(strs[i]);
        }
        else{
            group_ind[temp] = k;
            result.push_back({strs[i]});
            k++;
        }
    }
    
    return result;
}




 
int main()
{
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    // vector<vector<string>> result = groupAnagrams(strs);
    // vector<vector<string>> result = groupAnagramsOptimized(strs);
    vector<vector<string>> result = groupAnagramsMethod2(strs);
    for(auto v : result){
        for(auto st : v) cout<<st<<" ";
        cout<<endl;
    }

return 0;
}