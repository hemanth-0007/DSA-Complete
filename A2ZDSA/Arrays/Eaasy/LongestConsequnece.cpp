#include <bits/stdc++.h>

using namespace std;
int longestConsecutive(vector<int> &arr)
{
    int n = arr.size();
    unordered_set<int> st;
    for (int i = 0; i < n; i++)
        st.insert(arr[i]);
    
    int longest = -1e9;
    for(auto it : st){
        if(st.find(it - 1) == st.end()){
            int cnt = 1;
            int x = it;
            while (st.find(x + 1) != st.end())
            {
                x += 1;
                cnt++;
            }  
            longest = max(longest, cnt);        
        }
    }
    return longest;
}

int main()
{
    vector<int> nums = {0,3,7,2,5,8,4,6,0,1};
    cout<<longestConsecutive(nums);
    return 0;
}