#include<bits/stdc++.h>
using namespace std;

bool isPair(string s1, string s2){
        reverse(s2.begin(), s2.end());
        if(s1 == s2)
            return true;
        return false;
    }
int maximumNumberOfStringPairs(vector<string>& words) {
    int num = 0;
    for(int i = 0 ; i < words.size(); i++){
        for(int j = i + 1 ; j < words.size(); j++){
            if( isPair(words[i] , words[j]))
                num += 1;     
        }
    }
    return num;
}
int main()
{
    vector<string> words = {"cd","ac", "ca", "dc"};
    cout<<maximumNumberOfStringPairs(words);


return 0;
}