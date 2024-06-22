#include<bits/stdc++.h>
using namespace std;

int numRescueBoats(vector<int>& people, int limit) {
    int n = people.size();
    sort(people.begin(), people.end());
    int i = 0,j = n - 1;
    int ans = 0;
    while (i <= j)
    {
            if(people[i] + people[j] <= limit){
                i++;j--;ans++;
            }
            else{
                j--;ans++;
            }
    }
    return ans;      
}

int main()
{
    vector<int> people = {3,2,2,1};
    int limit = 3;
    cout<<numRescueBoats(people, limit);

return 0;
}