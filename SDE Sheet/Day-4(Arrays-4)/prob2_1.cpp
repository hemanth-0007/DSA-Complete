// Largest Subarray with k sum
// optimal solution using hash maps

#include<bits/stdc++.h>
using namespace std;

int longSubArray(vector<int> &nums, int n ){
    // tc - O(nlogn) and sc - O(n)
    map<int, int> mp;
    int sum = 0, maxi = -1e9;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        auto itr = mp.find(sum);
        if(itr != mp.end()){
            int ind = itr->second;
            maxi = max(maxi,i - ind);
        }
        else{
            if(sum != 0){
                mp.insert({sum, i});
            }
            else{
                maxi = max(maxi , i+1);
            }
        }
    }
    
    return maxi;


}

int main()
{
 vector<int> vec =  {1,-1,3,2,-2,-8,1,7,10,23};
 int n = vec.size();
 cout<<longSubArray(vec, n);

return 0;
}