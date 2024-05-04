//  finding the next smallest palindrome
// brute force method

#include<bits/stdc++.h>
using namespace std;

int isPalindrome(int n ){
    string s = to_string(n);
    int l = s.length();
    int mid = (l-1)/2;
    for (int i = 0; i <= mid; i++)
    {
        if(s[i] != s[l-1-i])
            return 0;
    }
    return 1;
}

// time complexity O(N*N) 
int main()
{
int num = 1220;
for (int i = num;; i++)
{
   if(isPalindrome(i)){
    cout<<i<<endl;
    break;
   }
}


return 0;
}