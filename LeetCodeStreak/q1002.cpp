#include<bits/stdc++.h>
using namespace std;


vector<int> count(string s){
    int n = s.size();
    vector<int> ans(26, 0);
    for(auto ch : s) ans[ch - 'a']++;
    return ans;
}

vector<int> intersection(const vector<int>& a,const vector<int>& b){
    vector<int> ans(26, 0);
    for (int i = 0; i < 26; i++)
    {
        ans[i] = min(a[i], b[i]);
    }
    return ans;
}


vector<string> commonChars(vector<string>& words) {
    int n  = words.size();
    vector<int> last = count(words[0]);
    // cout<<"1"<<endl;
    for (int i = 1; i < n; i++)
    {
        // cout<<i<<endl;
        last = intersection(last, count(words[i]));
    }
    vector<string> ans;
    // cout<<"2"<<endl;
    for (int i = 0; i < 26; i++)
    {
        // cout<<last[i]<<endl;
        while (last[i] > 0)
        {
            ans.push_back(string(1, (i + 'a')));  
            last[i]--; 
        }
    }
    return ans;
}



int main()
{
    vector<string> words = {"bella","label","roller"};
    vector<string> ans = commonChars(words);
    for(auto s : ans) cout<<s<<endl;
return 0;
}