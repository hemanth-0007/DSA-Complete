// Strings atlassian question 

// while iterating a string if s[i] == s[i+1] != s[i+2]
// then modify s[i+2] == s[i] till there is non chance 
// return the maximum number of cases
// edge case aabba
//           0 2   --> we start at two and we find the maximum


#include<bits/stdc++.h>
using namespace std;

int getMaxCount(string& s){
    int n = s.size();
    string s2(s);
    
    return 0;
}




int main()
{
string s = "aabba";
cout<<getMaxCount(s);
return 0;
}