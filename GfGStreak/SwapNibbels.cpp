#include <bits/stdc++.h>
using namespace std;
int swapNibbles(int n)
{
    // code here
    int lastFour = n;
    for (int i = 0; i < 4; i++)
    {
        int j = ~(1 << i);
        lastFour = (lastFour & j);
    }
    for (int i = 0; i < 4; i++)
        lastFour = (lastFour >> 1);
    // cout<<lastFour<<endl;
    int firstFour = n;
    for (int i = 4; i < 8; i++)
    {
        int j = ~(1 << i);
        firstFour = (firstFour & j);
    }
    for (int i = 0; i < 4; i++)
        firstFour = (firstFour << 1);
    int ans = (firstFour | lastFour);
    return ans;
}
int main()
{
    cout << swapNibbles(100) << endl;
    return 0;
}