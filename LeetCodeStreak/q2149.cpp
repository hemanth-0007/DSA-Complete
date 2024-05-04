#include<bits/stdc++.h>
using namespace std;

vector<int> rearrangeArray(vector<int>& nums) {
    int negInd = 0, posInd = 0;
    if(nums[0] < 0){
        negInd = 0;
        int i = 0;
        while(nums[i++] > 0) ++posInd;
    }       
    else{
        posInd = 0;
        int i = 0;
        while(nums[i++] < 0) ++negInd;
    }
    cout<<posInd<<" "<<negInd<<endl;
    return {};
}

int main()
{
    vector<int> nums = {-3,1,-2,-5,2,-4};
    vector<int> result =  rearrangeArray(nums);

return 0;
}