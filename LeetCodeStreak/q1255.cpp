#include <bits/stdc++.h>
using namespace std;

int getScore(const string &s, unordered_map<char, int> &mp, vector<int> &score)
{
    int cnt = 0;
    for (auto ch : s)
    {
        mp[ch]--;
        cnt += score[ch - 'a'];
    }
    return cnt;
}

bool isPossible(const string &s, unordered_map<char, int> &mp, vector<int> &score)
{
    unordered_map<char,int> temp;
    for(auto ch : s) temp[ch]++;
    for(auto it : temp){
        if(mp[it.first] >= it.second) return false;
    }
    return true;
}

int helper(int ind, vector<string> &words, unordered_map<char, int> &mp, vector<int> &score)
{
    if (ind == words.size())
            return 0;
    // code
    int include = -1e9;
    if (isPossible(words[ind], mp, score)){
        include = getScore(words[ind], mp, score) + helper(ind + 1, words, mp, score);
        for(auto ch : words[ind]) mp[ch]++;
    }

    int notInclude = 0 + helper(ind + 1, words, mp, score);
    return max(include, notInclude);
}

int maxScoreWords(vector<string> &words, vector<char> &letters, vector<int> &score)
{
    int n = words.size();
    unordered_map<char, int> mp;
    for (auto ch : letters)
        mp[ch]++;
    return helper(0, words, mp, score);
}

int main()
{
     vector<string> words = {"dog","cat","dad","good"};
    vector<char> letters = {'a','a','c','d','d','d','g','o','o'};
    vector<int> score = {1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0};
    cout<<maxScoreWords(words, letters, score);

    return 0;
}