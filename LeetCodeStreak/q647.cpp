#include<bits/stdc++.h>
using namespace std;
// O(N^2)
int palindromeCount(string s, int left, int right){
    int ans = 0;
    while(left >= 0 && right < s.size()){
        if(s[left] == s[right]){
             ++ans;
            cout<<s.substr(left, right)<<endl;
        }
        else break;
        --left;
        ++right;
    }
    return ans;
}


int countSubstrings(string s) {
    int n = s.size();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        // for even length palindrome
        ans += palindromeCount(s, i, i+1);
        // for odd length
        ans += palindromeCount(s, i, i);
    }
    return ans;
}


bool isPalindrome(string s , int i , int j){
    int n = s.size(), left = i , right = j ;
    for (int ind = i; ind <= j; ind++)
    {
        if(s[ind] != s[j - ind]) return false;
    }
    return true;
}



int countSubstringBrute(string s){
    int n = s.size(), ans = 0;
    for (int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++){
            if(isPalindrome(s, i, j)) ans++;
        }
    } 
    return ans;
}


int main()
{
    // string s = "aba";
    string s = "fdsklf";
    cout << countSubstrings(s) << endl;
    cout << countSubstringBrute(s) << endl;
    // cout<<isPalindrome(s,0, 0);
return 0;
}