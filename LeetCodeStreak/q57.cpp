#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    int n = intervals.size();
    vector<vector<int>> merged;
    int i = 0;
    while(i < n && intervals[i][1] < newInterval[0]){
        merged.push_back(intervals[i]);
        i++;
    }
    while(i < n &&  intervals[i][0] <= newInterval[1]){
        newInterval = {min(newInterval[0], intervals[i][0]), max(newInterval[1], intervals[i][1])};
        i++;
    }
    merged.push_back(newInterval);
    while (i < n )
    {
        merged.push_back(intervals[i]);
        i++;   
    }
    return merged;

}


int main()
{
    vector<vector<int>> intervals = {{1,3},{6,9}};
    vector<int> newInterval = {2,5};
    vector<vector<int>> result = insert(intervals, newInterval);
    for(auto v : result){
        cout << v[0] << " " << v[1] << endl;
    }

return 0;
}