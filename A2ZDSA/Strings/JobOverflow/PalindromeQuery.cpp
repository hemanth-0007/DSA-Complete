#include<bits/stdc++.h>
using namespace std;

int getLongestOddPalindrome(string s,int ind){
    int len = 1, i = 1;
    int n = s.size();
    while((ind - i) >= 0 && (ind + i) < n && s[ind - i] == s[ind + i] ){
        len += 2;
        i++;
    }
    // cout<<"ind is "<<ind<<i<<" "<<len<<endl;
    return len == 1 ? 0 : len;
}

vector<int> palindrome_query(string s, vector<int> queries){
    int n = s.size();
    vector<int> ans;
    for (int i = 0; i < queries.size(); i++)
    {   
        int ind = queries[i]-1;
        ans.push_back(getLongestOddPalindrome(s, ind));
    }
    return ans;
}



int main()
{
    string s;
    cin>>s;
    int q;
    cin>>q;
    vector<int> queries(q);
    for (int i = 0; i < q; i++) cin>>queries[i];
    vector<int> res = palindrome_query(s, queries);
    for(auto num : res) cout<<num<<" ";
return 0;
}