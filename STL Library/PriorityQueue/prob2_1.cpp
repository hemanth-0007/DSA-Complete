#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    vector<int> score = {10};
    int n = score.size();
        vector<string> ans(n);
    
        priority_queue< pair<int,int> > pq;
        for(int i = 0 ; i < n ; i++){
            pq.push({score[i], i});
        }   
        if(n == 1) ans[0] =  "Gold Medal";
        if( n >= 2){
            ans[pq.top().second] = "Gold Medal";
            pq.pop();
            ans[pq.top().second] = "Silver Medal";
            pq.pop();
        }
        if( n >= 3){
            ans[pq.top().second] = "Gold Medal";
            pq.pop();
            ans[pq.top().second] = "Silver Medal";
            pq.pop();
            ans[pq.top().second] = "Bronze Medal";
            pq.pop();
        }
        
        
        int cnt = 4;
         while (!pq.empty())
         {
             ans[pq.top().second] = to_string(cnt);
             cnt++;
             pq.pop();
         }
         
         for(auto str : ans) cout<<str<<" ";
        // return ans;
    

    return 0;
}