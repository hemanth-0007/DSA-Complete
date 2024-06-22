#include <bits/stdc++.h>
using namespace std;

string compressedString(string word)
{
    int n = word.size();
    string comp = "";
    int i = 0;
    while (i < n)
    {
        int j = i;
        char ch = word[i];
        int cnt = 0;
        while (j < n && ch == word[j])
            j++;
        cnt = j - i;
        i = j;
        cout << cnt << " " << ch << endl;
        while (cnt > 0)
        {
            if (cnt >= 9)
            {
                // string temp = '9' + ch;
                comp += '9';
                comp += ch;
                cnt -= 9;
            }
            else
            {
                char temp =  char(cnt + 48);
                cout<<temp<<endl;
                comp += temp;
                comp += ch;
                cnt = 0;
            }
        }
    }
    return comp;
}

int main()
{
    int cnt = 4;
    // cout<<char(cnt+48)<<endl;
    string word = "aaabcccd";
    cout << compressedString(word) << endl;

    return 0;
}