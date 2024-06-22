#include<bits/stdc++.h>
using namespace std;

long long solve(vector<int>& arr) {
     long long int n = arr.size();
     long long ans = 0;
     long long sum = 0;
     for (int i = 0; i < n-1; i++)
     {
         sum += arr[i];
         ans += sum;
     }
    return ans/n;
}

int main()
{

return 0;
}