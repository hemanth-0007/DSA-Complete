#include <bits/stdc++.h>
using namespace std;

string frequencySort(string s)
{
    vector<int> freq(256, 0);
    // O(N)
    for (auto ch : s)
        freq[ch]++;
    vector<pair<int, int>> sortFreq;
    for (int i = 0; i < 256; i++)
        if (freq[i] != 0)
            sortFreq.push_back({freq[i], i});

    sort(sortFreq.begin(), sortFreq.end(), greater<pair<int,int>>());

    string ans = "";
    // <= 256
    for (auto it : sortFreq)
    {
        char ch = char(it.second);
        // cout<<ch<<" "<<int(ch)<<" "<<it.second<<endl;
        for (int i = 0; i < it.first; i++)
            ans += ch;
    }
    return ans;
}

int main()
{
    string s = "tree";//"eert"
    cout << frequencySort(s) << endl;

    return 0;
}