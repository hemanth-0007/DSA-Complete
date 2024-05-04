// Maximize the profit with doing eacch job in unit time
//  and only one job at a time and also given the deadlines
#include<bits/stdc++.h>
using namespace std;


int maxProfit(vector<pair<int,int>> &jobs,int n){

    sort(jobs.begin(), jobs.end(), greater<pair<int,int>>());
    int timeStamp = 0, noOfJobs = 0;
    int i = 0,maxProfit = 0;
    
    while (i < n)
    {
        if(timeStamp < jobs[i].second){
            maxProfit += jobs[i].first;
            timeStamp++;
            noOfJobs++;
        }
            i++;
    }
    
    return maxProfit;
   
}
int main()
{

    vector<pair<int,int>> jobs = {
        {20,4},{10,1}, {40,1},{30,1}
    };
     
    int n = jobs.size();
    cout<<maxProfit(jobs,n);

return 0;
}