#include<bits/stdc++.h>
using namespace std;
//palindrome or not 
int isPalindrome(int i, string s){
    int l = s.length();
    // exit condition 
    if(i >= l/2){
        return 1;
    }

// this is the loop break condition
  if( s[i] != s[l-i-1])
    return 0;


// loop increment condition 
    return isPalindrome(i+1,s);

}
int main()
{
    string s = "111111102";
    cout<<isPalindrome(0,s);

return 0;
}