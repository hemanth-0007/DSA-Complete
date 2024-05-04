// Next largest element in an circular array 

#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> nums = {3,10,4,2,1,2,6,1,7,2,9};
    int n = nums.size(), ind = n-1;
    int i = ind + 1;
    while(i != ind)
    {
        if(nums[i] >= nums[ind]){
            cout<<"The next greatest num is"<<nums[i]<<endl;
            break;
        }
        i = (i+1)%n;
        // cout<<i<<endl;
    }
    

return 0;
}