#include<bits/stdc++.h>
using namespace std;


bool isBeautiful(vector<int>& arr){
    bool ans = true;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if(arr[i]%(i+1) != 0 && (i+1)%arr[i] != 0){
            ans = false;
            break;
        }
    }
    return ans;
}



int helper(int ind , vector<int>& arr){
    if(ind == arr.size()){
        if(isBeautiful(arr)){
            for(auto num : arr) cout<<num<<" ";
            cout<<endl;
            return 1;
        }
        else return 0;        
    }
    int ans  = 0;
    for (int i = ind; i < arr.size(); i++)
    {
        swap(arr[ind], arr[i]);
        ans +=   helper(ind + 1 , arr);
        swap(arr[i], arr[ind]);
    }
    return ans;
}


int print_per(int n){
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        arr[i] = i+1;
    return helper(0 , arr);
}



int main()
{
    
    cout<<print_per(2);

return 0;
}