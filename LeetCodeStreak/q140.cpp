#include <bits/stdc++.h>
using namespace std;

void helper(int ind ,const string& s,const unordered_set<string>& st, vector<string>& ans, string& ds){
    if(ind == s.size()){
        ans.push_back(ds);
        return;
    }
    // code
    
    for (int i = ind; i < s.size(); i++)
    {
        string temp = s.substr(ind , i - ind + 1);
        if(st.find(temp) != st.end()){
           if(i != s.size() -1) temp += " ";
            ds += temp;
            helper(i+1,s, st, ans, ds);
            for(auto i : temp) ds.pop_back();
        }
    }
    
}




vector<string> wordBreak(string s, vector<string> &wordDict)
{
    
    unordered_set<string> st(wordDict.begin(), wordDict.end());
    vector<string> ans;
    string ds;
    helper(0,s, st, ans, ds);
    sort (ans.begin(), ans.end(), greater<string>());
    return ans;
}
int main()
{
    string s = "catsanddog";
    vector<string> wordDict = {"cat","cats","and","sand","dog"};
    vector<string> ans  =  wordBreak(s, wordDict);
    for(auto st : ans) cout<<st<<endl;
    return 0;
}