#include <bits/stdc++.h>
using namespace std;

int maxProduct(vector<string> &words)
{
    int n = words.size();
    int st = 0;
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        for (auto ch : words[i])
            st = (st | (1 << (ch - 'a')));
        for (int j = i + 1; j < n; j++)
        {
            int ans = words[i].size() * words[j].size();
            for (auto ch : words[j])
            {
                if ((st & (1 << (ch - 'a'))) != 0)
                {
                    ans = 0;
                    break;
                }
            }
            maxi = max(maxi, ans);
        }
        st = (st & 0);
    }
    return maxi;
}

// optimal method is to store all the masks

int maxProduct(vector<string> &words)
{
    int n = words.size();
    vector<int> masks(n, 0);
    for (int i = 0; i < n; i++)
    {
        int mask = 0;
        for (auto ch : words[i])
        {
            mask |= (1 << (ch - 'a'));
            cout<<mask<<endl;
        }
        masks[i] = mask;
    }

    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int ans = words[i].size()*words[j].size();
            if(masks[i]&masks[j] != 0){ 
                cout<<i<<" "<<j<<endl;
                ans = 0;
            }
            maxi = max(maxi , ans);
        }
    }
    return maxi;
}

int main()
{

    return 0;
}