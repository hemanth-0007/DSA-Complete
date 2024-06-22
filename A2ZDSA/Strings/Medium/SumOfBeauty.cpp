#include <bits/stdc++.h>
using namespace std;
int beautySum(string s)
{
    int n = s.size();
    int ans =0; 
    for (int i = 0; i < n; i++)
    {
        vector<int> freq(26 , 0);
        for (int j = i; j < n; j++)
        {
            freq[s[j] - 'a']++;
            int maxi = getMax(freq);
            int mini = getMin(freq);
            cout<<maxi<<' '<<mini<<endl;
            ans += (maxi - mini);
        }
        
    }
    return ans;
}

int getMax(vector<int>& arr){
    int ans = -1e9;
    for(auto num : arr) if(num != 0) ans = max(ans, num);
    return ans;
}
int getMin(vector<int>& arr){
    int ans =  1e9;
    for(auto num : arr) if(num != 0) ans = min(ans, num);
    return ans;
}


int main()
{

    return 0;
}