#include <bits/stdc++.h>
#include "AsteroidCollision.h"
using namespace std;
  vector<int> asteroidCollision(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (arr[i] > 0)
                st.push(arr[i]);
            else if (st.empty() && arr[i] <= 0)
                ans.push_back(arr[i]);
            else if (!st.empty() && arr[i] < 0) {
                while (!st.empty() && st.top() < abs(arr[i]))
                    st.pop();
                if (st.empty()){
                    // cout<<"t "<<endl;
                    ans.push_back(arr[i]);
                }
                if (!st.empty() && st.top() == abs(arr[i]))
                    st.pop();
            }
        }
        int m = ans.size();
        while (!st.empty()) {
            // cout<<"tt"<<endl;
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin() + m, ans.end());
        return ans;
    }
int main()
{
    vector<int> asteroids = {8, -8};
    vector<int> ans = asteroidCollision(asteroids);
    for(auto num : ans) cout<<num<<" ";
    return 0;
}