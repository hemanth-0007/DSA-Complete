#include<bits/stdc++.h>
using namespace std;

bool modularExpo(vector<int>& nums, int target){
    int a = nums[0], b = nums[1], c = nums[2], m = nums[3];
    int result = 1;
    for(int i = 0; i < b ; i++){
        result = result*(a%10);
        result = result%10;
    }
    cout<<result<<endl;
    int temp = result;
    result = 1;
    for(int i = 0 ; i < c ; i++){
        result = result*(temp%m);
        result = result%m;
    }
    cout<<result<<endl;
    return result == target;
}

int main()
{

    vector<vector<int>> nums = {{2,3,3,10},{3,3,3,1},{6,1,1,4}};
    int target = 2;
    cout<< modularExpo(nums[0], target);

return 0;
}