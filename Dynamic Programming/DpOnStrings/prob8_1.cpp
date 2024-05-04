// Edit Distance Problem 
// convert string 1 to string 2 by 3 using methods minimum number of operations
// 1. add
// 2. delete 
// 3. replace ****

#include<bits/stdc++.h>
using namespace std;

int editDistance(int i , int j , string s, string t){
    // string 1 exhausts
    if(i < 0) return j + 1;// j+1 insert operations
    if(j < 0) return i + 1;// i+1 delete operations

    if(s[i] == t[j]) return (editDistance(i-1,j-1,s,t));// if equal no operations req.
    return min( 1 + editDistance(i ,j-1 ,s ,t ), 
                min(1 + editDistance(i-1, j , s, t), 
                1 + editDistance(i-1, j-1 , s, t))); 

}


int main()
{
    string s = "bass" , t = "ass";
    cout<<editDistance(s.size()-1, t.size()-1, s, t);

return 0;
}