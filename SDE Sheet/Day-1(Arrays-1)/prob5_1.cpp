//sorting the array with the 0's , 1's , 2's
// optimal approach
#include<bits/stdc++.h>
using namespace std;

 
int sortArray(vector<int> &nums){

    int n = nums.size();
    int low = 0, mid = 0 ,high = n-1;
    while(mid <= high){
        if(nums[mid] == 0){
            swap(nums[low], nums[mid]);
            mid++;
            low++;
        }
        else if(nums[mid] == 1){
            mid++;
        }
        else{
            swap(nums[mid], nums[high]);
            high--;
        }
    }
    
}



int main()
{
    vector<int> nums = {2,0,2,1,1,0,0,0};
    
     sortArray(nums);
     for(auto n : nums) cout<<n<<" ";


return 0;
}