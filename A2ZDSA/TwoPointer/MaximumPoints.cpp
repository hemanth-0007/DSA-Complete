#include<bits/stdc++.h>
using namespace std;

int maxScore(vector<int>& arr, int k) {
    int n = arr.size();
    int total_score = 0;
    for(auto num : arr) total_score += num;
    cout<<total_score<<endl;
    int sum = 0;
    for(int i = 0 ; i < (n-k) ; i++) sum += arr[i];
    int min_sum = sum;
    for(int i = (n-k); i < n ; i++){
        sum -= arr[i-(n-k)];
        sum += arr[i];
        min_sum = min(min_sum, sum);
    }   
    cout<<min_sum<<endl;
    return total_score - min_sum; 
}



int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int k;
    cin>>k;
    cout<<maxScore(arr, k);
    

return 0;
}