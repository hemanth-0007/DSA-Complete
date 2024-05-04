#include<bits/stdc++.h>
using namespace std;

string minRemoveToMakeValid(string s) {
    int n = s.size();
    stack<pair<char, int>> st;
    vector<pair<char, int>> vec;
    for (int i = 0; i < n; i++)
    {
        if(s[i] == ')' || s[i] == '(')
            vec.push_back(make_pair(s[i], i));
    }
    for (int i = 0; i < vec.size(); i++)
    {
        if(vec[i].first == '('){
            st.push({vec[i].first, vec[i].second});
        }
        else{
            if(!st.empty()){

            }
            else{
                vec[i] = make_pair('0', vec[i].second);
                
            }

        }
    }
        

}
int main()
{
    string s = "lee(t(c)o)de)";
    // ans : "lee(t(c)o)de"
    string s = "a)b(c)d";
    string s = "))((";


return 0;
}