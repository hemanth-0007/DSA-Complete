#include<bits/stdc++.h>
using namespace std;

string inital_string(string s , int k){
    while(k--){
        // cout<<k<<endl;
        reverse(s.begin(), s.begin() + k + 1);
    }
    return s;
}


int main()
{
string s  = "chakerrank";
int k  = 3;
cout<<inital_string(s, k);

return 0;
}