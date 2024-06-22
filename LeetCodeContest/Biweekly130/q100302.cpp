#include <bits/stdc++.h>
using namespace std;
int mod(int x)
{
    return x < 0 ? (-1) * x : x;
}

 int maxPointsInsideSquare(vector<vector<int>> &points, string s)
{
    int n = points.size();
    vector<pair<int, char>> pointLabel;
    for (int i = 0; i < n; i++)
        pointLabel.push_back({max(abs(points[i][0]) , abs(points[i][1])), s[i]});
    sort(pointLabel.begin(), pointLabel.end());
    // for (int i = 0; i < n; i++) cout<<pointLabel[i].first<<" "<<pointLabel[i].second<<endl;
    int ans = 0, maxSideLen = -1;
    unordered_set<char> st;
    for (int i = 0; i < n; i++) {
        int sideLen = pointLabel[i].first;
        char ch = pointLabel[i].second;
        if(st.find(ch) != st.end()){
            if(sideLen == maxSideLen) return ans -1;
            return ans;
        }
        else{
            maxSideLen = sideLen;
            ans++;
        }
        st.insert(ch);
    }
    return ans;   
}
int main()
{
    // vector<vector<int>> points = {{2, 2}, {-1, -2}, {-4, 4}, {-3, 1}, {3, -3}};
    // string s = "abdca";
    vector<vector<int>> points = {{16,32},{27,3},{23,-14},{-32,-16},{-3,26},{-14,33}};
    string s = "aaabfc";
    cout << maxPointsInsideSquare(points, s);
    return 0;
}