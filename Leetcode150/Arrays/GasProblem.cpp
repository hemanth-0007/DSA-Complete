#include<bits/stdc++.h>
using namespace std;

int startIndex(vector<int>& gas, vector<int>& cost){
    int n = gas.size();
    for (int i = 0; i < n ; i++)
    {
        // iterate circularly to the same index i
        int j = i ;
        int fuel = gas[i];
        cout<<"Initial fuel is: "<<fuel<<endl;
        while (true)
        {
            fuel += (gas[(j+1)%n] - cost[j]);
            cout<<"     "<<fuel<<endl;
            if(fuel <= 0) break;
            j = (j+1)%n;
            if(i == j) return i;
            cout<<"     j value is: "<<j<<endl;
        }
    }
    return -1;
}


int main()
{
    vector<int> gas = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};
    cout<<startIndex(gas, cost);

return 0;
}