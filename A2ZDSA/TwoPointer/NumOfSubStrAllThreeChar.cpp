#include<bits/stdc++.h>
using namespace std;
int numberOfSubstrings(string s) {
    int n = s.size();
    //int left = 0, right = 0;
    int cnt =0;
    int a = -1, b = -1, c = -1;
    for (int i = 0; i < n; i++)
    {
        if(s[i] == 'a') a = i;
        if(s[i] == 'b') b = i;
        if(s[i] == 'c') c = i;
        if(a != -1 && b != -1 && c != -1)
            cnt += (min(a, min(b,c)) + 1);
    }
    return cnt;
    
}
int main()
{
    string s;
    cin>>s;
    cout<<numberOfSubstrings(s);
    

return 0;
}