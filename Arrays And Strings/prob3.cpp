// Leet Code Contest Question
#include<bits/stdc++.h>
using namespace std;

string join(string s1, string s2){
    int n = s1.length();
    int m = s2.length();
    if(s1[n-1] == s2[0]){
        return s1.substr(0, n-1) + s2;
    }
    if(s1[0] == s2[m-1]){
        return s2.substr(0, m-1) + s1;
    }
    return s1 + s2;
}
 
int minimizeConcatenatedLength(vector<string>& words) {
        string s;
        int n = words.size();
        for(int i =0 ; i<n ; i++){
            if(i == 0 ){
                s += join(words[i], words[i+1]);
                continue;
            }
            if(i == 1) continue;
            s = join(s, words[i]);
          
        }

     return s.size();
     
}
int main()
{
    vector<string> words = {"aa","ab","bc"};
    cout<<minimizeConcatenatedLength(words);


return 0;
}