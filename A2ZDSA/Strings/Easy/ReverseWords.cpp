#include <bits/stdc++.h>
using namespace std;
string reverseWords(string s)
{
    int n = s.size();
    int i = n-1;
    string ans = "";
    while (i >= 0)
    {
        string temp = "";
        while( i >= 0 && s[i] == ' ') i--;
        while(i >= 0 && s[i] != ' '){
            temp += s[i];
            i--;
        }
        reverse(temp.begin(), temp.end());
        // cout<<(temp + " ")<<" "<<temp.size()<<endl;
        if(temp != "") ans += (temp + " ");
    }
    ans.pop_back();
    // cout<<ans.size()<<endl;
    return ans;
}
int main()
{
    string s = "  hello world  ";
    cout<< reverseWords(s)<<endl;

    return 0;
}