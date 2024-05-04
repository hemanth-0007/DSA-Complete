#include<bits/stdc++.h>
using namespace std;
bool isPalindrome(int num){
    string numStr = to_string(num);
    return numStr == string(numStr.rbegin(), numStr.rend());
}
    
long long minimumCost(vector<int>& nums) {
    int n = nums.size();
    int sum = 0;
    for(int i = 0 ; i < n ; i++) sum += nums[i];
    vector<int> palindromes;
    int OrgAvgNum = (sum/n);
    int avgNum = OrgAvgNum;
    for(int i = 0 ; i < 10 && avgNum > 0; i++){
        if(isPalindrome(avgNum)) palindromes.push_back(avgNum);
        avgNum--;
    }
    avgNum = OrgAvgNum;
    for(int i = 0 ; i < 10; i++){
        if(isPalindrome(avgNum)) palindromes.push_back(avgNum);
        avgNum++;
    }
    int cost = 0;
    int minCost = 1e9;
    cout<<"Size is"<<palindromes.size()<<endl;
    for(auto num : palindromes){
        cost = 0;
        for(auto temp : nums) cost += abs(num - temp);
        cout<<"The palindrome is : "<<num<<" and cost is: "<<cost<<endl;
        minCost = min(minCost, cost);
    }
        return minCost;
}
int main()
{
    vector<int> nums = {4, 2};
    cout<<"Minimum Cost is: "<<minimumCost(nums);
    return 0;
}
    
