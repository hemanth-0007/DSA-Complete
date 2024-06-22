#include <bits/stdc++.h>
using namespace std;
int mod(int x)
{
    return x < 0 ? (-1) * x : x;
}

 int maxPointsInsideSquare(vector<vector<int>> &points, string s)
{
    int n = points.size();
    int sideLen = -1;
    int deadLen = 1e9;
    unordered_map<char ,int> mp;
    for (int i = 0; i < n; i++)
    {
        int x = abs(points[i][0]);
        int y = abs(points[i][1]);
        if(mp.find(s[i]) != mp.end()){
            // duplicate encountered
            if(max(x, y ) == mp[s[i]]){
                sideLen = sideLen -1;
                deadLen = sideLen;
                continue;
            }
           sideLen = min(mp[s[i]], max(x, y));
           mp[s[i]] = sideLen;
           deadLen = min(deadLen, max(x, y) - 1 );
           cout<<sideLen<<" "<<deadLen<<endl;
           continue;
        }
        else{
            if(deadLen == -1) sideLen = max(x, y);
            else{
                if(max(x, y) <= deadLen){
                    sideLen = max(x, y);
                }
            }
        }
        mp[s[i]] = max(x, y);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int x = abs(points[i][0]);
        int y = abs(points[i][1]);
        if (x <= sideLen && y <= sideLen)
            ans++;
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