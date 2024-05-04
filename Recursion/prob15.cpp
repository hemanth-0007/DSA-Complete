// Printing all the permutations of a string or a array
// low space complexity
#include <bits/stdc++.h>
using namespace std;
//  Time Complexity: O(n! * N)
//  Space Complexity: O(1) 
// Auxillary Space: O(N) Recursive Stack Space
void print(vector<int> nums)
{
    for (auto n : nums)
    {
        cout << n << " ";
    }
}

void getPermutations(int pt, vector<int> &nums, int n)
{
    if (pt == n)
    {
        print(nums);
        cout << endl;
        return;
    }
    for (int i = pt; i < n; i++)
    {
        swap(nums[pt], nums[i]);
        getPermutations(pt + 1, nums, n);
        swap(nums[pt], nums[i]);
    }
}

int main()
{

    vector<int> nums = {1, 2, 3};
    int n = nums.size();
    getPermutations(0, nums, n);

    return 0;
}