#include<bits/stdc++.h>
using namespace std;

int minimumOperationsToMakeKPeriodic(string word, int k) {
    int n = word.size();
    unordered_map<string,int> mp;
    int maxFreq = 0;
    for(int i = 0; i < n ; i = i+k){
        string t = word.substr(i, k);
        mp[t]++;
        maxFreq = max(maxFreq, mp[t]);
    }
    int noOfWords = n/k;
    int ans = noOfWords - maxFreq;
    return ans;
}
int main()
{
    string word = "ymy";
    int k = 1;
    cout<<minimumOperationsToMakeKPeriodic(word, k);

return 0;
}