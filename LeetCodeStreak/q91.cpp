#include <bits/stdc++.h>
using namespace std;
// A message containing letters from A-Z can be encoded into numbers using the following mapping:

// 'A' -> "1"
// 'B' -> "2"
// ...
// 'Z' -> "26"

// Given a string s containing only digits, return the number of ways to decode it.

int numDecodingsTopDown(string s, int index, vector<int> &memo)
{
    if (index == s.length())
        return 1;

    if (s[index] == '0')
        return 0;

    if (memo[index] != -1)
        return memo[index];

    int ways = numDecodingsTopDown(s, index + 1, memo);

    if (index + 1 < s.length() && (s[index] == '1' || (s[index] == '2' && s[index + 1] <= '6')))
    {
        ways += numDecodingsTopDown(s, index + 2, memo);
    }

    return memo[index] = ways;
}

int numDecodingsDownTop(string s, int ind, vector<int> &memo)
{
    if (ind == s.size())
        return 1;
    if (s[ind] == '0')
        return 0;
    if (memo[ind] != -1)
        return memo[ind];
    int singleChar = 0, doubleChar = 0;
    singleChar = numDecodingsTopDown(s, ind + 1, memo);
    if (ind + 1 < s.length() && (s[ind] == '1' || (s[ind] == '2' && s[ind + 1] <= '6')))
        doubleChar = numDecodingsTopDown(s, ind + 2, memo);

    return memo[ind] = singleChar + doubleChar;
}
int numDecodings(string s)
{
    vector<int> memo(s.length(), -1);
    // return numDecodingsTopDown(s, 0, memo);
    return numDecodingsDownTop(s, 0, memo);
}
int numDecodingsMod(string s)
{
    vector<int> memo(s.length(), -1);
    // return numDecodingsTopDown(s, 0, memo);
    return numDecodingsTopDown(s, 0, memo);
}

int main()
{
    string s = "226";
    cout << numDecodings(s) << endl;
    cout << numDecodingsMod(s);

    return 0;
}