// Minimum number of platforms required for a station 
// through out the day given arrival and departure times
#include<bits/stdc++.h>
using namespace std;


int minPlatforms(vector<int> &arr,vector<int> &dep, int n){

    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    int i = 1 , j = 0;
    int ans = 1, res = 1;
    while (i<n && j<n)
    {
        if(arr[i] <= dep[j]){
            res += 1;
            i++;
        }
        else{
            res -= 1;
            j++;
        }
        ans = max(ans, res);
    }
    
    return ans;
}
int main()
{
    vector<int> arr = {900,945,955,1100,1500,1800};
    vector<int> dep = {920,1130,1150,1200,1900,2000};
    int n = arr.size();
    cout<<minPlatforms(arr,dep,n);

return 0;
}