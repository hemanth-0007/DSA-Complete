#include<bits/stdc++.h>
using namespace std;





class Solution {

    private:
    bool isPossible(vector<int>& arr, int m ,
     int k , int days){
        int noOfB = 0;
        int cnt = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            if(days >= arr[i]) cnt++;
            else{
                noOfB += (cnt/k);
                cnt = 0;
            }
        }
        noOfB += (cnt/k);
        return noOfB >= m;
     }



public:
    int minDays(vector<int>& arr, int m, int k) {
        int n = arr.size();
        if(n < m*k) return -1;
        int mini = INT_MAX, maxi = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            mini = min(mini, arr[i]);
            maxi = max(maxi, arr[i]);
        }
        int low = mini , high = maxi;
        while(low <= high){
            int mid = high - (high - low)/2;
            if(isPossible(arr, m , k , mid)) high = mid -1;
            else low = mid +1;
        }
        return low;
    }
};









int main()
{

return 0;
}