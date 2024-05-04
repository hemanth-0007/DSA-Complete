#include<bits/stdc++.h>
using namespace std;
int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        priority_queue<int> pq;
        for(auto num : stones) pq.push(num);
        while(!pq.empty()){
            int firstStone = pq.top();
            pq.pop();
            if(pq.empty()) return firstStone;
            int secStone = pq.top();
            pq.pop();
            cout<<firstStone<<" "<<secStone<<endl;
            if(firstStone < secStone){
                secStone = secStone - firstStone;
                pq.push(secStone);
            } 
            else if(firstStone > secStone){
                firstStone =firstStone - secStone;
                pq.push(firstStone);
            }
        }
        return 0;
    }


int main()
{
    vector<int> stones = {2,7,4,1,8,1};
    lastStoneWeight(stones);

return 0;
}