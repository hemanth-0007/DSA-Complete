#include<bits/stdc++.h>
using namespace std;

bool closeStrings(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        if(n != m) return false;
        vector<int> freq_1(26, 0), freq_2(26, 0);
        for(auto ch : word1) freq_1[ch - 'a']++;
        for(auto ch : word2) freq_2[ch - 'a']++;
        for(int i = 0 ; i < 26 ; i++){
            if( (freq_1[i] != 0 && freq_2[i] == 0) ||
             (freq_1[i] == 0 && freq_2[i] != 0)) return false;
        }
        sort(freq_1.begin(), freq_1.end());
        sort(freq_2.begin(), freq_2.end());
        for(int i = 0 ; i < 26; i++){
            if(freq_1[i] != freq_2[i]) return false;
        }
        return true;
}



int main()
{
    string s1 = "cabbba";
    string s2 = "abbccc";
    cout<<closeStrings(s1,s2);
return 0;
}