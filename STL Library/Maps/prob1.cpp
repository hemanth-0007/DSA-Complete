#include<bits/stdc++.h>
using namespace std;

vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        map<int,int> mp;
        vector<int> resultArray;
        int n = adjacentPairs.size();
        for (int i = 0; i < n; i++)
        {
           for (int j = 0; j < 2; j++)
           {
                // mp[adjacentPairs[i][j]]++;
                if(mp.find(adjacentPairs[i][j]) == mp.end()){

                    mp[adjacentPairs[i][j]] = 1;
                }
                else{

                    mp[adjacentPairs[i][j]]++;
                }
           }
           
        }
        
        
        return resultArray;
}

int main()
{
    vector<vector<int>> adjacentPairs = {{4,-2},{1,4},{-3,1}};
    vector<int> resultArray = restoreArray(adjacentPairs);
    for(auto i : resultArray)
        cout<<i<<" ";
    cout<<endl;

return 0;
}