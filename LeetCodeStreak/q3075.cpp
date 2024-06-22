#include <bits/stdc++.h>
using namespace std;

long long maximumHappinessSum(vector<int> &happiness, int k)
{
    int n = happiness.size();
    long long ans = 0;
    sort(happiness.begin(), happiness.end(), greater<int>());
    int i = 0;
    while (k--)
    {
       if(happiness[i] > i )ans += happiness[i] - i;
       i++;    
    }
    return ans;
}
int main()
{
    vector<int> happiness = {12,1,42};
    int k = 3;
    cout<<maximumHappinessSum(happiness, k);

    return 0;
}