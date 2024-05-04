#include<bits/stdc++.h>
using namespace std;


bool compareSecondIndDesc(const vector<int>& a, const vector<int>& b){
    if(a[1] != b[1])
        return a[1] > b[1];
    return a[0] < b[0];
}

string frequencySort(string s) {
    vector<vector<int>> freq(26, vector<int>(2, 0));
    string temp = "";
    for (int i = 0; i < 26; i++) freq[i][0] = i;
    for(auto ch : s){
        int charInd = ch-'a';
        if(charInd < 26) freq[charInd][1] += 1;
    }
    sort(freq.begin(), freq.end(), compareSecondIndDesc);
    for(auto v : freq){
        for(int i = 0; i < v[1]; i++) temp += (char)(v[0] + 'a');
    }
    for(auto v : freq){
        cout<<v[0]<<" "<<v[1]<<endl;
    }
    return temp;
}


string frequencySortOpt(string s){
    map<char ,int> mp;
    multimap<int , char> mmp;
    for(auto ch : s) mp[ch]++;
    for(auto it : mp) mmp.insert({it.second, it.first});

    for(auto it : mmp){
        cout<<it.first<<" "<<it.second<<endl;
    }
    string result = "";
    for(auto it = mmp.rbegin(); it != mmp.rend(); ++it){
        result += string(it->first, it->second);
    }
    return result;
}


int main()
{   
    // string s = "aaaaazzz";
    string s = "tree";
    // cout<<frequencySort(s);
    cout<<frequencySortOpt(s);

return 0;
}