#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str;
    string rev = "";
    cout<<"enter string";
    cin>>str;
    string::reverse_iterator it;
    for(it=str.rbegin();it!=str.rend();it++)
      rev.push_back(*it);
    if(rev==str)cout<<"it is a palindrome";
    else cout<<"not a palindrome";

    return 0;
}