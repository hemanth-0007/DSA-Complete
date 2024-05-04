// Longest subsequence in a string 
#include<bits/stdc++.h>
using namespace std;

int longSubSeq(int ind1 , int ind2 , string s1, string s2){

    if(ind1 < 0 || ind2 < 0) return 0;
    if(s1[ind1] == s2[ind2])
        return (1+longSubSeq(ind1-1, ind2-1, s1, s2));

    return max(longSubSeq(ind1-1, ind2, s1, s2), longSubSeq(ind1, ind2-1, s1, s2));

}


int main()
{
    string s1 = "abcdef";
    string s2 = "abxdyf";
    cout<<longSubSeq(s1.size()-1, s2.size()-1, s1, s2);

return 0;
}