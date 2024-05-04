// Finding the next permutation in for the given array
// Optimal approach using the break point method

 
#include<bits/stdc++.h>
using namespace std;
 
vector<int> get_next_permutation(vector<int> &nums, int n){

    vector<int> ans(nums);
    int ind = -1 ;
    for (int i = n-2; i >= 0; i--)
    {
        if(ans[i] < ans[i+1]){
            ind = i;
            break;
        }
    }

    if(ind == -1){
        reverse(ans.begin(), ans.end());
        return ans;
    }

    //step-2 ( get the swaping done with the smaller element greater than arr[ind] element)
    for(int i = n-1 ; i > ind ; i++){
        if(ans[i] > ans[ind]){
            swap(ans[i], ans[ind]);
            break;
        }
    }
    //step-3 : reverse the ind + 1 to end part
    reverse(ans.begin() + ind + 1, ans.end());
    return ans;
}
  
int main()
{

    vector<int> nums = {2,1,4,3};
    int n = nums.size();
    vector<int> ans = get_next_permutation(nums , n );
    for(auto num : ans)
        cout<<num<<" ";
    
    
        

    return 0;
}