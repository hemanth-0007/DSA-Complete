// Wild Card MAtching Prob
// write a bool fucntion that match from s1 to s2 
// in s1 '?' represents a single char and '*'represents a 0 or mutiple chars 
#include<bits/stdc++.h>
using namespace std;

bool isMatch(int i , int j, string s, string t){

// base cases --> think of the exhausting cases that are 4 cases of strings get exhausted
    if( i < 0 && j >= 0) return false;
    if(i<0 && j<0) return true;
    if(i>=0 && j<0){
       for (int ind = 0; ind <= i; ind++)
            if(s[ind] != '*') return false;
        return true;
    }

    if( (s[i] == t[j]) ||( s[i] = '?'))
        return isMatch(i-1,j-1,s,t);
    
    if(s[i] == '*')
        return (isMatch(i-1,j, s, t) || isMatch(i, j-1,s, t));
    
    return false;
}






int main()
{
    string s = "?ass" , t = "ass";
    int n = s.size(), m = t.size();
    cout<<isMatch(n-1,m-1,s,t);
return 0;
}