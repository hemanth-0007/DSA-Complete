// Maximum number of meetings that can be performed in a given 
//  the start time and end time 


#include<bits/stdc++.h>
using namespace std;

int maxMeetings(vector<int> &start, vector<int> &end, int n){
    vector<pair<int,int>> ds;
    // first one int is end time
    // second literal is start time
    for (int i = 0; i < n; i++)
        ds.push_back({end[i], start[i]});
   
    sort(ds.begin(), ds.end());
    int ans = 1, limit = ds[0].first;
    for (int i = 1; i < n; i++)
    {
        if(ds[i].second > limit){
            limit = ds[i].first;
            ans += 1;
        }
    }
    return ans;
    
}

int main()
{
    vector<int> start = {1,3,0,5,8,5}, end = {2,4,5,7,9,9};
    int n =  start.size();
    cout<<maxMeetings(start, end , n);
return 0;
}