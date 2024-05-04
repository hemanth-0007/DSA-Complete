#include<bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int prod = 1, noOfZeros = 0, withoutZeroProduct = 1;
    int n = nums.size();
    vector<int> prodArray(n, 0);
    int firstIndex = -1;
    for(int i = 0 ; i < n ;i++){
        if( nums[i] == 0){
            noOfZeros++;
            firstIndex = i;
        }
        else withoutZeroProduct *= nums[i];
        prod *= nums[i];
    }
    if(noOfZeros > 1) return prodArray;
    if(noOfZeros == 1){
        prodArray[firstIndex] = withoutZeroProduct;
        return prodArray;
    }
    for(int i = 0 ; i < n ;i++){
            prodArray[i] = (prod/nums[i]);
    }
    return prodArray;
}

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> prodArray(n, 0);
    prodArray[0] = 1;
    for(int i = 1 ; i < n ; i++){
        prodArray[i] = prodArray[i - 1] * nums[i - 1];
    }
    // for right product
    int rightProd = 1;
    for (int i = n-1; i >= 0; i--)
    {
        prodArray[i] = prodArray[i] * rightProd;
        rightProd *= nums[i];
    }
    return prodArray;   
}

int main()
{

return 0;
}