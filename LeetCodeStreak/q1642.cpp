#include<bits/stdc++.h>
using namespace std;

int helper(int ind, vector<int>& heights, int bricks, int ladders){
    // base case
    if(ind >= heights.size()-1) return -1e8;
    // main code
    int ans;
    if(heights[ind] >= heights[ind+1]){
        ans = 1 + helper(ind + 1, heights, bricks, ladders);
    }
    else{
        int diff = heights[ind+1] - heights[ind];
        if(diff <= bricks) ans += 1 + helper(ind + 1, heights, bricks - diff, ladders);
        if(ladders > 0) ans += 1 + helper(ind + 1, heights, bricks, ladders -1);
    }
    return ans;
}


int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
    return helper(0 ,heights, bricks, ladders);        
}



   /* Intuition: We will use the ladders where the difference is the largest,
       and we will use the bricks where the difference is the smallest */
    // Time complexity: O(nlogn)
    // Space complexity: O(min(n,l)) --> where l is the number of ladders, n is the size of the heights
int furthestBuildingOp(vector<int>& heights, int bricks, int ladders) {
    priority_queue<int> pq;
    int n = heights.size();
    // We will use the bricks to climb when the bricks are not enough to climb, we will use the ladders
    // and we pop out the largest difference from the priority queue and use the ladders where the difference is the largest
    
    for (int i = 0; i < n-1; i++)
    {
        int diff = heights[i+1] - heights[i];
        if(diff > 0){
            bricks -= diff;
            pq.push(diff);

            if(bricks < 0){
                bricks += pq.top();
                pq.pop();
                ladders--;
            }
            // If there are no ladders left, we can't climb anymore
            // so we return the current index
            if(ladders < 0){
                return i;
            }
            
        }
    }
    return n-1;
}

int main()
{
    vector<int> heights = {4,2,7,6,9,14,12};
    int bricks = 5;
    int ladders = 1;
    // cout<<furthestBuilding(heights, bricks, ladders)<<endl;
    cout<<furthestBuildingOp(heights, bricks, ladders)<<endl;

return 0;
}