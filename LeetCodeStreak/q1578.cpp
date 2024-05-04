#include<bits/stdc++.h>
using namespace std;

int minCost(string colors, vector<int>& neededTime) {
 int n = colors.size();
 int i = 0, max_cost = 0, min_cost = 0;
 while (i < n-1)
 {
    int cost = 0, max_cost = 0;
    if( colors[i] == colors[i+1]){
        cost += neededTime[i];
        max_cost = max(neededTime[i], max_cost);
    }
    while(i < n && colors[i] == colors[i+1]){
        cout<<"In 2 nd loop"<<endl;
        cost += neededTime[i+1];
        max_cost = max(neededTime[i+1], max_cost);
        cout<<"\t"<<colors[i]<<" "<<i<<" "<<cost<<" "<<max_cost<<endl;
        i++;
    }
    min_cost += cost - max_cost;
    cout<<colors[i]<<" "<<i<<" "<<min_cost<<" "<<cost<<" "<<max_cost<<endl;
    i++;
 }
 return min_cost;
        
}

int main()
{
    string colors = "abaac";
    vector<int> neededTime = {1,2,3,4,5};
    cout<<minCost(colors, neededTime);
return 0;
}