#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
 int n= intervals.size();
 sort(intervals.begin(), intervals.end());
 vector<vector<int>> res;
 for (int i = 0; i < n; i++)
 {
    int start = intervals[i][0];
    int end = intervals[i][1];
    while( i < n && end >= intervals[i][0]){
        end = max(end , intervals[i][1]);
        i++;
    }
    i--;
    end = max(end,intervals[i][1]);
    res.push_back({start,end});
 }
    return res;
}


int main()
{

return 0;
}