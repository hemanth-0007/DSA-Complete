#include <bits/stdc++.h>
using namespace std;


bool comparator(string s1 , string s2){
    return s1.size() > s2.size();
}

int getSubset(vector<string> &strs)
{
    int n = strs.size();
    sort(strs.begin(), strs.end(), comparator);
    // for (auto s : strs)
    //     cout << s << endl;
    vector<string> res;
    for (int i = 0; i < n; i++)
    {
        bool isSubStr = false;
        for(auto s : res){
            if(s.find(strs[i]) != string::npos) {
                isSubStr = true;
                break;
            }
        }
        if(!isSubStr) res.push_back(strs[i]);
    }
    
    return res.size();
}

int main()
{
    vector<string> strs = {"b",
                           "aab",
                           "ab",
                           "aabab",
                           "ababa"};
                           cout<<getSubset(strs);

    return 0;
}