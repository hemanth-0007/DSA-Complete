// maximum number of meetings that can held 
// given starting time and ending time

#include<bits/stdc++.h>
using namespace std;

vector<int> maxMeetings(vector<int>& start, vector<int>& end){
    int n = start.size();
    vector<int> res;
    vector<vector<int>> meetings;
    for(int i =0 ; i < n ; i++) meetings.push_back({end[i], start[i], i});
    sort(meetings.begin(), meetings.end());
    // for(int i =0 ; i < n ; i++)
    //     cout<<meetings[i][0]<<" "<<meetings[i][1]<<" "<<meetings[i][2]<<endl;
    int finishTime = meetings[0][0], max_meetings = 1;
    res.push_back(meetings[0][2]+1);
    for(int i = 1 ; i < n ; i++){
        if(meetings[i][1] > finishTime ){
            max_meetings++;
            res.push_back(meetings[i][2]+1);
            finishTime = meetings[i][0];
        } 
    }
     
    return res;
}




int main()
{
vector<int> S = {1,3,0,5,8,5};
vector<int> F = {2,4,6,7,9,9};
vector<int> R = maxMeetings(S,F);
for( auto num : R) cout<<num<<" ";

return 0;
}