#include<bits/stdc++.h>
using namespace std;


bool rotateString(string s, string goal) {
    int n = s.size(), m = goal.size();
    if(n != m ) return false;
    s += s;
    if(s.find(goal) < s.size()) return true;
    return false;       
}

int main()
{
    string s = "abcde";
    string goal = "cdeab";
    cout<<rotateString(s, goal)<<endl;
return 0;
}