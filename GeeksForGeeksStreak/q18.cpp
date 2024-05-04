#include <bits/stdc++.h>
using namespace std;

vector<int> recamanSequence(int n)
{
    vector<int> result(n, 0);
    int prev = 0;
    set<int> st;
    for (int i = 1; i < n; i++)
    {
        if (prev - i > 0 && st.find(prev - i) == st.end())
        {
            result[i] = prev - i;
            cout<<" an - n "<<result[i]<<endl;
            prev = prev - i;
        }
        else
        {
            result[i] = prev + i;
            cout<<" an + n "<<result[i]<<endl;
            prev = prev + i;
        }
        st.insert(result[i]);
    }
    return result;
}

int main()
{
    int n = 8;
    vector<int> res = recamanSequence(n);
    for (auto num : res)
        cout << num << " ";

    return 0;
}